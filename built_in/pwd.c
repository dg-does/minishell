/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:20:12 by fgreiff           #+#    #+#             */
/*   Updated: 2026/02/26 14:02:06 by digulraj         ###   ########.fr       */
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
	while (1)
	{
		buf = malloc(size);
		if (!buf)
			return (1);
		if (getcwd(buf, size))
			break ;
		free(buf);
		if (errno != ERANGE)
		{
			perror("minishell: pwd");
			return (1);
		}
		size *= 2;
	}
	write (1, buf, ft_strlen(buf));
	write(1, "\n", 1);
	free(buf);
	return (0);
}
