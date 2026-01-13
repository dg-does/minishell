/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:08:25 by digulraj          #+#    #+#             */
/*   Updated: 2026/01/12 16:01:37 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char	**ft_split(char const *s, char c);
char	*ft_strjoin(const char *s1, const char *s2);

void	free_split(char **split)
{
	int	i; 

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	is_path(char *str)
{
	int		i;
	char	*path = "PATH=";

	i = 0;
	while (str[i] && path[i])
	{
		if (str[i] != path[i])
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av, char **envp)
{
	int		i;
	char	*path_str;
	char	**dirs;
	char	*tmp;
	char	*full;

	if (ac != 2)
	{
		printf("Enter only one command arguement");
		return (1);
	}
	i = 0;
	path_str = NULL;
	dirs = NULL;
	tmp = NULL;
	full = NULL;
	while (envp[i])
	{
		if (is_path(envp[i]))
		{
			path_str = envp[i] + 5;
// to move past "path=" and save the actual path in path_str
			break ;
		}
		i++;
	}
	if (!path_str)
	{
		printf("PATH not found in envp\n");
		return (1);
	}
	dirs = ft_split(path_str, ':');
	if (!dirs)
	{
		printf("split failed!");
		goto cleanup;
	}
	i = 0;
	while (dirs[i])
	{
		tmp = ft_strjoin(dirs[i], "/");
		if (!tmp)
			goto cleanup;
		full = ft_strjoin(tmp, av[1]);
		free(tmp);
		tmp = NULL;
		if (access(full, X_OK) == 0)
		{
			printf("Found: %s\n", full);
			goto success;
		}
		free(full);
		full = NULL;
		i++;
	}
	printf("Command not found\n");

	cleanup:
		free(tmp);
		free(full);
		free_split(dirs);
		return (1);

	success:
		free(full);
		free_split(dirs);
		return (0);
}

