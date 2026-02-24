/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid Date        by                   #+#    #+#             */
/*   Updated: 2026/02/24 16:44:41 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
# define MINISHELL_H
# include "structs.h"
# include "stdlib.h"
# include "lexer.h"
# include "parser.h"
# include "execution.h"
# include "built_in.h"
# include <signal.h>

extern volatile sig_atomic_t	g_sig;

void	reset_signals(void);
void	setup_signals(void);
void	array_free(char **str);
void	free_shell(t_minishell *shell);

#endif