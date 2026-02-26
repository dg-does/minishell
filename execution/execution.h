/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:24:11 by felixgreiff       #+#    #+#             */
/*   Updated: 2026/02/26 16:26:38 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H
# include <fcntl.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdio.h>
# include "structs.h"
# include "libft.h"

//execute parent
int		execute_builtin(t_minishell *shell, char **argv);
void	execute_parent(t_minishell *shell, t_args *cmd, int *last_exit_status);

//execution utils
char	**args_to_argv(t_arg *args);
void	collect_status(t_minishell *shell, pid_t *pids, int cmd_count);
void	close_all_pipes(int **pipes, int count);
int		count_cmds(t_args *cmds);

//execution main file
void	execute_cmds(t_minishell *shell, t_args *cmds);

//handle redirections
void	apply_redirection(t_redir *redirs);
void	redirect_in(t_redir *redirs);
void	redirect_out(t_redir *redirs);
void	redirect_append(t_redir *redirs);
void	redirect_heredoc(t_redir *redirs);


//here_doc
int		exec_heredoc(t_minishell *shell, char *limiter, int expand);
void	prepare_heredocs(t_minishell *shell, t_args *cmds);

//single cmd execution
int		is_builtin(char *cmd);
void	execute_simple(t_minishell *shell, t_args *cmd);

//multiple-cmds
void	execute_multiple(t_minishell *shell, t_args *cmds, int cmd_count);
int		**create_pipes(int count);

//path parsing
char	*parse_paths(t_minishell *shell, t_args *cmd);

//child execution
void	execute_child(t_minishell *shell, t_args *cmd);

#endif