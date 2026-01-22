/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 11:59:42 by fgreiff           #+#    #+#             */
/*   Updated: 2026/01/20 15:41:47 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static char	**get_paths(char **envp)
{
	int		i;
	char	*path_str;
	char	**poss_paths;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (!envp[i])
	{
		//error handeling;
		return ;
	}
	path_str = envp[i] + 5;
	poss_paths = ft_split(path_str, ':');
	return (poss_paths);
}

static char	*find_correct_path(t_args *args, char **poss_paths)
{
	char	*temp;
	char	*candidate;
	int		i;
	t_args	*current;

	current = args;
	if (!current->args || current->args[0] == '\0')
		return (NULL);
	while (poss_paths[i])
	{
		temp = ft_strjoin(poss_paths[i], "/");
		candidate = ft_strjoin(temp, current->args[0]);
		free(temp);
		if (access(candidate, X_OK) == 0)
		{
			free(candidate);
			return (poss_paths[i]);
		}
		free(candidate);
		i++;
	}
	return (NULL);
}

void	parse_paths(t_args *args_head, char **envp)
{
	char	**poss_paths;
	t_args	*current;

	current = args_head;
	poss_paths = get_paths(envp);
	while (current->next != NULL)
	{
		current->path = find_correct_path(current, poss_paths);
		current = current->next;
	}
}