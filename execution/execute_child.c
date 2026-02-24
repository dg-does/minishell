/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_child.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 14:55:34 by felixgreiff       #+#    #+#             */
/*   Updated: 2026/02/24 15:04:57 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "execution.h"

void	execute_child(t_minishell *shell, t_args *cmd)
{
	char	**argv;
	char	*path;

	if (cmd->redirs)
		apply_redirection(cmd->redirs);
	argv = args_to_argv(cmd->args);
	if (is_builtin(cmd->args->value))
	{
		execute_builtin(shell, argv);
		//how leave child procvess after built in exec
	}
	else
	{
		path = parse_paths(shell, cmd);
		execve(path, argv, shell->env);
	}
	array_free(argv);
	free(path);
	perror("minishell: child");
	exit(127); //correct this way or call exit function
}