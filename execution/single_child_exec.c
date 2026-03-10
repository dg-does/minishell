/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_child_exec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 09:05:07 by fgreiff           #+#    #+#             */
/*   Updated: 2026/03/10 10:18:16 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "execution.h"

void	execute_child(t_minishell *shell, t_args *cmd)
{
	char	**argv;
	char	*path;

	if (cmd->redirs && apply_redirection(cmd->redirs))
		exit (1);
	argv = args_to_argv(cmd->args);
	if (is_builtin(cmd->args->value))
	{
		shell->last_exit_status = execute_builtin(shell, argv);
		array_free(argv);
		exit(shell->last_exit_status);
	}
	path = parse_paths(shell, cmd);
	if (!path)
		check_path_erorr(argv[0]);
	execve(path, argv, shell->env);
	perror("minishell: child");
	array_free(argv);
	free(path);
}
