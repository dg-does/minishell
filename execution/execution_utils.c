/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixgreiff <felixgreiff@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:23:41 by felixgreiff       #+#    #+#             */
/*   Updated: 2026/02/17 14:26:06 by felixgreiff      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_built_in(t_arg *cmd)
{
	if (cmd->value == "cd" || cmd->value == "unset" || cmd->value == "export"
		|| cmd->value == "exit")
		return (1);
	else 
		return (0);
}