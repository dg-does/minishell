/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_low.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:40:56 by digulraj          #+#    #+#             */
/*   Updated: 2026/02/26 11:02:24 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		count++;
	}
	return (count);
}

int	ft_puthex_low(unsigned int n)
{
	char	*digits;

	digits = "0123456789abcdef";
	if (n > 15)
		ft_puthex_low(n / 16);
	ft_putchar_fd(digits[n % 16], 1);
	return (count_digits(n));
}
/*
#include <stdio.h>
int	main(void)
{
	int len = ft_puthex_low(11);
	printf("\n%d\n", len);
}
//*/