/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 16:30:16 by fgreiff           #+#    #+#             */
/*   Updated: 2026/03/12 16:33:30 by fgreiff          ###   ########.fr       */
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
	*args_head = gc_malloc(sizeof(t_args));
	if (!*args_head)
		return ;
	(*args_head)->args = NULL;
	(*args_head)->redirs = NULL;
	(*args_head)->next = NULL;
	current_args = *args_head;
	while (i < num_cmnds)
	{
		current_args->next = gc_malloc(sizeof(t_args));
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

	if (!token)
		return (0);
	pipe_counter = 0;
	while (token->next)
	{
		if (token->type == TOKEN_PIPE)
			pipe_counter++;
		token = token->next;
	}
	return (pipe_counter);
}
