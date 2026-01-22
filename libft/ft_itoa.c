/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 13:11:09 by fgreiff           #+#    #+#             */
/*   Updated: 2025/05/30 15:15:05 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int n)
{
	int	counter;
	int	i;

	i = n;
	if (i == 0)
		return (1);
	counter = 0;
	if (n < 0)
		counter++;
	while (i != 0)
	{
		i = i / 10;
		counter++;
	}
	return (counter);
}

char	*ft_itoa(int n)
{
	int		counter;
	char	*c;
	long	num;
	int		j;
	int		sign;

	counter = ft_count(n);
	c = malloc((counter + 1) * sizeof(char));
	j = counter - 1;
	if (!c)
		return (NULL);
	sign = (n < 0);
	if (sign)
		num = -(long)n;
	else 
		num = n;
	c[counter] = '\0';
	while (j >= sign)
	{
		c[j--] = (num % 10) + '0';
		num /= 10;
	}
	if (sign)
		c[0] = '-';
	return (c);
}

/*int	main(void)
{
	char *str;

	str = ft_itoa(-1574);
	printf("the int is now %s\n", str);
	return (0);
}*/
