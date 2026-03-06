/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 14:33:04 by felixgreiff       #+#    #+#             */
/*   Updated: 2026/03/06 13:47:20 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "built_in.h"
#include "minishell.h"

static int	is_valid(char *unset_value)
{
	int	i;

	if (!ft_isalpha(unset_value[0]) && unset_value[0] != '_')
		return (0);
	i = 1;
	while (unset_value[i] != '\0')
	{
		if (!ft_isalnum(unset_value[i]) && unset_value[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

static int	find_env_index(char **env, char *unset_value, int len)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], unset_value, len) && env[i][len] == '=')
			return (i);
		i++;
	}
	return (-1);
}

static char	**build_new_env(char **env, int skip, int len)
{
	char	**new_env;
	int		j;
	int		k;

	new_env = gc_malloc(sizeof(char *) * len);
	j = 0;
	k = 0;
	while (env[j])
	{
		if (j != skip)
			new_env[k++] = env[j];
		j++;
	}
	new_env[k] = NULL;
	return (new_env);
}

int	ft_unset(t_minishell *shell, char *unset_value)
{
	int		i;
	int		j;
	char	**new_env;

	if (!unset_value)
		return (0);
	if (!is_valid(unset_value))
		return (1);
	i = find_env_index(shell->env, unset_value, ft_strlen(unset_value));
	if (i == -1)
		return (0);
	j = 0;
	while (shell->env[j])
		j++;
	new_env = build_new_env(shell->env, i, j);
	free(shell->env[i]);
	free(shell->env);
	shell->env = new_env;
	return (0);
}
