/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:58:10 by fgreiff           #+#    #+#             */
/*   Updated: 2025/05/26 16:01:36 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*cs;

	i = 0;
	cs = (const char *)s;
	while (i < n)
	{
		if ((unsigned char)cs[i] == (unsigned char)c)
			return ((void *)&cs[i]);
		i++;
	}
	return (NULL);
}
