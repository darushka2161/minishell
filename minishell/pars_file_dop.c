/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_file_dop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyoda <chyoda@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 10:26:39 by chyoda            #+#    #+#             */
/*   Updated: 2022/09/28 10:26:41 by chyoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_ff_dop(char **pipe_line, int *i, int l, char **file)
{
	if (ft_quotes(*pipe_line) == 0)
	{
		while ((*i) < l)
		{
			(*file)[(*i)] = (*pipe_line)[(*i)];
			(*i)++;
		}
	}
	return ;
}
