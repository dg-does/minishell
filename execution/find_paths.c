/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 11:59:42 by fgreiff           #+#    #+#             */
/*   Updated: 2026/03/10 12:21:21 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "structs.h"

static char	**get_paths(t_minishell *shell)
{
	int		i;
	char	*path_str;
	char	**poss_paths;

	i = 0;
	while (shell->env[i] && ft_strncmp(shell->env[i], "PATH=", 5) != 0)
		i++;
	if (!shell->env[i])
	{
		shell->last_exit_status = 127;
		return (NULL);
	}
	path_str = shell->env[i] + 5;
	poss_paths = gc_split(path_str, ':');
	return (poss_paths);
}

static char	*find_correct_path(t_arg *args, char **poss_paths)
{
	char	*temp;
	char	*candidate;
	int		i;
	t_arg	*current;

	current = args;
	i = 0;
	if (!current->value || current->value == NULL)
		return (NULL);
	while (poss_paths[i])
	{
		temp = ft_strjoin(poss_paths[i], "/");
		candidate = ft_strjoin(temp, current->value);
		free(temp);
		if (access(candidate, X_OK) == 0)
		{
			return (candidate);
		}
		free(candidate);
		i++;
	}
	return (NULL);
}

char	*parse_paths(t_minishell *shell, t_args *cmd)
{
	char	**poss_paths;
	char	*path;

	poss_paths = get_paths(shell);
	path = find_correct_path(cmd->args, poss_paths);
	return (path);
}
