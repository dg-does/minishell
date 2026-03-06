/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 12:21:11 by felixgreiff       #+#    #+#             */
/*   Updated: 2026/03/06 13:42:39 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	array_free(char **str)
{
	int	i;

	i = 0;
	if (!str || !str[i])
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return ;
}

t_gc	*gc_get(void)
{
	static t_gc	gc = {NULL};

	return (&gc);
}

void	*gc_malloc(size_t size)
{
	t_gc_node	*node;
	void		*ptr;

	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	node = malloc(sizeof(t_gc_node));
	if (!node)
	{
		free(ptr);
		return (NULL);
	}
	node->ptr = ptr;
	node->next = gc_get()->head;
	gc_get()->head = node;
	return (ptr);
}

void	gc_free_all(void)
{
	t_gc_node	*current;
	t_gc_node	*next;

	current = gc_get()->head;
	while (current)
	{
		next = current->next;
		free(current->ptr);
		free(current);
		current = next;
	}
	gc_get()->head = NULL;
}

void	gc_free(void *ptr)
{
	t_gc_node	**current;
	t_gc_node	*to_free;

	current = &gc_get()->head;
	while (*current)
	{
		if ((*current)->ptr == ptr)
		{
			to_free = *current;
			*current = (*current)->next;
			free(to_free->ptr);
			free(to_free);
			return ;
		}
		current = &(*current)->next;
	}
}
