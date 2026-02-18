/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:06:29 by felixgreiff       #+#    #+#             */
/*   Updated: 2026/02/18 19:23:11 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//never execute in fork always in parent process 

#include "built_in.h"

int	ft_cd(char **argv)
{
	char	*path;

	if (!argv[1])
	{
		path = getenv("HOME");
		if (!path)
		{
			ft_putstr_fd("cd: HOME not set\n", 2);
			return (1);
		}
	}
	if (argv[1] && argv[2])
	{
		ft_putstr_fd("cd: too many arguments\n", 2);
		return (1);
	}
	else
		path = argv[1];
	if (chdir(path) != 0)
	{
		ft_putstr_fd("cd: ", 2);
		perror(path);
		return (1);
	}
	return (0);
}
