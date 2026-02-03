/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:44:12 by fgreiff           #+#    #+#             */
/*   Updated: 2026/02/03 16:32:33 by digulraj         ###   ########.fr       */
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

typedef struct s_redir
{
	char			*target;
	t_redir_type	redir;
	struct s_redir	*next;
}	t_redir;

typedef struct s_arg
{
	char			*value;
	t_quote			quote_type;
	struct s_arg	*next;
}	t_arg;

typedef struct s_args
{
	t_arg			*args;
	t_redir			*redirs;
	struct s_args	*next;
}	t_args;

//parser_utils.c
void			allocate_nodes_arg(t_token *token, t_args **args_head);
int				count_pipes(t_token *token);
int				is_redirection(t_type type);
t_redir_type	token_to_redir_type(t_type type);

//parser.c
t_args			*parsing_tokens(t_token *token);
void			parse_redirections(t_token	**token, t_args *cmd);
void			add_arg(t_args *cmd, char *value, t_quote quote_type);
// expander
char			*expand_vars(char *str, int last_exit_status);
void			expand_commands(t_args *cmds, int last_exit_status);
char			**args_to_argv(t_arg *args);
//debugging
void			print_list(t_args *args_head);

#endif