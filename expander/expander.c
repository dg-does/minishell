/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:00:55 by digulraj          #+#    #+#             */
/*   Updated: 2026/01/20 15:42:52 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#import "parser.h"

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
		return (strdup("?"));
	}

	while (str[start + len] 
		&& (ft_isalnum(str[start + len])) || str[start + len == '_'])
		len++;
	if (len == 0)
		return (NULL);
	var_name = malloc(len + 1);
	if (!var_name)
		return (NULL);
	ft_strncpy(var_name, &str[start], len + 1);
	*inex = start + len;
	return (var_name);
}

char	*get_var_value(char *var_name, int last_exit_status)
{
	char	*var_value;
	char	*exit_str;

/* figure out exit code bita
	if (ft_strcmp(var_name, "?") == 0)
	{

	}
*/
	var_value = getenv(var_name);
	if (!var_value)
		return (strdup(""));
	return (strdup(var_value));
}

char	*expand_vars(char *str, int last_exit_status)
{
	char	*buffer[TOKEN_BUFFER_SIZE];
	char	*var_name;
	char	*var_value;
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
			{
				buffer[j++] = '$';
				i++;
				continue ;
			}
			var_value = get_var_value(var_name, last_exit_status);
			free(var_name);
			//copy var_value into buffer
		}
		else
			buffer[j++] = str[i++];
	}
	buffer[j] = '\0';
	return (strdup(buffer));
}
