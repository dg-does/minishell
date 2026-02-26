/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 12:42:21 by felixgreiff       #+#    #+#             */
/*   Updated: 2026/02/26 11:07:48 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//create shell struct to save envp

#include "built_in.h"

int	ft_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		ft_printf("%s\n", envp[i]);
		i++;
	}
	return (0);
}
