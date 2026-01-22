/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 11:44:07 by digulraj          #+#    #+#             */
/*   Updated: 2026/01/22 11:27:39 by fgreiff          ###   ########.fr       */
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

typedef struct s_token
{
	char			*value;
	t_type	type;
	int				has_quotes;
	struct s_token	*next;
}	t_token;

// need to figure out which ones can be static and not needed here

//lexer_utils.c
int	is_quote(char c);
int	is_special_char(char c);

//libft.c
int	ft_isalnum(int c);
int	ft_strcmp(const char *s1, const char *s2);

//tokenizer_utils.c
int	handle_quote_string(char *input, int i, char *buffer, int *j);
int	collect_word(char *input, int i, char *buffer, int *has_quotes);
int	get_operator_type(char *input, int i, t_type *type);
int	process_operator(char *input, int i, t_token **head);
int	process_word(char *input, int i, t_token **head, int *error);

//tokenizer.c
void		add_token(t_token **head, char *value, t_type type, int has_quotes);
void		free_tokens(t_token *head);
void		print_tokens(t_token *head);
t_token		*tokenize(char *input, int *error);
const char	*token_type(t_type type);
#endif