/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:39:57 by felixgreiff       #+#    #+#             */
/*   Updated: 2026/03/06 11:34:24 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

static int	get_start(char **argv)
{
	if (ft_strcmp(argv[1], "-n") == 0)
		return (2);
	return (1);
}

int	ft_echo(char **argv)
{
	int	n;
	int	i;

	n = 0;
	if (!argv[1])
		return (write(1, "\n", 1), 0);
	i = get_start(argv);
	n = (i == 2);
	while (argv[i])
	{
		ft_putstr_fd(argv[i], 1);
		if (argv[i + 1])
			ft_putstr_fd(" ", 1);
		i++;
	}
	if (n == 0)
		write (1, "\n", 1);
	return (0);
}
