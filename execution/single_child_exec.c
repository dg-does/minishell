/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_child_exec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 09:05:07 by fgreiff           #+#    #+#             */
/*   Updated: 2026/03/12 13:22:32 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "execution.h"

void	execute_child(t_minishell *shell, t_args *cmd)
{
	char	**argv;
	char	*path;

	if (cmd->redirs && apply_redirection(cmd->redirs))
		child_exit(shell, 1);
	argv = args_to_argv(cmd->args);
	if (is_builtin(cmd->args->value))
	{
		shell->last_exit_status = execute_builtin(shell, argv);
		child_exit(shell, shell->last_exit_status);
	}
	path = parse_paths(shell, cmd);
	if (!path)
	{
		check_path_erorr(shell, argv[0]);
		child_exit(shell, 127);
	}
	execve(path, argv, shell->env);
	perror("minishell: child");
	child_exit(shell, 127);
}
