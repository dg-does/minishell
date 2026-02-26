/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:54:12 by digulraj          #+#    #+#             */
/*   Updated: 2026/02/26 11:02:34 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(unsigned long n)
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

int	ft_puthex_long(unsigned long n)
{
	char	*digits;

	digits = "0123456789abcdef";
	if (n > 15)
		ft_puthex_long(n / 16);
	ft_putchar_fd(digits[n % 16], 1);
	return (count_digits(n));
}

int	ft_putptr(void *ptr)
{
	char			*digits;
	unsigned long	n;

	n = (unsigned long)ptr;
	digits = "0123456789abcdef";
	if (!ptr || n == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	else
	{
		ft_putstr_fd("0x", 1);
		ft_puthex_long(n);
		return (count_digits(n) + 2);
	}
}
/*
#include <stdio.h>
int	main(void)
{
	int len = ft_puthex_upp(11);
	printf("\n%d\n", len);
}
//*/