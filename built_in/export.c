/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:21:58 by felixgreiff       #+#    #+#             */
/*   Updated: 2026/03/04 14:16:40 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "built_in.h"
#include "minishell.h"

static int	is_valid(char *export_value)
{
	int	i;

	if (!ft_isalpha(export_value[0]) && export_value[0] != '_')
		return (0);
	i = 1;
	while (export_value[i] != '\0' && export_value[i] != '=')
	{
		if (!ft_isalnum(export_value[i]) && export_value[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

static int	get_key_len(char *export_value)
{
	int	i;

	i = 0;
	while (export_value[i] != '\0' && export[i] != '=')
		i++;
	if (export_value[i] == '=')
		i++;
	return (i);
}

static char	**append_to_env(char **env, char *export_value, int len)
{
	char	**new_env;
	int		i;

	i = 0;
	while (env[i])
		i++;
	new_env = malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (env[i])
	{
		new_env[i] = env[i];
		i++;
	}
	new_env[i++] = ft_strdup(export_value);
	new_env[i] = NULL;
	free(env);
	return (new_env);
}

int	ft_export(t_minishell *shell, char *export_value)
{
	int		key_len;
	int		i;

	if (!is_valid(export_value))
		return (1);
	key_len = get_key_len(export_value);
	i = 0;
	while (shell->env[i] != NULL 
		&& ft_strncmp(shell->env[i], export_value, key_len) != 0)
		i++;
	if (shell->env[i] == NULL)
		shell->env = append_to_env(shell->env, export_value, key_len);
	else
	{
		free(shell->env[i]);
		shell->env[i] = ft_strdup(export_value);
	}
	return (0);
}
