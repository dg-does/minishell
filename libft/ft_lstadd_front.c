/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:21:04 by fgreiff           #+#    #+#             */
/*   Updated: 2025/05/27 12:23:02 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

/*t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

#include <stdio.h>

int	main(void)
{
	t_list *node;
	t_list *new;
	int i;
	int	*ptr;
	int c;
	int *ptr2;

	i = -15;
	ptr = &i;
	c = -2;
	ptr2 = &c;

	node = ft_lstnew(ptr);
	new = ft_lstnew(ptr2);
	ft_lstadd_front(&node, new);
	while (node != NULL)
	{
		printf("%d\n", *(int *)(node->content));
		node = node->next;
	}
}
*/