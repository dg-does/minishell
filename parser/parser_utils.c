/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 16:30:16 by fgreiff           #+#    #+#             */
/*   Updated: 2026/01/23 16:21:47 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

//missing
//syntax check
//free function

void	allocate_nodes_arg(t_token *token, t_args **args_head)
{
	int		num_cmnds;
	t_args	*current_args;
	int		i;

	i = 0;
	num_cmnds = count_pipes(token);
	*args_head = malloc(sizeof(t_args));
	if (!args_head)
		return ;
	(*args_head)->args = NULL;
	current_args = *args_head;
	while (i < num_cmnds)
	{
		current_args->next = malloc(sizeof(t_args));
		if (!current_args->next)
			return ;
		current_args = current_args->next;
		current_args->args = NULL;
		current_args->next = NULL;
		i++;
	}
}

void	allocate_nodes_redir(t_token *token, t_redir **redir_head)
{
	int		num_cmnds;
	t_redir	*current_redir;
	int		i;

	i = 0;
	num_cmnds = count_pipes(token);
	*redir_head = malloc(sizeof(t_args));
	if (!redir_head)
		return ;
	(*redir_head)->target = NULL;
	current_redir = *redir_head;
	while (i < num_cmnds)
	{
		current_redir->next = malloc(sizeof(t_args));
		if (!current_redir->next)
			return ;
		current_redir = current_redir->next;
		current_redir->target = NULL;
		current_redir->next = NULL;
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
	printf("\n===ARGS after parsing & expansion ===\n");
	while (current->next != NULL)
	{
		i = 0;
		while (current->args[i])
		{
			printf("[%d] %s ", i, expand_vars(current->args[i], 0));
			i++;
		}
		printf("\n");
		current = current->next;
	}
}
