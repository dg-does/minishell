/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixgreiff <felixgreiff@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 12:42:21 by felixgreiff       #+#    #+#             */
/*   Updated: 2026/02/03 15:47:53 by felixgreiff      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//create shell struct to save envp

#include "built_in.h"

int env(char **envp)
{
    int i;
    
    i = 0;
    while (envp[i] != NULL)
    {
        printf("%s\n", envp[i]);
        i++;
    }
    return (0);
    
}