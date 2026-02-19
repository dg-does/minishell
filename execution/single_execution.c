/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_execution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixgreiff <felixgreiff@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:17:04 by felixgreiff       #+#    #+#             */
/*   Updated: 2026/02/19 18:30:40 by felixgreiff      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

void	execute_simple(t_minishell *shell, t_args *cmd, int *last_exit_status, char **envp)
{
	if (!cmd->args || !cmd->args->value)
	{
		//free(argv);
		return ;
	}
	if (is_builtin(cmd->args->value))
	{
		if (is_parent_built_in(cmd->args->value))
		{
			execute_parent(shell, cmd->args->value, &last_exit_status);
		}
		else
			execute_child();
	}
	//execute_other?
	//free(argv);
}
