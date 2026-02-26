/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 12:43:59 by fgreiff           #+#    #+#             */
/*   Updated: 2026/02/26 14:25:22 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# define TOKEN_BUFFER_SIZE 4096

typedef struct s_minishell
{
	char	**env;
	int		last_exit_status;
}	t_minishell;

typedef enum e_token_type
{
	TOKEN_WORD,
	TOKEN_PIPE,
	TOKEN_REDIRECT_IN,
	TOKEN_REDIRECT_OUT,
	TOKEN_REDIRECT_APPEND,
	TOKEN_HEREDOC
}	t_type;

typedef enum e_quote_type
{
	NO_QUOTE,
	SINGLE_QUOTE,
	DOUBLE_QUOTE
}	t_quote;

typedef struct s_token
{
	char			*value;
	t_type			type;
	t_quote			quote_type;
	struct s_token	*next;
}	t_token;

typedef enum e_redir_type
{
	REDIR_IN,
	REDIR_OUT,
	REDIR_APPEND,
	REDIR_HEREDOC
}	t_redir_type;

typedef struct s_redir
{
	char			*target;
	t_redir_type	redir;
	int				expand;
	int				heredoc_fd;
	struct s_redir	*next;
}	t_redir;

typedef struct s_arg
{
	char			*value;
	t_quote			quote_type;
	struct s_arg	*next;
}	t_arg;

typedef struct s_args
{
	t_arg			*args;
	t_redir			*redirs;
	struct s_args	*next;
}	t_args;

#endif