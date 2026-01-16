/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:44:12 by fgreiff           #+#    #+#             */
/*   Updated: 2026/01/15 15:56:51 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include "lexer.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_args
{
	char			**args;
	struct s_args	*next;
}	t_args;

#endif