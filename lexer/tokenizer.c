/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 11:43:33 by digulraj          #+#    #+#             */
/*   Updated: 2026/01/16 15:37:58 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	add_token(t_token **head, char *value, t_type type, int has_quotes)
{
	t_token	*new_token;
	t_token	*current;

	new_token = malloc(sizeof(t_token));
	if (!new_token)
		return ;
	new_token->value = ft_strdup(value);
	if (!new_token->value)
	{
		free(new_token);
		return ;
	}
	new_token->type = type;
	new_token->has_quotes = has_quotes;
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

void	free_tokens(t_token *head)
{
	t_token	*current;

	current = head;
	while (current)
	{
		free(current->value);
		free(current);
		current = current->next;
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
				return (free_tokens(head), NULL);
			i = j;
		}
	}
	return (head);
}
// Printing functions just for testing:

const char	*token_type(t_type type)
{
	if (type == TOKEN_WORD)
		return ("WORD");
	if (type == TOKEN_PIPE)
		return ("PIPE");
	if (type == TOKEN_REDIRECT_IN)
		return ("REDIR_IN");
	if (type == TOKEN_REDIRECT_OUT)
		return ("REDIR_OUT");
	if (type == TOKEN_REDIRECT_APPEND)
		return ("REDIR_APPEND");
	if (type == TOKEN_HEREDOC)
		return ("HEREDOC");
	return ("UNKNOWN TYPE");
}

void	print_tokens(t_token *head)
{
	t_token	*current;
	int		i;

	current = head;
	i = 0;
	printf("\n--- TOKENS before parsing ---\n");
	while (current)
	{
		printf("[%d] %s | %s | In quotes: %s\n", 
			i++, current->value, token_type(current->type), 
			current->has_quotes? "Yes" : "No");
		current = current->next;
	}
}
