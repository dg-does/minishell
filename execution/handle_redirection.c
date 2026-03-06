/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redirection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 16:48:03 by felixgreiff       #+#    #+#             */
/*   Updated: 2026/03/06 12:23:00 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "execution.h"

int	apply_redirection(t_redir *redirs)
{
	while (redirs)
	{
		if (redirs->redir == REDIR_IN && redirect_in(redirs))
			return (1);
		if (redirs->redir == REDIR_OUT && redirect_out(redirs))
			return (1);
		if (redirs->redir == REDIR_APPEND && redirect_append(redirs))
			return (1);
		if (redirs->redir == REDIR_HEREDOC)
			redirect_heredoc(redirs);
		redirs = redirs->next;
	}
	return (0);
}

int	redirect_in(t_redir *redirs)
{
	int	fd;

	fd = open(redirs->target, O_RDONLY);
	if (fd < 0)
	{
		perror("minishell: open");
		return (1);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (0);
}

int	redirect_out(t_redir *redirs)
{
	int	fd;

	fd = open(redirs->target, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror("minishell: open");
		return (1);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (0);
}

int	redirect_append(t_redir *redirs)
{
	int	fd;

	fd = open(redirs->target, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd < 0)
	{
		perror("minishell: open");
		return (1);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (0);
}

void	redirect_heredoc(t_redir *redirs)
{
	dup2(redirs->heredoc_fd, STDIN_FILENO);
	close(redirs->heredoc_fd);
	return ;
}
