/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:19:16 by digulraj          #+#    #+#             */
/*   Updated: 2026/01/14 17:37:26 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

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
		printf("Input: %s\n", tests[i]);
		tokens = tokenize(tests[i], & error);
		if (error)
			printf("ERROR: Close your quotes!!\n");
		else
		{
			print_tokens(tokens);
			free_tokens(tokens);
		}
		i++;
	}
	return (0);
}
/*
		input = readLine("minishell> ");
		if (strcmp(input, "exit") == 0)
		{
			free (input);
			break ;
		}
		tokens = tokenize(input);
		print_tokens(tokens);
		free(tokens);
		free(input);
*/