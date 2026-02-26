/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 14:30:25 by fgreiff           #+#    #+#             */
/*   Updated: 2026/02/26 16:44:20 by fgreiff          ###   ########.fr       */
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
				redir->heredoc_fd = exec_heredoc(shell,
						redir->target, redir->expand);
			redir = redir->next;
		}
		cur = cur->next;
	}
}

int	exec_heredoc(t_minishell *shell, char *limiter, int expand)
{
	int		hd_pipe[2];
	char	*line;
	char	*expanded;

	pipe(hd_pipe);
	while (1)
	{
		ft_putstr_fd("> ", STDOUT_FILENO);
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break ;
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0
			&& line[ft_strlen(limiter)] == '\n')
		{
			free(line);
			break ;
		}
		if (expand)
		{
			expanded = expand_vars(line, shell->last_exit_status);
			free(line);
			line = expanded;
		}
		write(hd_pipe[1], line, ft_strlen(line));
		free(line);
	}
	close(hd_pipe[1]);
	return (hd_pipe[0]);
}