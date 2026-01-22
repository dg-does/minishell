/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:19:20 by fgreiff           #+#    #+#             */
/*   Updated: 2025/05/22 15:52:01 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		s1len;
	int		s2len;
	int		i;
	int		j;
	char	*ptr;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	i = 0;
	j = 0;
	ptr = malloc((s1len + s2len + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	while (i < s1len)
		ptr[i++] = s1[j++];
	j = 0;
	while (i < s1len + s2len)
		ptr[i++] = s2[j++];
	ptr[i] = '\0';
	return (ptr);
}
