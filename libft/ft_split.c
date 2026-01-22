/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:20:21 by fgreiff           #+#    #+#             */
/*   Updated: 2025/05/30 12:00:02 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wcount(const char *s, char c)
{
	size_t	wcount;
	size_t	i;
	int		inword;

	wcount = 0;
	i = 0;
	inword = 0;
	while (s[i])
	{
		if (s[i] != c && inword == 0)
		{
			inword = 1;
			wcount++;
		}
		else if (s[i] == c)
		{
			inword = 0;
		}
		i++;
	}
	return (wcount);
}

static char	*ft_walloc(const char *start, const char *end)
{
	size_t	i;
	size_t	len;
	char	*result;

	len = end - start;
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = start[i];
		i++;
	}
	result[len] = '\0';
	return (result);
}

static void	*ft_free(char **str, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free (str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	char		**result;
	const char	*start;
	size_t		i;

	result = malloc((ft_wcount(s, c) + 1) * sizeof(char *));
	if (!s || !(result))
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (!*s)
			break ;
		start = s;
		while (*s && *s != c)
			s++;
		result[i] = ft_walloc(start, s);
		if (!result[i])
			return (ft_free(result, i));
		i++;
	}
	result[i] = NULL;
	return (result);
}

/* #include <stdio.h>

int	main(void)
{
	char	**result = ft_split("hello0world,0how0are0you0!", '0');
	size_t	i = 0;

	while (result[i])
	{
		printf ("word %zu: %s\n", i, result[i]);
		free(result[i]);
		i++;
	}
}*/