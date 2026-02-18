/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:39:57 by felixgreiff       #+#    #+#             */
/*   Updated: 2026/02/18 19:35:07 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

int	ft_echo(char **argv)
{
	int	n;
	int	i;

	n = 0;
	if (!argv[1])
		return (1);
	if (ft_strcmp(argv[1], "-n") == 0)
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
