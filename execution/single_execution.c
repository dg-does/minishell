/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_execution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:17:04 by felixgreiff       #+#    #+#             */
/*   Updated: 2026/02/24 12:39:41 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "execution.h"

int	is_builtin(char *cmd)
{
	if (ft_strcmp(cmd, "cd") == 0)
		return (1);
	if (ft_strcmp(cmd, "echo") == 0)
		return (1);
	if (ft_strcmp(cmd, "env") == 0)
		return (1);
	if (ft_strcmp(cmd, "exit") == 0)
		return (1);
	if (ft_strcmp(cmd, "export") == 0)
		return (1);
	if (ft_strcmp(cmd, "pwd") == 0)
		return (1);
	if (ft_strcmp(cmd, "unset") == 0)
		return (1);
}

static int	is_parent_builtin(char *cmd)
{
	if (ft_strcmp(cmd, "cd") == 0)
		return (1);
	else if (ft_strcmp(cmd, "exit") == 0)
		return (1);
	else if (ft_strcmp(cmd, "export") == 0)
		return (1);
	else if (ft_strcmp(cmd, "unset") == 0)
		return (1);
	else 
		return (0);
}

void	execute_simple(t_minishell *shell, t_args *cmd, char **envp)
{
	pid_t	pid1;

	if (!cmd->args || !cmd->args->value)
	{
		//some kind of exit code?
		return ;
	}
	if (is_parent_built_in(cmd->args->value))
		execute_parent(shell, cmd->args, shell->last_exit_status);
	else
	{
		pid1 = fork();
		if (pid1 == 0)
			execute_child(shell, cmd);
		waitpid(pid1, shell->last_exit_status, 0);
	}
	//execute_other?
	//free(argv);
}
