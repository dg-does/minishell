/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:05:55 by felixgreiff       #+#    #+#             */
/*   Updated: 2026/03/03 12:43:07 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "execution.h"
#include "minishell.h"

void	execute_cmds(t_minishell *shell, t_args *cmds)
{

	shell->cmd_count = count_cmds(cmds);
	expand_commands(cmds, shell);
	prepare_heredocs(shell, cmds);
	if (shell->cmd_count == 1)
	{
		execute_simple(shell, cmds);
		return ;
	}
	execute_multiple(shell, cmds);
}
