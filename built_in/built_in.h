/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:21:35 by fgreiff           #+#    #+#             */
/*   Updated: 2026/03/07 12:16:31 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_IN_H
# define BUILT_IN_H
# include "parser.h"
# include <errno.h>
# include <unistd.h>
# include "structs.h"

int		ft_cd(char **argv);
int		ft_echo(char **argv);
int		ft_env(char **envp);
int		ft_export(t_minishell *shell, char *export_value);
int		ft_pwd(void);
int		ft_unset(t_minishell *shell, char *unset_value);
int		ft_exit(char **argv, t_minishell *shell);

#endif