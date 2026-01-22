/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:42:19 by fgreiff           #+#    #+#             */
/*   Updated: 2025/05/23 16:32:51 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	srclen;
	size_t	destlen;

	i = 0;
	srclen = ft_strlen(src);
	destlen = 0;
	while (dest[destlen] != '\0' && destlen < size)
		destlen++;
	if (destlen == size)
		return (size + srclen);
	while (src[i] != '\0' && (destlen + i +1) < size)
	{
		dest[destlen + i] = src[i];
		i++;
	}
	if (destlen + i < size)
		dest[destlen + i] = '\0';
	return (destlen + srclen);
}
