/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 11:05:59 by digulraj          #+#    #+#             */
/*   Updated: 2026/01/12 11:47:38 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	exit_now(char *buffer)
{
	char	*exit;
	int		i;

	exit = "exit\n";
	i = 0;
	while (exit[i] != '\0')
	{
		if (buffer[i] != exit[i])
			return (0);
		i++;
	}
	if (buffer[i] != '\0')
		return (0);
	return (1);
}


int	main(void)
{
	char		buffer[100];
	ssize_t		bytes;

	while (1)
	{
		printf(">");
		bytes = read(0, buffer, 100);
		if (bytes == 0)
			break ;
		buffer[bytes] = '\0';
		if (exit_now(buffer))
			break ;
		printf("You typed: %s", buffer);
	}
	return (0);
}
