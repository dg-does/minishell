/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_wrappers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 14:01:55 by digulraj          #+#    #+#             */
/*   Updated: 2026/03/12 16:34:11 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "minishell.h"

static void	gc_register(void *ptr)
{
	t_gc_node	*node;

	node = malloc(sizeof(t_gc_node));
	if (!node)
		return ;
	node->ptr = ptr;
	node->next = gc_get()->head;
	gc_get()->head = node;
}

char	*gc_strdup(const char *s)
{
	char	*result;

	result = ft_strdup(s);
	if (!result)
		return (NULL);
	gc_register(result);
	return (result);
}

char	**gc_split(char const *s, char c)
{
	char	**result;
	int		i;

	result = ft_split(s, c);
	if (!result)
		return (NULL);
	i = 0;
	if (result)
	{
		while (result[i])
			gc_register(result[i++]);
		gc_register(result);
	}
	return (result);
}
