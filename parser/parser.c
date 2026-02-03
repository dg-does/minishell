/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:57:21 by fgreiff           #+#    #+#             */
/*   Updated: 2026/02/03 13:55:05 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

//alloc_args;
//traverse input first to count words until hitting pipe, redirect or end
//allocate args array for first argument
//repeat process until end of linked list

/*static void	free_args(t_args *args_head)
{
	t_args	*curr;

	curr = args_head;
	while (curr)
	{
		if (curr->args)
			free(curr->args);
		curr = curr->next;
	}
}*/

void	add_arg(t_args *cmd, char *value, t_quote quote_type)
{
	t_arg	*new;
	t_arg	*tmp;

	new = malloc(sizeof(t_arg));
	if (!new)
		return ;
	new->value = value;
	new->quote_type = quote_type;
	new->next = NULL;
	if (!cmd->args)
		cmd->args = new;
	else
	{
		tmp = cmd->args;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	parse_redirections(t_token	**token, t_args *cmd)
{
	t_redir	*redir;
	t_token	*next;
	t_redir	*tmp;

	redir = malloc(sizeof(t_redir));
	if (!redir)
		return ;
	redir->redir = token_to_redir_type((*token)->type);
	redir->next = NULL;
	next = (*token)->next;
	if (!next || next->type != TOKEN_WORD)
		return (free(redir));
	redir->target = next->value;
	if (!cmd->redirs)
		cmd->redirs = redir;
	else
	{
		tmp = cmd->redirs;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = redir;
	}
	*token = next->next;
}

t_args	*parsing_tokens(t_token *token)
{
	t_args	*cmd_head;
	t_args	*current_cmd;
	t_token	*current_token;

	cmd_head = NULL;
	allocate_nodes_arg(token, &cmd_head);
	current_cmd = cmd_head;
	current_token = token;
	while (current_token)
	{
		if (current_token->type == TOKEN_WORD)
		{
			add_arg(current_cmd, current_token->value,
				current_token->quote_type);
			current_token = current_token->next;
		}
		else if (is_redirection(current_token->type))
			parse_redirections(&current_token, current_cmd);
		else if (current_token->type == TOKEN_PIPE)
		{
			current_cmd = current_cmd->next;
			current_token = current_token->next;
		}
	}
	return (cmd_head);
}
