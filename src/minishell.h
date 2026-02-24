/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2026/02/24 16:10:01 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
# define MINISHELL_H
# include "structs.h"
# include "stdlib.h"

//Global variable used for passing signals
extern volatile sig_atomic_t	g_sig;

void	reset_signals(void);
void	setup_signals(void);
void	array_free(char **str);
void	free_shell(t_minishell *shell);

#endif