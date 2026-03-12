/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signalling.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 11:41:31 by digulraj          #+#    #+#             */
/*   Updated: 2026/03/12 13:06:05 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

volatile sig_atomic_t	g_sig = 0;

// Handler for SIGINT (Ctrl+C) - display newline and new prompt
void	handle_sigint_parent(int sig)
{
	g_sig = sig;
	write(STDOUT_FILENO, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	handle_sigint_child(int sig)
{
	g_sig = sig;
	write(STDOUT_FILENO, "\n", 1);
}
// Ctrl+\ (SIGQUIT) does nothing at the prompt
// Handler for Crtl+D is in main because it exits the shell

// Setup signal handlers for interactive mode
void	setup_signals(void)
{
	struct sigaction	sa;

	sa.sa_handler = handle_sigint_parent;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sa, NULL);
	sa.sa_handler = SIG_IGN;
	sa.sa_flags = 0;
	sigaction(SIGQUIT, &sa, NULL);
}

// Reset signals to default (to be used in child processes)
void	reset_signals(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	signal(SIGPIPE, SIG_DFL);
}
