/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_dop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyoda <chyoda@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 10:24:09 by chyoda            #+#    #+#             */
/*   Updated: 2022/09/28 10:24:10 by chyoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env_value(char *env)
{
	int		i;
	char	*tmp;

	i = 0;
	while (env[i] && env[i] != '=')
		i++;
	tmp = strdup(&env[i + 1]);
	return (tmp);
}

int	check_args_cd(char **args, t_env_var *env)
{
	if (args[1] && args[2])
	{
		ft_putstr_fd("cd: too many arguments\n", 2);
		env->status = 1;
		return (1);
	}
	return (0);
}
