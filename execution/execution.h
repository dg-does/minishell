/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:24:11 by felixgreiff       #+#    #+#             */
/*   Updated: 2026/02/24 12:48:28 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H
# include <fcntl.h>
# include <sys/wait.h>
# include <unistd.h>
# include "structs.h"

//execute parent
int		execute_builtin(t_minishell *shell, char **argv);
void	execute_parent(t_minishell *shell, t_args *cmd, int *last_exit_status);

//execution utils
char	**args_to_argv(t_arg *args);

//execution main file
void	execute_cmds(t_minishell *shell, t_args *cmds, int *last_exit_status, char **envp);

//handle redirections
void	apply_redirection(t_redir *redirs);
void	redirect_in(t_redir *redirs);
void	redirect_out(t_redir *redirs);
void	redirect_append(t_redir *redirs);

//single cmd execution
int		is_builtin(char *cmd);
void	execute_simple(t_minishell *shell, t_args *cmd, int *last_exit_status, char **envp);


#endif