/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:36:57 by fgreiff           #+#    #+#             */
/*   Updated: 2025/05/27 13:58:29 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*temp;
	int		i;

	temp = lst;
	i = 0;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
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
	t_list *node;
	t_list *new;
	int i;
	int	*ptr;
	int c;
	int *ptr2;
	int	size;

	i = -15;
	ptr = &i;
	c = -2;
	ptr2 = &c;
	node = ft_lstnew(ptr);
	new = ft_lstnew(ptr2);
	ft_lstadd_front(&node, new);
	size = ft_lstsize(node);
	printf("%d\n", size);
}*/