/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:48:18 by fgreiff           #+#    #+#             */
/*   Updated: 2025/05/23 21:04:29 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strchrl(char s1, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (s1 == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int		slen;
	int		i;

	i = 0;
	slen = ft_strlen(s1);
	if (!s1 || !set)
		return (NULL);
	while (ft_strchrl(s1[i], set) && s1[i])
		i++;
	while (ft_strchrl(s1[slen - 1], set) && slen > i)
		slen--;
	return (ft_substr(s1, i, slen - i));
}
