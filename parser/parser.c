/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:57:21 by fgreiff           #+#    #+#             */
/*   Updated: 2026/01/20 14:50:26 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

//alloc_args;
//traverse input first to count words until hitting pipe, redirect or end
//allocate args array for first argument
//repeat process until end of linked list

static void	free_args(t_args *args_head)
{
	t_args	*curr;

	curr = args_head;
	while (curr)
	{
		if (curr->args)
			free(curr->args);
		curr = curr->next;
	}
}

static t_token	*skip_separators(t_token *curr_token)
{
	if (curr_token == NULL)
		return (NULL);
	if (curr_token->type == TOKEN_PIPE)
		curr_token = curr_token->next;
	else if (curr_token->type != TOKEN_WORD)
	{
		if (curr_token->next == NULL)
			return (NULL);
		return (curr_token->next->next);
	}
	return (curr_token);
}


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
		curr_args->args = malloc(sizeof(char *) * (word_count + 1));
		if (!curr_args->args)
		{
			free_args(args_head);
			perror("malloc fail");
			return ;
		}
		curr_args = curr_args->next;
		curr_token = skip_separators(curr_token);
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
			curr_args->args[i++] = curr_token->value;
			curr_token = curr_token->next;
		}
		curr_args->args[i] = NULL;
		curr_args = curr_args->next;
		curr_token = skip_separators(curr_token);
	}
}

int	parsing_tokens(t_token *token, char **envp)
{
	t_args	*args_head;

	args_head = NULL;
	allocate_nodes(token, &args_head);
	alloc_args(token, args_head);
	create_args(token, args_head);
	parse_paths(args_head, envp);
	print_list(args_head);
	return (0);
}
