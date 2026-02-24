/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:05:55 by felixgreiff       #+#    #+#             */
/*   Updated: 2026/02/24 16:39:09 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "execution.h"

void	execute_cmds(t_minishell *shell, t_args *cmds)
{
	if (!cmds)
		return ;
	if (!cmds->next)
		execute_simple(shell, cmds);
	/*else
		execute_complex(shell, cmds, last_exit_status, envp);*/
}
