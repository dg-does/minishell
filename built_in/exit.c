/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 16:37:06 by felixgreiff       #+#    #+#             */
/*   Updated: 2026/02/26 11:07:53 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"
#include "structs.h"
#include "minishell.h"

void	ft_exit(t_minishell *shell)
{
	ft_printf("exit\n");
	free_shell(shell);
	exit(shell->last_exit_status);
}

