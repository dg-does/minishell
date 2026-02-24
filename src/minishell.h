/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:45:38 by felixgreiff       #+#    #+#             */
/*   Updated: 2026/02/24 15:59:38 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "structs.h"
# include "stdlib.h"

void	array_free(char **str);
void	free_shell(t_minishell *shell);

#endif