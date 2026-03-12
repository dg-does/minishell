/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:44:12 by fgreiff           #+#    #+#             */
/*   Updated: 2026/03/12 16:34:00 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "structs.h"
# include "libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_minishell	t_minishell;

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
char			*expand_vars(char *str, t_minishell *shell);
void			expand_commands(t_args *cmds, t_minishell *shell);

#endif