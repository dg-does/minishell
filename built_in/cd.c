/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:06:29 by felixgreiff       #+#    #+#             */
/*   Updated: 2026/02/17 10:30:05 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//never execute in fork always in parent process 

#include "built_in.h"
#include <unistd.h>

int	cd(const char *path)
{
    //maybe pass argv instead and use argv[1] also needs safety checks
    if (chdir(path) != 0)
    {
        perror("cd");
        return (1);
    }
    else 
        return (0);
}