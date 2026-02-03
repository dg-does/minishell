/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:19:16 by digulraj          #+#    #+#             */
/*   Updated: 2026/02/03 12:48:20 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "parser.h"
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

int	main(void)
{
	int		error;
	t_token	*tokens;
	char	*input;
	t_args	*cmds;
	int		last_exit_status;

	last_exit_status = 0;
	while (1)
	{
		input = readline("minishell> ");
		if (!input || ft_strncmp(input, "exit", 4) == 0)
		{
			free (input);
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
			printf("ERROR: Close your quotes!!\n");
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
		expand_commands(cmds, last_exit_status);
		print_list(cmds);
		free_tokens(tokens);
		free(input);
	}
	return (last_exit_status);
}

