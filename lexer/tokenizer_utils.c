/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:33:29 by digulraj          #+#    #+#             */
/*   Updated: 2026/02/26 13:47:25 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	handle_quote_string(char *input, int i, char *buffer, int *j)
{
	char	quote_char;

	quote_char = input[i++];
	while (input[i] && input[i] != quote_char)
		buffer[(*j)++] = input[i++];
	if (input[i] != quote_char)
		return (-1);
	return (i + 1);
}

int	collect_word(char *input, int i, char *buffer, t_quote *quote_type)
{
	int		j;

	j = 0;
	*quote_type = NO_QUOTE;
	while (input[i] && !ft_isspace((input[i])) && !is_special_char(input[i]))
	{
		if (is_quote(input[i]))
		{
			if (*quote_type == NO_QUOTE)
			{
				if (input[i] == '\'')
					*quote_type = SINGLE_QUOTE;
				else if (input[i] == '"')
					*quote_type = DOUBLE_QUOTE;
			}
			i = handle_quote_string(input, i, buffer, &j);
			if (i == -1)
				return (-1);
			continue ;
		}
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
	char		buffer[TOKEN_BUFFER_SIZE];
	t_quote		quote_type;
	int			new_i;

	new_i = collect_word(input, i, buffer, &quote_type);
	if (new_i == -1)
	{
		*error = 1;
		return (-1);
	}
	if (buffer[0] != '\0')
		add_token(head, buffer, TOKEN_WORD, quote_type);
	return (new_i);
}
