/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixgreiff <felixgreiff@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:39:57 by felixgreiff       #+#    #+#             */
/*   Updated: 2026/02/03 15:48:07 by felixgreiff      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

int echo(char **argv)
{
    int n;
    int i;
    
    if (!argv[1])
        return (1);
    if (argv[1] == "-n")
    {
        n = 1;
        i = 2;
    }
    else
    {
        n = 0;
        i = 1;
    }
    while (argv[i])
    {
        printf("%s ", argv[i]);
        i++;
    }
    if (n == 0)
        write (1, "\n", 1);
    return (0);
    
}