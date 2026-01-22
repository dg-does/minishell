/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:28:22 by fgreiff           #+#    #+#             */
/*   Updated: 2025/05/23 11:46:35 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c <= '9' && c >= '0')
		return (1);
	else
		return (0);
}

/*#include <unistd.h>
int main(void)
{
    int a;

    a = ft_isdigit('5') + '0';
    write(1, &a, 1);
    return (9);
}*/