/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:21:58 by felixgreiff       #+#    #+#             */
/*   Updated: 2026/02/17 10:31:45 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//Input in format "KEY=VALUE"
//need to check if already has been added a "KEY="
//for this use strncmp with the i from the first loop
//if "KEY="already exists just replace VALUE
//if thats the case free the poionter and strdup export value
//if not at the end of ENV allocate strlen(export_value) new array and strdup with "KEY=VALUE"

static int	check_validity(char *export_value)
{
    int i;

    i = 1;
    if (!ft_isalpha(export_value[0]) && export_value[0] != '_')
        return (1);
    while (export_value[i] != NULL)
	{
		if (!ft_isalnum(export_value[i] && export_value[i] != '_'))
			return (1);
		i++;
	}
	return (0);
}


int	export(t_minishell *shell, char *export_value)
{
    int		key_len;
    int		i;
    int 	j;
	char	**temp_env;

    key_len = 0;
    if (check_validity(export_value))
    {
        //print error?
        return (1);
    }
    while (export_value[key_len] != "=" || export_value[key_len] != '\0')
        key_len++;
    key_len++;
    while (shell->env[i] != NULL)
    {
        if (ft_strncmp(shell->env[i], export_value, key_len) == 0)
            break ;
        i++;
    }
    if (shell->env[i] == NULL)
    {
		j = 0;
		temp_env = malloc(sizeof(char *) * (i + 2));
		while (shell->env[j] != NULL)
		{
			temp_env[j] = shell->env[j];
			j++;
		}
		temp_env[j++] = ft_strdup(export_value);
		temp_env[j++] = NULL;
		free(shell->env);
		shell->env = temp_env;
		array_free(temp_env);
	}
    else
    {
		free(shell->env[i]);
		shell->env[i] = ft_strdup(export_value);
	}    
    return (0);
}