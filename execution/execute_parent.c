/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_parent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixgreiff <felixgreiff@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 14:55:28 by felixgreiff       #+#    #+#             */
/*   Updated: 2026/02/17 15:07:22 by felixgreiff      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


//misses redirections and changing of fds not finished yet!!!!!
void execute_parent(t_minishell *shell, t_arg *cmd)
{
    if (!cmd->value)
        return ;
    if (cmd->value == "cd")
        cd(cmd->next->value);
    if (cmd->value == "unset")
       unset(shell, cmd->next->value);
    if (cmd->value == "export")
        export(shell, cmd->next->value);
    if (cmd->value == "exit")
        exit(shell);
    return (0);
}