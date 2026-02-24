/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:20:12 by fgreiff           #+#    #+#             */
/*   Updated: 2026/02/24 16:51:11 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//never execute in fork always in parent process

#include "built_in.h"
#include "structs.h"

int	ft_pwd(void)
{
	char	*path;
	size_t	size;

	size = 256;
	path = malloc(size);
	getcwd(path, size);
	if (path == NULL)
	{
		if (errno != ERANGE)
		{
			perror("minishell: pwd");
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
