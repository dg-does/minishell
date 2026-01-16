/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:57:21 by fgreiff           #+#    #+#             */
/*   Updated: 2026/01/16 13:06:39 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

//alloc_args;
//traverse input first to count words until hitting pipe, redirect or end
//allocate args array for first argument
//repeat process until end of linked list

static void	alloc_args(t_token *token, t_args *args_head)
{
	int		word_count;
	t_args	*curr_args;
	t_token	*curr_token;

	curr_args = args_head;
	curr_token = token;
	while (curr_args != NULL)
	{
		word_count = 0;
		while (curr_token && curr_token->type == TOKEN_WORD)
		{
			word_count++;
			curr_token = curr_token->next;
		}
		if (curr_token->next == NULL)
			return ;
		if (curr_token->type == TOKEN_PIPE)
			curr_token = curr_token->next;
		if (curr_token->type != TOKEN_PIPE && curr_token->type != TOKEN_WORD)
			curr_token = curr_token->next->next;
		curr_args->args = malloc(sizeof(char *) * (word_count + 1));
		curr_args = curr_args->next;
	}
}

static void	create_args(t_token *token, t_args *args_head)
{
	int		i;
	t_args	*curr_args;
	t_token	*curr_token;

	curr_args = args_head;
	curr_token = token;
	while (curr_args != NULL)
	{
		i = 0;
		while (curr_token && curr_token->type == TOKEN_WORD)
		{
			curr_args->args[i] = curr_token->value;
			curr_token = curr_token->next;
			i++;
		}
		curr_args->args[i] = NULL;
		if (curr_token->type == TOKEN_PIPE)
			curr_token = curr_token->next;
		if (curr_token->type != TOKEN_PIPE && curr_token->type != TOKEN_WORD)
			curr_token = curr_token->next->next;
		curr_args = curr_args->next;
	}
}

int	parsing_tokens(t_token *token)
{
	t_args	*args_head;

	args_head = NULL;
	allocate_nodes(token, &args_head);
	alloc_args(token, args_head);
	create_args(token, args_head);
	print_list(args_head);
	return (0);
}