/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:39:57 by felixgreiff       #+#    #+#             */
/*   Updated: 2026/03/02 10:51:56 by fgreiff          ###   ########.fr       */
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
		ft_printf("%s", argv[i]);
		i++;
	}
	if (n == 0)
		write (1, "\n", 1);
	return (0);
}
