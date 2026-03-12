/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:19:16 by digulraj          #+#    #+#             */
/*   Updated: 2026/03/12 14:37:52 by fgreiff          ###   ########.fr       */
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
void	set_heredoc_signals(void);
void	handle_sigint_child(int sig);
void	handle_sigint_parent(int sig);
void	handle_sigint_heredoc(int sig);
void	array_free(char **str);
void	free_shell(t_minishell *shell);
void	gc_free(void *ptr);

#endif