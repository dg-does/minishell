/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:17:20 by digulraj          #+#    #+#             */
/*   Updated: 2026/01/12 16:37:49 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int	main(void)
{
	pid_t	pid;
	int		status;

	printf("Parent: Creating child process... \n");
	pid = fork();
	if (pid == -1)
	{
		perror("fork failed");
		return (1);
	}
	else if (pid == 0)
	{
		printf("Child: I'm alive! PID: %d\n", getpid());
		printf("Child: Exiting with code 42.\n");
		exit(42);
	}
	else
	{
		printf("Parent: Child PID is %d\n", pid);
		printf("Parent: Waiting for child to exit.\n");
		waitpid(pid, &status, 0);
		printf("Child has exited\n");
		if (WIFEXITED(status))
		{
			int exit_code = WEXITSTATUS(status);
			printf("WIFEXITED: true (child exited normally)\n");
			printf("WIFEXITSTATUS: %d\n", exit_code);
			printf("Child exited normally with code %d\n", exit_code);;
		}
		else if (WISIGNALED(status))
		{
			int signal_num = WTERMSIG(status);
			printf("WIFSIGNALED: true (child was killed by signal)\n");
			printf("WTERMSIG: %d\n", signal_num);
			printf("Child was killed by signal %d\n", signal_num);
		}
		else
			printf("Idk how tf your child died bruv\n");
	}
	return (0);
}
