/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:44:12 by fgreiff           #+#    #+#             */
/*   Updated: 2026/01/16 12:02:51 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include "lexer.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_args
{
	char			**args;
	struct s_args	*next;
}	t_args;

//Parsing Utils
void	allocate_nodes(t_token *token, t_args **args_head);
int		count_pipes(t_token *token);

//main Parsing part
int		parsing_tokens(t_token *token);

//debugging
void	print_list(t_args *args_head);

#endif