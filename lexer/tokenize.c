/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 11:43:33 by digulraj          #+#    #+#             */
/*   Updated: 2026/01/13 15:32:45 by digulraj         ###   ########.fr       */
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

int	is_quote(char c)
{
	if (c == '"' || c == '\'')
		return (1);
	else
		return (0);
}

t_token	tokenize(char *input)
{
	t_token	*head;
	char	buffer[1024];
	int		i;
	int		j;
	char	quote;

	*head = NULL;
	i = 0;
	while (input[i])
	{
		while (input[i] && isspace(input[i]))
			i++;
		if (!input[i])
			break ;
		j = 0;
		if (is_quote(input[i]))
		{
			quote = input[i++];
			while (input[i] && !is_quote(input[i]))
				buffer[j++] = input[i++];
			if (input[i] == quote)
				i++;
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
			while (input[i] && !isspace(input[i]) && !is_special(input[i]) && 
				!is_quote(input[i]))
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
* change the boolean flag in the struct to organise what type of token it is
* handle ">> also in special characters, rn it's only 1 char. bash handles >> so we need to save it as a token
* handle escape characters using '/' the way bash does
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
