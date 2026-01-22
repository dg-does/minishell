/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:57:51 by fgreiff           #+#    #+#             */
/*   Updated: 2025/05/29 11:32:16 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

/*#include <stdio.h>

int	main(void)
{
	int		i;
	int		*ptr;
	t_list	*node;

	i = 15;
	ptr = &i;
	node = ft_lstnew(ptr);
	printf("new node %d\n", *(int *)(node->content));
	return (0);
}*/
