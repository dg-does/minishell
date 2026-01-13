/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 11:43:33 by digulraj          #+#    #+#             */
/*   Updated: 2026/01/13 14:48:20 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	add_token(t_token **head, char *value)
{
	t_token	*new_token;

	new_token = malloc(sizeof(t_token));
	if (!new_token)
		return (NULL);
	new_token->value = value;
	new_token->next = (NULL);
	return (new_token);
}


t_token	tokenize(char *input)
{
	t_token	*head;
	char	buffer[1024];
	int		i;
	int		j;
	int		in_quotes;

	*head = NULL;
	i = 0;
	in_quotes = 0;
	while (input[i])
	{
		while (input[i] && isspace(input[i]) && !in_quotes)
			i++;
		if (!input[i])
			break ;
		j = 0;
		if (input[i] == '"')
		{
			i++;
			in_quotes = 1;
			while (input[i] && input[i] != '"')
				buffer[j++] = input[i++];
			if (input[i] == '"')
				i++;
			in_quotes = 0;
			buffer[j] = '\0';
			add_token(&head, ft_strdup(buffer));
		}
		else if (is_special(input[i]))
		{
			buffer[0] = input[i];
			buffer[1] = '\0';
			add_token(&head, ft_strdup(buffer));
		}
		else
		{
			while (input[i] && !isspace(input[i]) && !is_special(input[i]))
				buffer[j++] = input[i++];
			buffer[j] = '\0';
			if (j > 0)
				add_token(&head, ft_strdup(buffer));
		}
	}
	return (head);
}
/*
Still need to:
* if there's no close quotation mark
* single quotes
* change the boolean flag in the struct to organise what type of token it is
* handle >> also in special characters, rn it's only 1 char
*implement isspace and is_special
*/



int	main(void)
{
	char	*input;
	t_token	*tokens;

	while (1)
	{
		input = readLine("minishell> ");
		if (strcmp(input, "exit") == 0)
		{
			free (input);
			break ;
		}
		tokens = tokenize(input);
		print_tokens(tokens);
		free(tokens);
		free(input);
	}
	return (0);
}
