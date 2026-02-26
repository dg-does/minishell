/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 16:30:16 by fgreiff           #+#    #+#             */
/*   Updated: 2026/02/26 11:09:35 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_redir_type	token_to_redir_type(t_type type)
{
	if (type == TOKEN_REDIRECT_IN)
		return (REDIR_IN);
	if (type == TOKEN_REDIRECT_OUT)
		return (REDIR_OUT);
	if (type == TOKEN_REDIRECT_APPEND)
		return (REDIR_APPEND);
	if (type == TOKEN_HEREDOC)
		return (REDIR_HEREDOC);
	return (-1);
}

int	is_redirection(t_type type)
{
	return (type == TOKEN_REDIRECT_IN
		|| type == TOKEN_REDIRECT_OUT
		|| type == TOKEN_REDIRECT_APPEND
		|| type == TOKEN_HEREDOC);
}

void	allocate_nodes_arg(t_token *token, t_args **args_head)
{
	int		num_cmnds;
	t_args	*current_args;
	int		i;

	i = 0;
	num_cmnds = count_pipes(token);
	*args_head = malloc(sizeof(t_args));
	if (!*args_head)
		return ;
	(*args_head)->args = NULL;
	(*args_head)->redirs = NULL;
	(*args_head)->next = NULL;
	current_args = *args_head;
	while (i < num_cmnds)
	{
		current_args->next = malloc(sizeof(t_args));
		if (!current_args->next)
			return ;
		current_args = current_args->next;
		current_args->args = NULL;
		current_args->redirs = NULL;
		current_args->next = NULL;
		i++;
	}
}

int	count_pipes(t_token *token)
{
	int		pipe_counter;

	pipe_counter = 0;
	while (token->next)
	{
		if (token->type == TOKEN_PIPE)
			pipe_counter++;
		token = token->next;
	}
	return (pipe_counter);
}

/* print functions to delete later

const char	*quote_type_str(t_quote quote)
{
	if (quote == NO_QUOTE)
		return ("NO_QUOTE");
	if (quote == SINGLE_QUOTE)
		return ("SINGLE_QUOTE");
	if (quote == DOUBLE_QUOTE)
		return ("DOUBLE_QUOTE");
	return ("UNKNOWN_QUOTE");
}

const char *redir_type_str(t_redir_type type)
{
	if (type == REDIR_IN)
		return ("REDIR_IN");
	if (type == REDIR_OUT)
		return ("REDIR_OUT");
	if (type == REDIR_APPEND)
		return ("REDIR_APPEND");
	if (type == REDIR_HEREDOC)
		return ("REDIR_HEREDOC");
	return ("UNKNOWN_REDIR");
}

void	print_list(t_args *cmds)
{
	t_arg	*arg;
	t_redir	*redir;
	int		i;

	while (cmds)
	{
		arg = cmds->args;
		i = 0;
		if (arg)
			printf("\n--- ARGS ---\n");
		while (arg)
		{
			printf("[%d] %s | WORD | Quote Type: %s\n", i++, arg->value,
				quote_type_str(arg->quote_type));
			arg = arg->next;
		}
		redir = cmds->redirs;
		if (redir)
			printf("--- REDIRECTONS ---\n");
		while (redir)
		{
			printf("[%s] %s\n", redir_type_str(redir->redir), redir->target);
			redir = redir->next;
		}
		printf("===============\n");
		cmds = cmds->next;
	}
}

//*/