/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:00:55 by digulraj          #+#    #+#             */
/*   Updated: 2026/01/29 14:45:21 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static char	*get_var_name(char *str, int *index)
{
	char	*var_name;
	int		start;
	int		len;

	start = *index + 1;
	len = 0;
	if (str[start] == '?')
	{
		*index = start + 1;
		return (ft_strdup("?"));
	}

	while (str[start + len] 
		&& ((ft_isalnum(str[start + len])) || str[start + len] == '_'))
		len++;
	if (len == 0)
		return (NULL);
	var_name = malloc(len + 1);
	if (!var_name)
		return (NULL);
	ft_strlcpy(var_name, &str[start], len + 1);
	*index = start + len;
	return (var_name);
}

static char	*get_var_value(char *var_name, int last_exit_status)
{
	char	*var_value;

	if (ft_strncmp(var_name, "?", 1) == 0)
		return (ft_itoa(last_exit_status));
	var_value = getenv(var_name);
	if (!var_value)
		return (ft_strdup(""));
	return (ft_strdup(var_value));
}

static int	copy2buf(char *buffer, char *var_name, int j, int last_exit_status)
{
	char	*var_value;
	int		i;

	var_value = get_var_value(var_name, last_exit_status);
	if (!var_value)
		return (j);
	i = 0;
	while (var_value[i] && j < TOKEN_BUFFER_SIZE - 1)
		buffer[j++] = var_value[i++];
	free(var_value);
	return (j);
}

char	*expand_vars(char *str, int last_exit_status)
{
	char	buffer[TOKEN_BUFFER_SIZE];
	char	*var_name;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			var_name = get_var_name(str, &i);
			if (!var_name)
				buffer[j++] = '$';
			else
			{
				j = copy2buf(buffer, var_name, j, last_exit_status);
				free(var_name);
			}
		}
		else
			buffer[j++] = str[i++];
	}
	buffer[j] = '\0';
	return (ft_strdup(buffer));
}
