/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixgreiff <felixgreiff@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:45:34 by digulraj          #+#    #+#             */
/*   Updated: 2026/02/19 15:18:20 by felixgreiff      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**args_to_argv(t_arg *args)
{
	t_arg	*current;
	char	**argv;
	int		i;

	i = 0;
	current = args;
	while (current)
	{
		i++;
		current = current->next;
	}
	argv = malloc(sizeof(char *) * (i + 1));
	if (!argv)
		return (NULL);
	i = 0;
	current = args;
	while (current)
	{
		argv[i++] = current->value;
		current = current->next;
	}
	argv[i] = NULL;
	return (argv);
}

void	execute_cmds(t_args *cmds, int *last_exit_status, char **envp)
{
	if (!cmds)
		return ;
	if (!cmds->next)
		execute_simple(cmds, last_exit_status, envp);
	else
		execute_complex(cmds, last_exit_status, envp);
}

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
}

int	execute_builtin(char **argv, char **envp)
{
	if (ft_strcmp(cmd, "cd") == 0)
		return (ft_cd(argv));
	if (ft_strcmp(cmd, "echo") == 0)
		return (ft_echo(argv));
	if (ft_strcmp(cmd, "env") == 0)
		return (ft_env(envp));
	if (ft_strcmp(cmd, "exit") == 0)
		return (ft_exit(argv));
	if (ft_strcmp(cmd, "export") == 0)
		return (ft_export(argv, envp));
	if (ft_strcmp(cmd, "pwd") == 0)
		return (ft_pwd());
	if (ft_strcmp(cmd, "unset") == 0)
		return (ft_unset(argv, envp));
	return (1);
}

void	execute_simple(t_args *cmd, int *last_exit_status, char **envp)
{
	char	**argv;

	argv = args_to_argv(cmd->args);
	if (!argv || !argv[0])
	{
		free(argv);
		return ;
	}
	if (is_builtin(argv[0]))
	{
		*last_exit_status = execute_bulitin(argv, envp);
		free(argv);
		return ;
	}
	//execute_other?
	free(argv);
}
