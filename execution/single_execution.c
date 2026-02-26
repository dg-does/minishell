/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_execution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:17:04 by felixgreiff       #+#    #+#             */
/*   Updated: 2026/02/26 16:13:25 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "execution.h"

int	is_builtin(char *cmd)
{
	if (ft_strcmp(cmd, "cd") == 0)
		return (1);
	if (ft_strcmp(cmd, "echo") == 0)
		return (1);
	if (ft_strcmp(cmd, "env") == 0)
		return (1);
	if (ft_strcmp(cmd, "exit") == 0)
		return (1);
	if (ft_strcmp(cmd, "export") == 0)
		return (1);
	if (ft_strcmp(cmd, "pwd") == 0)
		return (1);
	if (ft_strcmp(cmd, "unset") == 0)
		return (1);
	else
		return (0);
}

static int	is_parent_builtin(char *cmd)
{
	if (ft_strcmp(cmd, "cd") == 0)
		return (1);
	else if (ft_strcmp(cmd, "exit") == 0)
		return (1);
	else if (ft_strcmp(cmd, "export") == 0)
		return (1);
	else if (ft_strcmp(cmd, "unset") == 0)
		return (1);
	else 
		return (0);
}

void	execute_child(t_minishell *shell, t_args *cmd)
{
	char	**argv;
	char	*path;

	write(2, "child: applying redirs\n", 23);
	if (cmd->redirs)
		apply_redirection(cmd->redirs);
	write(2, "child: building argv\n", 21);
	argv = args_to_argv(cmd->args);
	write(2, "child: checking builtin\n", 24);
	if (is_builtin(cmd->args->value))
	{
		shell->last_exit_status = execute_builtin(shell, argv);
		array_free(argv);
		exit(shell->last_exit_status);
	}
	write(2, "child: finding path\n", 20);
	path = parse_paths(shell, cmd);
	if (!path)
	{
		ft_putstr_fd("minishell: command not found\n", 2);
		exit(127);
	}
	write(2, "child: execve\n", 14);
	execve(path, argv, shell->env);
	perror("minishell: child");
	array_free(argv);
	free(path);
	exit(127); //correct this way or call exit function
}

void	execute_simple(t_minishell *shell, t_args *cmd)
{
	pid_t	pid1;

	if (!cmd->args || !cmd->args->value)
	{
		//some kind of exit code?
		return ;
	}
	if (is_parent_builtin(cmd->args->value))
		execute_parent(shell, cmd, &shell->last_exit_status);
	else
	{
		pid1 = fork();
		if (pid1 == 0)
		{
			reset_signals();
			execute_child(shell, cmd);
		}
		waitpid(pid1, &shell->last_exit_status, 0);
	}
	//free(argv);
}
