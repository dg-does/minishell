/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:23:33 by digulraj          #+#    #+#             */
/*   Updated: 2026/01/29 16:01:57 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	expand_args(char **args, int last_exit_status)
{
	char	*expanded;
	int		i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
	{
		if (ft_strchr(args[i], '$'))
		{
			expanded = expand_vars(args[i], last_exit_status);
			free(args[i]);
			args[i] = expanded;
		}
		i++;
	}
}

static void	expand_redirs(t_redir *redirs, int last_exit_status)
{
	t_redir		*current;
	char		*expanded;

	current = redirs;
	while (current)
	{
		if (current->redir != REDIR_HEREDOC)
		{
			if (ft_strchr(current->target, '$'))
			{
				expanded = expand_vars(current->target, last_exit_status);
				free(current->target);
				current->target = expanded;
			}
		}
		current = current->next;
	}
}

void	expand_commands(t_args *commands, int last_exit_status)
{
	t_args	*current;

	current = commands;
	while (current)
	{
		expand_args(current->args, last_exit_status);
		expand_redirs(current->redirs, last_exit_status);
		current = current->next;
	}
}
