/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 16:30:16 by fgreiff           #+#    #+#             */
/*   Updated: 2026/01/15 17:14:35 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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

	while (token->next)
	{
		if (token->type == TOKEN_PIPE)
			pipe_counter++;
		token = token->next;
	}
	return (pipe_counter + 1);
}