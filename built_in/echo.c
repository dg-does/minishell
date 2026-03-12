/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:39:57 by felixgreiff       #+#    #+#             */
/*   Updated: 2026/03/12 14:28:31 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

static int	is_n_flag(char *argv)
{
	int	i;

	if (!argv || argv[0] != '-' || argv[1] == '\0')
		return (0);
	i = 1;
	while (argv[i])
	{
		if (argv[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

static int	get_start(char **argv, int *n)
{
	int	i;

	i = 1;
	while (argv[i] && is_n_flag(argv[i]))
	{
		*n = 1;
		i++;
	}
	return (i);
}

int	ft_echo(char **argv)
{
	int	n;
	int	i;

	n = 0;
	if (!argv[1])
		return (write(1, "\n", 1), 0);
	i = get_start(argv, &n);
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
