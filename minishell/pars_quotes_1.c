/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_quotes_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyoda <chyoda@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 10:27:32 by chyoda            #+#    #+#             */
/*   Updated: 2022/09/28 10:27:33 by chyoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_quotes_for_pipe(char *pipe_line)
{
	int	count;
	int	j;
	int	flag[2];

	flag[0] = 0;
	flag[1] = 0;
	count = 0;
	j = 0;
	while (pipe_line[j] && pipe_line[j] \
		!= '|' && pipe_line[j] != '>' && pipe_line[j] != '<')
	{
		j++;
		if (pipe_line[j - 1] && pipe_line[j - 1] == '$' && \
			(flag[1] == 1 || (flag[0] == 0 && flag[1] == 0)))
			return (-1);
		if ((int)(pipe_line[j - 1]) == 39)
			flag[0] = deteck_flag(flag[0], flag[1], &count);
		if (pipe_line[j - 1] == 34)
			flag[1] = deteck_flag(flag[1], flag[0], &count);
	}
	return (count);
}

int	ft_quotes(char *pipe_line)
{
	int	count;
	int	j;
	int	flag[2];

	flag[0] = 0;
	flag[1] = 0;
	count = 0;
	j = 0;
	while (pipe_line[j] && pipe_line[j] != ' ' && pipe_line[j] \
		!= '|' && pipe_line[j] != '>' && pipe_line[j] != '<')
	{
		j++;
		if ((int)(pipe_line[j - 1]) == 39)
			flag[0] = deteck_flag(flag[0], flag[1], &count);
		if (pipe_line[j - 1] == 34)
			flag[1] = deteck_flag(flag[1], flag[0], &count);
	}
	return (count);
}

int	deteck_flag(int k, int l, int *count)
{
	if (k == 0 && l == 0)
	{
		(*count)++;
		return (1);
	}
	else if (k == 1 && l == 0)
	{
		(*count)++;
		return (0);
	}
	else
		return (k);
}

void	ft_alloc_dup(int n, char **pipe_line, int *j, t_command *command)
{
	if (n != 0)
	{
		if (**pipe_line == ' ' && ++command->tmp)
			(*pipe_line)++;
		if ((*pipe_line)[0] == '\'')
		{
			(*j)++;
			while ((*pipe_line)[*j] != '\'')
				(*j)++;
		}
		else if ((*pipe_line)[0] == '\"')
		{
			(*j)++;
			while ((*pipe_line)[*j] != '\"')
				(*j)++;
		}
		(*j)--;
	}
}

char	*ft_without_un_quotes(char *pipe_line, char g)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	while (pipe_line[i] && pipe_line[i] != '|')
	{
		ft_wuq_dop(&pipe_line, &i, &flag, g);
		i++;
	}
	return (pipe_line);
}
