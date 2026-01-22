/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:29:02 by digulraj          #+#    #+#             */
/*   Updated: 2026/01/20 15:43:23 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	ft_isalnum(int c)
{
	if (((c >= 97) && (c <= 122)) || ((c >= 65) && (c <= 90)) || 
		((c >= 48) && (c <= 57)))
		return (c);
	else
		return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

//ft_strlen
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

//ft_split
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

//ft strjoin
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

//ft_strncmp
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0')
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
