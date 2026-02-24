/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 16:37:06 by felixgreiff       #+#    #+#             */
/*   Updated: 2026/02/24 15:10:21 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"
#include "structs.h"
#include "minishell.h"

void	ft_exit(t_minishell *shell)
{
	printf("exit\n");
	free_shell(shell);
	exit(shell->last_exit_status);
}

