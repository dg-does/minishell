/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 16:30:16 by fgreiff           #+#    #+#             */
/*   Updated: 2026/01/16 14:27:19 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

//missing
//syntax check
//free function

void	allocate_nodes(t_token *token, t_args **args_head)
{
	int		num_cmnds;
	t_args	*current;
	int		i;

	i = 0;
	num_cmnds = count_pipes(token);
	*args_head = malloc(sizeof(t_args));
	if (!args_head)
		return ;
	(*args_head)->args = NULL;
	(*args_head)->next = NULL;
	current = *args_head;
	while (i < num_cmnds)
	{
		current->next = malloc(sizeof(t_args));
		if (!current->next)
			return ;
		current = current->next;
		current->args = NULL;
		current->next = NULL;
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
	return (pipe_counter + 1);
}

void	print_list(t_args *args_head)
{
	t_args	*current;
	int		i;

	current = args_head;
	while (current != NULL)
	{
		i = 0;
		while (current->args[i])
		{
			printf("%s ", current->args[i]);
			i++;
		}
		current = current->next;
	}
}