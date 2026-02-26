/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:05:55 by felixgreiff       #+#    #+#             */
/*   Updated: 2026/02/26 11:32:28 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "execution.h"

void	execute_cmds(t_minishell *shell, t_args *cmds)
{
	int	cmd_count;

	cmd_count = count_cmds(cmds);

	if (cmd_count == 1)
		execute_simple(shell, cmds);
	else
		execute_multiple(shell, cmds, cmd_count);
}
