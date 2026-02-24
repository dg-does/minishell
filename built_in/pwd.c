/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:20:12 by fgreiff           #+#    #+#             */
/*   Updated: 2026/02/24 21:26:31 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//never execute in fork always in parent process

#include "built_in.h"
#include "structs.h"

int	ft_pwd(void)
{
	char	*buf;
	size_t	size;

	size = 256;
	buf = malloc(size);
	if (!buf)
		return (1);
	getcwd(buf, size);
	if (getcwd(buf, size) == NULL)
	{
		if (errno != ERANGE)
		{
			perror("minishell: pwd");
			free(buf);
			return (1);
		}
		free(buf);
		size *= 2;
		buf = malloc(size);
		if (!buf)
			return (1);
	}
	write (1, buf, ft_strlen(buf));
	write(1, "\n", 1);
	free(buf);
	return (0);
}
