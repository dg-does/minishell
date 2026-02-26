/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_execution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:17:21 by felixgreiff       #+#    #+#             */
/*   Updated: 2026/02/26 16:29:45 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "execution.h"
#include "minishell.h"

static void	child_process(t_minishell *shell, t_args *cmd,
	int **pipes, int i, int cmd_count)
{
	char	**argv;
	char	*path;

	if (i == 0)
		dup2(pipes[0][1], STDOUT_FILENO);
	else if (i == cmd_count - 1)
		dup2(pipes[i - 1][0], STDIN_FILENO);
	else
	{
		dup2(pipes[i - 1][0], STDIN_FILENO);
		dup2(pipes[i][1], STDOUT_FILENO);
	}
	apply_redirection(cmd->redirs);
	close_all_pipes(pipes, cmd_count - 1);
	argv = args_to_argv(cmd->args);
	if (is_builtin(argv[0]))
		exit(execute_builtin(shell, argv));
	path = parse_paths(shell, cmd);
	execve(path, argv, shell->env);
	perror("minishell: execve");
	exit(127);
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
	pipes = malloc(sizeof(int *) * count);
	if (!pipes)
		return (NULL);
	i = 0;
	while (i < count)
	{
		pipes[i] = malloc(sizeof(int) * 2);
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

void	execute_multiple(t_minishell *shell, t_args *cmds, int cmd_count)
{
	int		i;
	pid_t	*pids;
	int		**pipes;
	t_args	*cur;

	pipes = create_pipes(cmd_count - 1);
	pids = malloc(sizeof(pid_t) * cmd_count);
	cur = cmds;
	i = 0;
	while (cur)
	{
		pids[i] = fork();
		if (pids[i] == -1)
			perror("minishell: fork");
		if (pids[i] == 0)
			child_process(shell, cur, pipes, i, cmd_count);
		cur = cur->next;
		i++;
	}
	close_all_pipes(pipes, cmd_count - 1);
	collect_status(shell, pids, cmd_count);
}
