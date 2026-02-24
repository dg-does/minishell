/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:19:16 by digulraj          #+#    #+#             */
/*   Updated: 2026/02/24 13:48:50 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "parser.h"
#include "minishell.h"
/*
int	main(void)
{
	char	*tests[] = {
		"echo hello world",
        "echo \"hello world\"",
        "echo 'hello world'",
        "cat file.txt > output.txt",
        "cat file.txt >> output.txt",
        "cat << EOF",
        "grep pattern < input.txt | sort",
        "echo \"$USER is logged in\"",
        "echo '$USER will not expand'",
        "echo \"Price is $5\"",
        "echo hello\"world\"test",
        "echo 'single'\"double\"mixed",
        "ls -la | grep txt | wc -l",
        "echo \"unclosed",
        NULL
	};
	int		i;
	int		error;
	t_token	*tokens;

	i = 0;
	while (tests[i])
	{
		printf("\n\nInput: %s\n", tests[i]);
		tokens = tokenize(tests[i], &error);
		if (error)
			printf("ERROR: Close your quotes!!\n");
		else
		{
			print_tokens(tokens);
			parsing_tokens(tokens);
			free_tokens(tokens);
		}
		i++;
	}
	return (0);
}
//*/

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

t_minishell *init_shell(char **envp)
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
	{
		free(shell);
		return (NULL);
	}
	i = 0;
	while (envp[i])
	{
		shell->env[i] = ft_strdup(envp[i]);
		if (!shell->env[i])
		{
			while (--i >= 0)
				free(shell->env[i]);
			free_shell(shell);
			return (NULL);
		}
		i++;
	}
	shell->env[i] = NULL;
	shell->last_exit_status = 0;
	return (shell);
}

int	main(int argc, char **argv, char **envp)
{
	int			error;
	t_token		*tokens;
	char		*input;
	t_args		*cmds;
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
		if (!input || ft_strncmp(input, "exit", 4) == 0)
		{
			printf("exit\n");
			free(input);
			break ;
		}
		if (input[0] == '\0')
		{
			free(input);
			continue ;
		}
		add_history(input);
		tokens = tokenize(input, &error);
		if (error)
		{
			printf("ERROR: Unclosed quote\n");
			free(input);
			continue ;
		}
		print_tokens(tokens);
		cmds = parsing_tokens(tokens);
		if (!cmds)
		{
			free_tokens(tokens);
			free(input);
			continue ;
		}
		expand_commands(cmds, shell);
		print_list(cmds);
		g_sig = 1;
		execute_commands(cmds, shell);
		g_sig = 0;
		free_tokens(tokens);
		//free cmds?
		free(input);
	}
	free_shell(shell);
	return (shell->last_exit_status);
}

