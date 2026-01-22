/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:44:12 by fgreiff           #+#    #+#             */
/*   Updated: 2026/01/20 15:16:52 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "lexer.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_args
{
	char			**args;
	char			*path;
	struct s_args	*next;
}	t_args;

//parser_utils.c
void	allocate_nodes(t_token *token, t_args **args_head);
int		count_pipes(t_token *token);

//parser.c
int		parsing_tokens(t_token *token, char **envp);
void	parse_paths(t_args *args_head, char **envp);

//debugging
void	print_list(t_args *args_head);

#endif