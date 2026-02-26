/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:02:19 by digulraj          #+#    #+#             */
/*   Updated: 2026/02/26 11:02:09 by digulraj         ###   ########.fr       */
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
		n /= 10;
		count++;
	}
	return (count);
}

int	ft_putunsigned(unsigned int n)
{
	char	*digits;

	digits = "0123456789";
	if (n > 9)
		ft_putunsigned(n / 10);
	write(1, &digits[n % 10], 1);
	return (count_digits(n));
}
/*
#include <stdio.h>
int	main(void)
{
	int len = ft_putunsigned(-5);
	printf("\n%d\n", len);
}
//*/