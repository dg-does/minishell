/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_execution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:17:21 by felixgreiff       #+#    #+#             */
/*   Updated: 2026/03/10 15:11:16 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "execution.h"
#include "minishell.h"

static void	exec_cmd(t_minishell *shell, t_args *cmds, char **argv)
{
	char	*path;

	if (!argv || !argv[0])
		exit(127);
	if (is_builtin(argv[0]))
		exit(execute_builtin(shell, argv));
	path = parse_paths(shell, cmds);
	if (!path)
		check_path_erorr(shell, argv[0]);
	execve(path, argv, shell->env);
	perror("minishell: execve");
	child_exit(shell, 127);
}

static void	child_process(t_minishell *shell, t_args *cmds,
	int **pipes, int i)
{
	int		cmd_count;

	cmd_count = shell->cmd_count;
	if (i == 0)
		dup2(pipes[0][1], STDOUT_FILENO);
	else if (i == cmd_count - 1)
		dup2(pipes[i - 1][0], STDIN_FILENO);
	else
	{
		dup2(pipes[i - 1][0], STDIN_FILENO);
		dup2(pipes[i][1], STDOUT_FILENO);
	}
	if (apply_redirection(cmds->redirs))
		exit(1);
	close_all_pipes(pipes, cmd_count - 1);
	exec_cmd(shell, cmds, args_to_argv(cmds->args));
}

static void	free_pipes(int **pipes, int count)
{
	while (count > 0)
	{
		count--;
		free(pipes[count]);
	}
	free(pipes);
	return ;
}

int	**create_pipes(int count)
{
	int	**pipes;
	int	i;

	if (count <= 0)
		return (NULL);
	pipes = gc_malloc(sizeof(int *) * count);
	if (!pipes)
		return (NULL);
	i = 0;
	while (i < count)
	{
		pipes[i] = gc_malloc(sizeof(int) * 2);
		if (!pipes[i])
		{
			free_pipes(pipes, i);
			return (NULL);
		}
		if (pipe(pipes[i]) == -1)
		{
			perror("minishell: pipe");
			return (NULL);
		}
		i++;
	}
	return (pipes);
}

void	execute_multiple(t_minishell *shell, t_args *cmds)
{
	int		i;
	pid_t	*pids;
	int		**pipes;
	t_args	*cur;

	pipes = create_pipes(shell->cmd_count - 1);
	pids = gc_malloc(sizeof(pid_t) * shell->cmd_count);
	cur = cmds;
	i = 0;
	while (cur)
	{
		pids[i] = fork();
		if (pids[i] == -1)
			perror("minishell: fork");
		if (pids[i] == 0)
			child_process(shell, cur, pipes, i);
		cur = cur->next;
		i++;
	}
	close_all_pipes(pipes, shell->cmd_count - 1);
	collect_status(shell, pids, shell->cmd_count);
}
