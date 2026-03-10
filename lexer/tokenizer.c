/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 11:43:33 by digulraj          #+#    #+#             */
/*   Updated: 2026/03/10 12:17:43 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	add_token(t_token **head, char *value, t_type type, t_quote quote_type)
{
	t_token	*new_token;
	t_token	*current;

	new_token = gc_malloc(sizeof(t_token));
	if (!new_token)
		return ;
	new_token->value = gc_strdup(value);
	if (!new_token->value)
		return ;
	new_token->type = type;
	new_token->quote_type = quote_type;
	new_token->next = NULL;
	if (*head == NULL)
		*head = new_token;
	else
	{
		current = *head;
		while (current->next)
			current = current->next;
		current->next = new_token;
	}
}

t_token	*tokenize(char *input, int *error)
{
	t_token	*head;
	int		i;
	int		j;

	head = NULL;
	i = 0;
	*error = 0;
	while (input[i])
	{
		while (input[i] && ft_isspace(input[i]))
			i++;
		if (!input[i])
			break ;
		if (is_special_char(input[i]))
			i = process_operator(input, i, &head);
		else
		{
			j = process_word(input, i, &head, error);
			if (j == -1)
				return (NULL);
			i = j;
		}
	}
	return (head);
}
