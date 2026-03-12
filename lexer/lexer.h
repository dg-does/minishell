/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 11:44:07 by digulraj          #+#    #+#             */
/*   Updated: 2026/03/12 16:33:06 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include "libft.h"
# include "structs.h"
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

//lexer_utils.c
int			is_quote(char c);
int			is_special_char(char c);

//tokenizer_utils.c
int			handle_quote_string(char *input, int i, char *buffer, int *j);
int			collect_word(char *input, int i, char *buffer, t_quote *quote_type);
int			get_operator_type(char *input, int i, t_type *type);
int			process_operator(char *input, int i, t_token **head);
int			process_word(char *input, int i, t_token **head, int *error);

//tokenizer.c
void		add_token(t_token **head, char *value, t_type type, t_quote quote);
void		free_tokens(t_token *head);
void		print_tokens(t_token *head);
t_token		*tokenize(char *input, int *error);
const char	*token_type(t_type type);

#endif