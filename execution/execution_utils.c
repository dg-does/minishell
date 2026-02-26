/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:23:41 by felixgreiff       #+#    #+#             */
/*   Updated: 2026/02/26 13:28:42 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "execution.h"

char	**args_to_argv(t_arg *args)
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

int	count_cmds(t_args *cmds)
{
	int	count;

	count = 0;
	while (cmds)
	{
		count++;
		cmds = cmds->next;
	}
	return (count);
}

void	close_all_pipes(int **pipes, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		close(pipes[i][0]);
		close(pipes[i][1]);
		i++;
	}
}

void	collect_status(t_minishell *shell, pid_t *pids, int cmd_count)
{
	int	i;
	int	status;

	i = 0;
	while (i < cmd_count)
	{
		waitpid(pids[i], &status, 0);
		if (i == cmd_count - 1 && WIFEXITED(status))
			shell->last_exit_status = WEXITSTATUS(status);
		i++;
	}
	free(pids);
}
