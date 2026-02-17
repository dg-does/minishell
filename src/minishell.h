/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:45:38 by felixgreiff       #+#    #+#             */
/*   Updated: 2026/02/17 10:22:24 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "parser.h"
# include "lexer.h"
# include "built_in.h"

typedef struct s_minishell
{
    char    **env;
    int     last_status;
}   t_minishell;

#endif