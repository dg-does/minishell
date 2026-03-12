/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:20:12 by fgreiff           #+#    #+#             */
/*   Updated: 2026/03/12 16:32:51 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"
#include "structs.h"
#include "minishell.h"

int	ft_pwd(void)
{
	char	*buf;
	size_t	size;

	size = 256;
	while (1)
	{
		buf = gc_malloc(size);
		if (!buf)
			return (1);
		if (getcwd(buf, size))
			break ;
		gc_free(buf);
		if (errno != ERANGE)
		{
			perror("minishell: pwd");
			return (1);
		}
		size *= 2;
	}
	write (1, buf, ft_strlen(buf));
	write(1, "\n", 1);
	return (0);
}
