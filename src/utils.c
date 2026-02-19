/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixgreiff <felixgreiff@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 12:21:11 by felixgreiff       #+#    #+#             */
/*   Updated: 2026/02/19 12:46:41 by felixgreiff      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void array_free(char **str)
{
	int	i;

	i = 0;
	if (!str || !str[i])
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return ;
}