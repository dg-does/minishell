/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redirection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 16:48:03 by felixgreiff       #+#    #+#             */
/*   Updated: 2026/02/24 18:15:24 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "execution.h"

void	apply_redirection(t_redir *redirs)
{
	while (redirs)
	{
		if (redirs->redir == REDIR_IN)
			redirect_in(redirs);
		if (redirs->redir == REDIR_OUT)
			redirect_out(redirs);
		if (redirs->redir == REDIR_APPEND)
			redirect_append(redirs);
		/*if (redirs->redir == REDIR_HEREDOC)
			redirect_heredoc(redirs);*/
		redirs = redirs->next;
	}
}

void	redirect_in(t_redir *redirs)
{
	int	fd;

	fd = open(redirs->target, O_RDONLY);
	if (fd < 0)
	{
		perror("minishell: open");
		return ;
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	return ;
}

void	redirect_out(t_redir *redirs)
{
	int	fd;

	fd = open(redirs->target, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror("minishell: open");
		return ;
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return ;
}

void	redirect_append(t_redir *redirs)
{
	int	fd;

	fd = open(redirs->target, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd < 0)
	{
		perror("minishell: open");
		return ;
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return ;
}

/*void	redirect_heredoc(t_redir *redirs)
{
	
}*/
