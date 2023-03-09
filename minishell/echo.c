/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyoda <chyoda@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 10:24:46 by chyoda            #+#    #+#             */
/*   Updated: 2022/09/28 10:24:46 by chyoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	args_size(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

int	ft_strcmp_nnn(const char *s1)
{
	size_t	i;

	if (!s1[0])
		return (0);
	i = 1;
	while (s1[i] && s1[i] == 'n')
		i++;
	if (!s1[i] && i != 1)
		return (0);
	return (1);
}

int	ft_echo(char **args)
{
	int	i;
	int	option_count;

	i = 1;
	option_count = 0;
	if (args_size(args) > 1)
	{
		while (args[i] && ft_strcmp_nnn(args[i]) == 0)
		{
			option_count = 1;
			i++;
		}
		while (args[i])
		{
			ft_putstr_fd(args[i], 1);
			if (args[i + 1] && args[i][0] != '\0')
				write(1, " ", 1);
			i++;
		}
	}
	if (option_count == 0)
		write(1, "\n", 1);
	return (0);
}
