/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixgreiff <felixgreiff@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:45:38 by felixgreiff       #+#    #+#             */
/*   Updated: 2026/02/03 16:53:49 by felixgreiff      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <parser.h>
# include <lexer.h>
# include <built_in.h>

typedef struct s_minishell
{
    char    **env;
    int     last_status;
}   t_minishell;

#endif