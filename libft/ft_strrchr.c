/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 13:33:35 by fgreiff           #+#    #+#             */
/*   Updated: 2025/05/31 17:57:32 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	slen;

	slen = 0;
	while (s[slen] != '\0')
		slen ++;
	while (slen >= 0)
	{
		if ((unsigned char)s[slen] == (unsigned char)c)
			return ((char *)&s[slen]);
		slen--;
	}
	return (0);
}

/*#include <stdio.h>
int main(void)
{
    char *add;

    add = ft_strrchr("abhfgschd", 'g');
    printf("%p\n", add);
    return (0);
}*/