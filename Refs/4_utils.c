/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 19:23:19 by digulraj          #+#    #+#             */
/*   Updated: 2026/01/12 16:04:44 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static int	count_words(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static char	*get_word(const char *s, char c)
{
	char	*word;
	int		len;
	int		i;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	word = (char *)malloc(len + 1);
	if (!word)
		return (0);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

static void	free_split(char **arr, int i)
{
	while (i > 0)
	{
		i--;
		free(arr[i]);
	}
	free(arr);
}

static int	split_loop(char const **s, char **res, char c, int i)
{
	res[i] = get_word(*s, c);
	if (!res[i])
	{
		free_split(res, i);
		return (-1);
	}
	i++;
	while (**s && **s != c)
		(*s)++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;

	i = 0;
	if (!s)
		return (0);
	res = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!res)
		return (0);
	while (*s)
	{
		if (*s != c)
		{
			i = split_loop(&s, res, c, i);
			if (i == -1)
				return (0);
		}
		else
			s++;
	}
	res[i] = 0;
	return (res);
}

int		ft_strlen(const char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (s1[i])
		res[j++] = s1[i++];
	i = 0;
	while (s2[i])
		res[j++] = s2[i++];
	res[j] = '\0';
	return (res);
}