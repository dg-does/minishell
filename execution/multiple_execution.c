/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_execution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:17:21 by felixgreiff       #+#    #+#             */
/*   Updated: 2026/02/26 12:01:45 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "execution.h"

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
	argv = args_to_argv(cmd);
	if (is_builtin(argv[0]))
		exit(execute_builtin(shell, argv));
	path = parse_paths(shell, cmd);
	execve(path, argv, shell->env);
	perror("minishell: execve");
	exit(127);
}