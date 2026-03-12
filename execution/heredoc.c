/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 14:30:25 by fgreiff           #+#    #+#             */
/*   Updated: 2026/03/12 16:04:04 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "execution.h"
#include "minishell.h"
#include "libft.h"

void	prepare_heredocs(t_minishell *shell, t_args *cmds)
{
	t_args	*cur;
	t_redir	*redir;

	cur = cmds;
	while (cur)
	{
		redir = cur->redirs;
		while (redir)
		{
			if (redir->redir == REDIR_HEREDOC)
			{
				redir->heredoc_fd = exec_heredoc(shell,
						redir->target, redir->expand);
				if (redir->heredoc_fd == -1)
					return ;
			}
			redir = redir->next;
		}
		cur = cur->next;
	}
}

static int	is_limiter(char *line, char *limiter)
{
	return (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0
		&& line[ft_strlen(limiter)] == '\n');
}

static void	heredoc_child(t_minishell *shell, char *lim, int exp, int write_fd)
{
	char	*line;
	char	*tmp;

	set_heredoc_signals();
	while (1)
	{
		ft_putstr_fd("> ", STDOUT_FILENO);
		line = get_next_line(STDIN_FILENO);
		if (!line || is_limiter(line, lim))
		{
			free(line);
			get_next_line(-1);
			close(write_fd);
			child_exit(shell, 0);
		}
		if (exp)
		{
			tmp = expand_vars(line, shell);
			free(line);
			line = tmp;
		}
		write(write_fd, line, ft_strlen(line));
		if (!exp)
			free(line);
	}
}

int	exec_heredoc(t_minishell *shell, char *limiter, int expand)
{
	int		hd_pipe[2];
	pid_t	pid;
	int		status;

	if (pipe(hd_pipe) == -1)
		return (-1);
	pid = fork();
	if (pid == 0)
	{
		close(hd_pipe[0]);
		heredoc_child(shell, limiter, expand, hd_pipe[1]);
	}
	close(hd_pipe[1]);
	signal(SIGINT, handle_sigint_child);
	signal(SIGQUIT, SIG_IGN);
	waitpid(pid, &status, 0);
	setup_signals();
	if (WIFSIGNALED(status) && WTERMSIG(status) == SIGINT)
	{
		g_sig = SIGINT;
		write(STDOUT_FILENO, "\n", 1);
		close(hd_pipe[0]);
		return (-1);
	}
	return (hd_pipe[0]);
}
