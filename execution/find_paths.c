/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 11:59:42 by fgreiff           #+#    #+#             */
/*   Updated: 2026/03/12 14:37:57 by fgreiff          ###   ########.fr       */
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
	if (!current->value || !poss_paths)
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
	char	*cmd_str;

	if (!cmd->args || !cmd->args->value)
		return (NULL);
	cmd_str = cmd->args->value;
	if (cmd_str[0] == '/' || (cmd_str [0] == '.' && cmd_str[1] == '/'))
	{
		if (access(cmd_str, X_OK) == 0)
			return (cmd_str);
		return (NULL);
	}
	poss_paths = get_paths(shell);
	if (!poss_paths)
		return (NULL);
	path = find_correct_path(cmd->args, poss_paths);
	return (path);
}
