/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:45:38 by felixgreiff       #+#    #+#             */
/*   Updated: 2026/02/24 13:45:59 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "parser.h"
# include "lexer.h"
# include "built_in.h"
# include "execution.h"
# include <signal.h>

typedef struct s_minishell
{
	char	**env;
	int		last_exit_status;
}	t_minishell;

//Global variable used for passing signals
extern volatile sig_atomic_t	g_sig;

void	reset_signals(void);
void	setup_signals(void);
void	array_free(char **str);

#endif