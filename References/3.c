/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:40:25 by digulraj          #+#    #+#             */
/*   Updated: 2026/01/12 13:36:23 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	main(int ac, char **av, char **envp)
{
	char	*path = "/bin/ls";
	char	*args[2] = {"testing", NULL};

	printf("About to execute %s\n", path);
	if (execve(path, args, envp) == -1)
	{
		perror("execve failed");
		return (1);
	}
	return (0);
}
