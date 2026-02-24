/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:05:55 by felixgreiff       #+#    #+#             */
/*   Updated: 2026/02/24 12:39:17 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "execution.h"

void	execute_cmds(t_minishell *shell, t_args *cmds, int *last_exit_status, char **envp)
{
	if (!cmds)
		return ;
	if (!cmds->next)
		execute_simple(shell, cmds, last_exit_status, envp);
	else
		execute_complex(shell, cmds, last_exit_status, envp);
}