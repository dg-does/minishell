/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:44:12 by fgreiff           #+#    #+#             */
/*   Updated: 2026/01/23 16:01:12 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "lexer.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef enum e_redir_type
{
	REDIR_IN,
	REDIR_OUT,
	REDIR_APPEND,
	REDIR_HEREDOC
}	t_redir_type;

typedef struct s_args
{
	char			**args;
	struct s_args	*next;
}	t_args;

typedef struct s_redir
{
	char			*target;
	t_redir_type	redir;
	struct s_redir	*next;
}	t_redir;

//parser_utils.c
void	allocate_nodes_arg(t_token *token, t_args **args_head);
int		count_pipes(t_token *token);

//parser.c
int		parsing_tokens(t_token *token);

// expander.c
char	*expand_vars(char *str, int last_exit_status);

//debugging
void	print_list(t_args *args_head);

#endif