/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:22:45 by fgreiff           #+#    #+#             */
/*   Updated: 2025/05/29 12:17:25 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;
	t_list	*prev;

	if (!lst)
		return (NULL);
	temp = lst;
	while (temp)
	{
		prev = temp;
		temp = temp->next;
	}
	return (prev);
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

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

#include <stdio.h>

int	main(void)
{
	t_list	*node;
	t_list	*node2;
	t_list	*last;
	int i;
	int c;
	int	*ptr;
	int	*ptr2;

	i = 10;
	c = -5;
	ptr = &i;
	ptr2 = &c;
	node = ft_lstnew(ptr);
	node2 = ft_lstnew(ptr2);
	ft_lstadd_front(&node, node2);
	last = ft_lstlast(node2);
	printf("the last node is %d\n", *(int *)(last->content));
	return (0);
}*/
