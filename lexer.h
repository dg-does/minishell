/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 11:44:07 by digulraj          #+#    #+#             */
/*   Updated: 2026/01/13 15:30:56 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# include <readline.h>


typedef struct s_token
{
	char			*value;
	struct s_token	*next;
	int				word;
	int				redirect;
	int				s_quotes;
	int				d_quotes;
	int				pipe;
	int				expand;
} t_token;

#endif