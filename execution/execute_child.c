/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_child.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 14:55:34 by felixgreiff       #+#    #+#             */
/*   Updated: 2026/02/26 11:09:03 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "execution.h"

void	execute_child(t_minishell *shell, t_args *cmd)
{
	char	**argv;
	char	*path;

	write(2, "child: applying redirs\n", 23);
	if (cmd->redirs)
		apply_redirection(cmd->redirs);
	write(2, "child: building argv\n", 21);
	argv = args_to_argv(cmd->args);
	write(2, "child: checking builtin\n", 24);
	if (is_builtin(cmd->args->value))
	{
		shell->last_exit_status = execute_builtin(shell, argv);
		array_free(argv);
		exit(shell->last_exit_status);
	}
	write(2, "child: finding path\n", 20);
	path = parse_paths(shell, cmd);
	if (!path)
	{
		ft_putstr_fd("minishell: command not found\n", 2);
		exit(127);
	}
	write(2, "child: execve\n", 14);
	execve(path, argv, shell->env);
	perror("minishell: child");
	array_free(argv);
	free(path);
	exit(127); //correct this way or call exit function
}
