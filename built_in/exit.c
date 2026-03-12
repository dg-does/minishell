/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 16:37:06 by felixgreiff       #+#    #+#             */
/*   Updated: 2026/03/12 15:37:10 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"
#include "structs.h"
#include "minishell.h"

static int	is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	exit_error_numeric(char **args, t_minishell *shell)
{
	ft_putstr_fd("exit: ", STDERR_FILENO);
	ft_putstr_fd(args[1], STDERR_FILENO);
	ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
	gc_free_all();
	rl_clear_history();
	free_shell(shell);
	exit(2);
}

static int	count_args(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
		i++;
	return (i);
}

static int	normalize_code(int code)
{
	if (code < 0)
		return (256 + (code % 256));
	return (code % 256);
}

int	ft_exit(char **argv, t_minishell *shell)
{
	int	code;
	int	arg_count;

	arg_count = count_args(argv);
	ft_printf("exit\n");
	if (arg_count == 1)
	{
		code = shell->last_exit_status;
		gc_free_all();
		rl_clear_history();
		free_shell(shell);
		exit(code);
	}
	if (arg_count > 2)
	{
		ft_putstr_fd("exit: too many arguments\n", STDERR_FILENO);
		return (1);
	}
	if (!is_numeric(argv[1]))
		exit_error_numeric(argv, shell);
	code = normalize_code(ft_atoi(argv[1]));
	gc_free_all();
	rl_clear_history();
	free_shell(shell);
	exit(code);
}
