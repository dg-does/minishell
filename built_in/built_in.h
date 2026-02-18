/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:21:35 by fgreiff           #+#    #+#             */
/*   Updated: 2026/02/18 19:29:59 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H
# include "parser.h"
# include <errno.h>
# include <unistd.h>

typedef struct s_minishell t_minishell;

int		ft_cd(char **argv);
int		ft_echo(char **argv);
int		ft_env(char **envp);
int		ft_export(t_minishell *shell, char *export_value);
int		ft_pwd(void);
int		ft_unset(t_minishell *shell, char *unset_value);
void	ft_exit(t_minishell *shell);

#endif