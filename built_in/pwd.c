/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:20:12 by fgreiff           #+#    #+#             */
/*   Updated: 2026/01/29 18:00:47 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

char	*pwd(void)
{
	char	*path;
	size_t	size;
	int		i;

	size = 256;
	path = malloc(size);
	getcwd(path, size);
	if (errno == ERANGE)
	{
		while (path == NULL)
		{
			free(path);
			size *= 2;
			path = malloc(size);
			getcwd(path, size);
		}
	}
	return (path);
}