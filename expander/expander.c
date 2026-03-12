/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:23:33 by digulraj          #+#    #+#             */
/*   Updated: 2026/03/12 14:21:48 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	expand_redirs(t_redir *redirs, t_minishell *shell)
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
				expanded = expand_vars(current->target, shell);
				current->target = expanded;
			}
		}
		current = current->next;
	}
}

static t_arg	*remove_empty_arg(t_args *cmds, t_arg *arg, t_arg *prev)
{
	t_arg	*next;

	next = arg->next;
	if (prev)
		prev->next = next;
	else
		cmds->args = next;
	return (next);
}

static char	*strip_quotes(char *str)
{
	char	buffer[TOKEN_BUFFER_SIZE];
	int		i;
	int		j;
	int		in_double;
	int		in_single;

	i = 0;
	j = 0;
	in_single = 0;
	in_double = 0;
	while (str[i])
	{
		if (str[i] == '\'' && !in_double)
			return (in_single = !in_single, i++, buffer);
		if (str[i] == '"' && !in_single)
			return (in_double = !in_double, i++, buffer);
		buffer[j++] = str[i++];
	}
	buffer[j] = '\0';
	return (gc_strdup(buffer));
}

void	expand_commands(t_args *cmds, t_minishell *shell)
{
	t_arg	*arg;
	t_arg	*prev;

	while (cmds)
	{
		arg = cmds->args;
		prev = NULL;
		while (arg)
		{
			if (arg->quote_type != SINGLE_QUOTE)
				arg->value = expand_vars(arg->value, shell);
			else
				arg->value = strip_quotes(arg->value);
			if (arg->quote_type == NO_QUOTE && ft_strlen(arg->value) == 0)
				arg = remove_empty_arg(cmds, arg, prev);
			else
			{
				prev = arg;
				arg = arg->next;
			}
		}
		expand_redirs(cmds->redirs, shell);
		cmds = cmds->next;
	}
}
