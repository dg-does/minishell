/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixgreiff <felixgreiff@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:20:12 by fgreiff           #+#    #+#             */
/*   Updated: 2026/02/03 12:32:23 by felixgreiff      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//never execute in fork always in partent process

#include "built_in.h"

int pwd(void)
{
	char	*path;
	size_t	size;
	int		i;

	size = 256;
	path = malloc(size);
	getcwd(path, size);
	if (path == NULL)
	{
		if (errno != ERANGE)
		{
			perror(errno);
			return (1);
		}
		else if (errno == ERANGE)
		{
			while (errno == ERANGE)
			{
				size *= 2;
				path = malloc(size);
				getcwd(path, size);
			}
		}
	}
	write (1, &path, ft_strlen(path));
	return (0);
}