/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixgreiff <felixgreiff@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 14:33:04 by felixgreiff       #+#    #+#             */
/*   Updated: 2026/02/19 13:03:32 by felixgreiff      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_validity(char *export_value)
{
    int i;

    i = 1;
    if (!ft_isalpha(export_value[0]) && export_value[0] != '_')
        return (1);
    while (export_value[i] != '\0')
	{
		if (!ft_isalnum(export_value[i] && export_value[i] != '_'))
			return (1);
		i++;
	}
	return (0);
}

int	ft_unset(t_minishell *shell, char *unset_value)
{
	int		i;
	int		j;
	int		env_len;
	int		value_len;
	char	**temp_env;

	env_len = 0;
	if (check_validity(unset_value) != 0)
	{
		//print error
		return (1);
	}
	value_len = ft_strlen(unset_value);
	i = 0;
	while (shell->env[env_len] != NULL)
		env_len++;
	while (shell->env[i] != NULL)
	{
		if (ft_strncmp(shell->env[i], unset_value, value_len))
			break ;
	}
	if (shell->env[i] == NULL)
		return (0);
	else
	{
		j = 0;
		temp_env = malloc(sizeof(char *) * env_len);
		free(shell->env[i]);
		while (shell->env[j] != 0)
		{
			temp_env[j] = shell->env[j];
			j++;
		}
		temp_env[j] = NULL;
		free(shell->env);
		shell->env = temp_env;
		array_free(temp_env);
	}
	return (0);
}
