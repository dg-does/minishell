/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:33:29 by digulraj          #+#    #+#             */
/*   Updated: 2026/01/14 17:36:50 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

// *j is the pointer to the current index of buffer (word being built)
int	handle_quote_string(char *input, int i, char *buffer, int *j)
{
	char	quote_char;

	quote_char = input[i++];
	while (input[i] && input[i] != quote_char)
	{
		if (quote_char == '"' && input[i] == '$')
		{
			//TODO: Add $VAR expansion logic
			buffer[(*j)++] = input[i++];
		}
		else
			buffer[(*j)++] = input[i++];
	}
	if (input[i] != quote_char)
		return (-1);
	return (i + 1);
}

int	collect_word(char *input, int i, char *buffer, int *has_quotes)
{
	int	j;
	int	new_i;

	j = 0;
	has_quotes = 0;
	while (input[i] && !isspace((input[i])) && !is_special_char(input[i]))
	{
		if (is_quote(input[i]))
		{
			*has_quotes = 1;
			new_i = handle_quote_string(input, i, buffer, &j);
			if (new_i == -1)
				return (-1);
			i = new_i;
		}
		else
			buffer[j++] = input[i++];
	}
	buffer[j] = '\0';
	return (i);
}

int	get_operator_type(char *input, int i, t_type *type)
{
	if (input[i] == '>' && input[i + 1] == '>')
		return (*type = TOKEN_REDIRECT_APPEND, 2);
	else if (input[i] == '<' && input[i + 1] == '<')
		return (*type = TOKEN_HEREDOC, 2);
	else if (input[i] == '>')
		return (*type = TOKEN_REDIRECT_OUT, 1);
	else if (input[i] == '<')
		return (*type = TOKEN_REDIRECT_IN, 1);
	else if (input[i] == '|')
		return (*type = TOKEN_PIPE, 1);
	return (0);
}

int	process_operator(char *input, int i, t_token **head)
{
	t_type	type;
	int		op_len;
	int		j;
	char	buffer[3];

	op_len = get_operator_type(input, i, &type);
	if (op_len == 0)
		return (i);
	j = 0;
	while (j < op_len)
		buffer[j++] = input[i++];
	buffer[j] = '\0';
	add_token(head, buffer, type, 0);
	return (i);
}

int	process_word(char *input, int i, t_token **head, int *error)
{
	char	buffer[TOKEN_BUFFER_SIZE];
	int		has_quotes;
	int		new_i;

	new_i = collect_word(input, i, buffer, &has_quotes);
	if (new_i == 1)
	{
		*error = 1;
		return (-1);
	}
	if (buffer[0] != '\0')
		add_token(head, buffer, TOKEN_WORD, has_quotes);
	return (new_i);
}
