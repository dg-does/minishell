/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixgreiff <felixgreiff@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:21:58 by felixgreiff       #+#    #+#             */
/*   Updated: 2026/02/03 17:31:21 by felixgreiff      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int export(t_minishell *shell, char *export_value)
{
    int i;

    i = 0;
    while (export_value[i] != "=")
        i++;
    
}