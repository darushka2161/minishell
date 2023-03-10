/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyoda <chyoda@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 10:27:56 by chyoda            #+#    #+#             */
/*   Updated: 2022/09/28 10:27:56 by chyoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(t_env_var *vars)
{
	char	cwd[PATH_MAX];
	int		i;

	i = 0;
	if (getcwd(cwd, PATH_MAX))
	{
		if (cwd == NULL)
			return (-1);
		while (cwd[i] != '\0')
		{
			write(1, &(cwd[i]), 1);
			i++;
		}
		write(1, "\n", 1);
		vars->status = 0;
		return (0);
	}
	else
	{
		vars->status = 1;
		return (-1);
	}
}
