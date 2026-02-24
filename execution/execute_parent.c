/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_parent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 14:55:28 by felixgreiff       #+#    #+#             */
/*   Updated: 2026/02/24 15:51:20 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "built_in.h"

//misses redirections and changing of fds not finished yet!!!!!
int	execute_builtin(t_minishell *shell, char **argv)
{
	if (ft_strcmp(argv[0], "cd") == 0)
		return (ft_cd(argv));
	if (ft_strcmp(argv[0], "exit") == 0)
		ft_exit(shell);
	if (ft_strcmp(argv[0], "export") == 0)
		return (ft_export(shell, argv[1]));
	if (ft_strcmp(argv[0], "unset") == 0)
		return (ft_unset(shell, argv[1]));
	return (1);
}

void	execute_parent(t_minishell *shell, t_args *cmd, int *last_exit_status)
{
	int		tmp_stdin;
	int		tmp_stdout;
	char	**argv;

	tmp_stdin = dup(STDIN_FILENO);
	tmp_stdout = dup(STDOUT_FILENO);
	if (cmd->redirs)
		apply_redirection(cmd->redirs);
	argv = args_to_argv(cmd->args);
	*last_exit_status = execute_builtin(shell, argv);
	dup2(tmp_stdin, STDIN_FILENO);
	dup2(tmp_stdout, STDOUT_FILENO);
	close(tmp_stdin);
	close(tmp_stdout);
}