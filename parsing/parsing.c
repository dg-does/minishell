/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:57:21 by fgreiff           #+#    #+#             */
/*   Updated: 2026/01/15 17:22:27 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

//alloc_args;
//traverse input first to count words until hitting pipe, redirect or end
//allocate args array for first argument
//repeat process until end of linked list

void	alloc_args(t_token *token, t_args *args)
{
	int	word_count;

	while (token->next)
	{
		word_count = 0;
		while (token->type == TOKEN_WORD)
		{
			word_count++;
			token = token->next;
		}
		if (token->type == TOKEN_PIPE)
			token = token->next;
		if (token->type != TOKEN_PIPE && token->type != TOKEN_WORD)
			token = token->next->next;
		args->args = malloc(sizeof(char *) * (word_count + 1));
		args = args->next;
	}
}

void create_args()
{
	//traverse until non word token
	//for every stint of word tokens every word goes into one array of args[][]
	//of the current args node
	//null terminate args[]
	//skip non word tokens and repeat above process until end of string
	
}

int	parsing_tokens(t_token *token)
{
	t_args	*args_head;

	args_head = NULL;
	allocate_nodes(&args_head, token);
	alloc_args(token, args_head);
}