/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 10:14:16 by fgreiff           #+#    #+#             */
/*   Updated: 2026/03/12 16:18:24 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "execution.h"

static void	path_error(t_minishell *shell, char *cmd, char *msg, int code)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(msg, 2);
	child_exit(shell, code);
}

void	check_direct_path(t_minishell *shell, char *cmd)
{
	struct stat	st;

	if (stat(cmd, &st) != 0)
	{
		if (errno == ENOTDIR)
			path_error(shell, cmd, ": Not a directory\n", 126);
		path_error(shell, cmd, ": No such file or directory\n", 127);
	}
	if (S_ISDIR(st.st_mode))
		path_error(shell, cmd, ": Is a directory\n", 126);
	path_error(shell, cmd, ": Permission denied\n", 126);
}

void	check_path_erorr(t_minishell *shell, char *cmd)
{
	if (cmd[0] == '/' || (cmd[0] == '.' && cmd[1] == '/'))
	{
		check_direct_path(shell, cmd);
		return ;
	}
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": command not found\n", 2);
	child_exit(shell, 127);
}

void	child_exit(t_minishell *shell, int status)
{
	free_shell(shell);
	gc_free_all();
	rl_clear_history();
	exit(status);
}
