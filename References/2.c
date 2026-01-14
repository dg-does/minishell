/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 11:47:49 by digulraj          #+#    #+#             */
/*   Updated: 2026/01/12 12:37:43 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int	main(void)
{
	pid_t	pid;

	printf("Parent before fork (PID %d)\n", getpid());
	pid = fork();
	if (pid == -1)
	{
		perror("Forking failed");
		return (1);
	}
	else if (pid == 0)
	{
		printf("Child after fork (PID %d)\n", getpid());
	}
	else
	{
		printf("Parent after fork (PID %d)\n", getpid());
	}
	return (0);
}
