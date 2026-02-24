/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:23:41 by felixgreiff       #+#    #+#             */
/*   Updated: 2026/02/24 12:39:14 by fgreiff          ###   ########.fr       */
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
