/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:21:35 by fgreiff           #+#    #+#             */
/*   Updated: 2026/02/17 10:33:00 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H
# include "parser.h"
# include "errno.h"

int		cd(const char *path);
int		echo(char **argv);
int		env(char **envp);
int		export(t_minishell *shell, char *export_value);
int		pwd(void);
int		unset(t_minishell *shell, char *unset_value);
void	exit(t_minishell *shell);

#endif