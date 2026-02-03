/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 11:44:07 by digulraj          #+#    #+#             */
/*   Updated: 2026/02/03 12:24:32 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

# define TOKEN_BUFFER_SIZE 4096

typedef enum e_token_type
{
	TOKEN_WORD,
	TOKEN_PIPE,
	TOKEN_REDIRECT_IN,
	TOKEN_REDIRECT_OUT,
	TOKEN_REDIRECT_APPEND,
	TOKEN_HEREDOC
}	t_type;

typedef enum e_quote_type
{
	NO_QUOTE,
	SINGLE_QUOTE,
	DOUBLE_QUOTE
}	t_quote;

typedef struct s_token
{
	char			*value;
	t_type			type;
	t_quote			quote_type;
	struct s_token	*next;
}	t_token;

// need to figure out which ones can be static and not needed here

//lexer_utils.c
int	is_quote(char c);
int	is_special_char(char c);

//tokenizer_utils.c
int	handle_quote_string(char *input, int i, char *buffer, int *j);
int	collect_word(char *input, int i, char *buffer, t_quote *quote_type);
int	get_operator_type(char *input, int i, t_type *type);
int	process_operator(char *input, int i, t_token **head);
int	process_word(char *input, int i, t_token **head, int *error);

//tokenizer.c
void		add_token(t_token **head, char *value, t_type type, t_quote quote_type);
void		free_tokens(t_token *head);
void		print_tokens(t_token *head);
t_token		*tokenize(char *input, int *error);
const char	*token_type(t_type type);

#endif