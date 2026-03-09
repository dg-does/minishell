/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:19:16 by digulraj          #+#    #+#             */
/*   Updated: 2026/03/09 15:46:39 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_shell(t_minishell *shell)
{
	int	i;

	if (!shell)
		return ;
	if (shell->env)
	{
		i = 0;
		while (shell->env[i])
		{
			free(shell->env[i]);
			i++;
		}
		free(shell->env);
	}
	free(shell);
}

t_minishell	*init_shell(char **envp)
{
	t_minishell	*shell;
	int			i;

	shell = malloc(sizeof(t_minishell));
	if (!shell)
		return (NULL);
	i = 0;
	while (envp[i])
		i++;
	shell->env = malloc(sizeof(char *) * (i + 1));
	if (!shell->env)
		return (free(shell), NULL);
	i = 0;
	while (envp[i])
	{
		shell->env[i] = ft_strdup(envp[i]);
		if (!shell->env[i])
			return (free(shell), NULL);
		i++;
	}
	shell->env[i] = NULL;
	shell->last_exit_status = 0;
	return (shell);
}

static void	exit_shell(t_minishell *shell)
{
	int	exit_status;

	ft_printf("exit\n");
	exit_status = shell->last_exit_status;
	free_shell(shell);
	exit(exit_status);
}

static void	loop_shell(t_minishell *shell, char *input)
{
	int			error;
	t_token		*tokens;
	t_args		*cmds;

	tokens = tokenize(input, &error);
	if (error)
	{
		ft_printf("ERROR: Unclosed quote\n");
		return ;
	}
	cmds = parsing_tokens(tokens);
	if (!cmds)
		return ;
	g_sig = 1;
	execute_cmds(shell, cmds);
	g_sig = 0;
	gc_free_all();
}

int	main(int argc, char **argv, char **envp)
{
	char		*input;
	t_minishell	*shell;

	(void)argc;
	(void)argv;
	shell = init_shell(envp);
	if (!shell)
		return (1);
	setup_signals();
	while (1)
	{
		g_sig = 0;
		input = readline("minishell> ");
		if (!input)
		{
			free(input);
			exit_shell(shell);
		}
		if (input[0] != '\0')
		{
			add_history(input);
			loop_shell(shell, input);
		}
		free(input);
	}
}
