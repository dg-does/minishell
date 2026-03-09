/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_child_exec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 09:05:07 by fgreiff           #+#    #+#             */
/*   Updated: 2026/03/09 09:08:54 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "execution.h"

static void	check_direct_path(char *cmd)
{
	struct stat	st;

	if (stat(cmd, &st) != 0)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		exit(127);
	}
	if (S_ISDIR(st.st_mode))
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": Is a directory\n", 2);
		exit(126);
	}
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": Permission denied\n", 2);
	exit(126);
}

static void	check_path_erorr(char *cmd)
{
	if (cmd[0] == '/' || (cmd[0] == '.' && cmd[1] == '/'))
		check_direct_path(cmd);
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": command not found\n", 2);
	exit(127);
}

void	execute_child(t_minishell *shell, t_args *cmd)
{
	char	**argv;
	char	*path;

	if (cmd->redirs && apply_redirection(cmd->redirs))
		exit (1);
	argv = args_to_argv(cmd->args);
	if (is_builtin(cmd->args->value))
	{
		shell->last_exit_status = execute_builtin(shell, argv);
		array_free(argv);
		exit(shell->last_exit_status);
	}
	path = parse_paths(shell, cmd);
	if (!path)
		check_path_erorr(argv[0]);
	execve(path, argv, shell->env);
	perror("minishell: child");
	array_free(argv);
	free(path);
}
