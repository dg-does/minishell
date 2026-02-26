/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:39:47 by digulraj          #+#    #+#             */
/*   Updated: 2026/02/26 11:02:37 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int n)
{
	char	*str;
	int		len;

	ft_putnbr_fd(n, 1);
	str = ft_itoa(n);
	if (!str)
		return (0);
	len = ft_strlen(str);
	free(str);
	return (len);
}
