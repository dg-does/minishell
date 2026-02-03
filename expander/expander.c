/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:23:33 by digulraj          #+#    #+#             */
/*   Updated: 2026/02/03 13:59:30 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	expand_redirs(t_redir *redirs, int last_exit_status)
{
	t_redir		*current;
	char		*expanded;

	current = redirs;
	while (current)
	{
		if (current->redir != REDIR_HEREDOC)
		{
			if (current->target && ft_strchr(current->target, '$'))
			{
				expanded = expand_vars(current->target, last_exit_status);
				free(current->target);
				current->target = expanded;
			}
		}
		current = current->next;
	}
}

void	expand_commands(t_args *cmds, int last_exit_status)
{
	t_arg	*arg;

	while (cmds)
	{
		arg = cmds->args;
		while (arg)
		{
			if (arg->quote_type != SINGLE_QUOTE && ft_strchr(arg->value, '$'))
				arg->value = expand_vars(arg->value, last_exit_status);
			arg = arg->next;
		}
		expand_redirs(cmds->redirs, last_exit_status);
		cmds = cmds->next;
	}
}
