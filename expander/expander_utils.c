/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:00:55 by digulraj          #+#    #+#             */
/*   Updated: 2026/03/10 16:34:38 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static char	*get_var_name(char *str, int *index)
{
	char	*var_name;
	int		start;
	int		len;

	start = *index;
	len = 0;
	if (str[start] == '?')
	{
		*index = start + 1;
		return (gc_strdup("?"));
	}
	while (str[start + len] 
		&& ((ft_isalnum(str[start + len])) || str[start + len] == '_'))
		len++;
	if (len == 0)
		return (NULL);
	var_name = gc_malloc(len + 1);
	if (!var_name)
		return (NULL);
	ft_strlcpy(var_name, &str[start], len + 1);
	*index = start + len;
	return (var_name);
}

static char	*get_var_value(char *var_name, t_minishell *shell)
{
	char	*tmp;
	char	*registered;
	int		i;
	int		len;

	if (ft_strncmp(var_name, "?", 1) == 0)
	{
		tmp = ft_itoa(shell->last_exit_status);
		registered = gc_strdup(tmp);
		free(tmp);
		return (registered);
	}
	i = 0;
	len = ft_strlen(var_name);
	while (shell->env[i])
	{
		if (ft_strncmp(shell->env[i], var_name, len) == 0
			&& shell->env[i][len] == '=')
			return (gc_strdup(shell->env[i] + len + 1));
		i++;
	}
	return (gc_strdup(""));
}

static int	copy2buf(char *buffer, char *var_name, int j, t_minishell *shell)
{
	char	*var_value;
	int		i;

	var_value = get_var_value(var_name, shell);
	if (!var_value)
		return (j);
	i = 0;
	while (var_value[i] && j < TOKEN_BUFFER_SIZE - 1)
		buffer[j++] = var_value[i++];
	return (j);
}

static int	process_char(char *str, char *buf, int *i, t_minishell *shell)
{
	char	*var_name;
	int		c;

	c = str[(*i)++];
	if (c == '\'' && shell->expand_state != 2)
		return (shell->expand_state = !shell->expand_state, -1);
	if (c == '"' && shell->expand_state != 1)
	{
		if (shell->expand_state == 0)
			shell->expand_state = 2;
		else
			shell->expand_state = 0;
		return (-1);
	}
	if (c == '$' && shell->expand_state != 1)
	{
		var_name = get_var_name(str, i);
		if (var_name)
			return (copy2buf(buf, var_name, 0, shell));
		buf[0] = '$';
		return (1);
	}
	buf[0] = c;
	return (1);
}

char	*expand_vars(char *str, t_minishell *shell)
{
	char	buf[TOKEN_BUFFER_SIZE];
	int		i;
	int		j;
	int		result;

	i = 0;
	j = 0;
	shell->expand_state = 0;
	while (str[i])
	{
		result = process_char(str, &buf[j], &i, shell);
		if (result != -1)
			j += result;
	}
	buf[j] = '\0';
	return (gc_strdup(buf));
}
