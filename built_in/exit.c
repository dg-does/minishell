/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixgreiff <felixgreiff@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 16:37:06 by felixgreiff       #+#    #+#             */
/*   Updated: 2026/02/05 16:45:28 by felixgreiff      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    exit(t_minishell *shell)
{
    printf("exit");
    //free(everything);
    exit(shell->last_status);
}