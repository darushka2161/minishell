/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd_dop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgwin <tgwin@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 10:32:47 by tgwin             #+#    #+#             */
/*   Updated: 2022/09/28 10:32:48 by tgwin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "enums.h"

int	empty_heredoc_or_redirect(char *cmd)
{
	if (cmd == NULL || *cmd == ends)
		return (unsuccess);
	if (((*cmd == l_crnr || *cmd == r_crnr) && ft_strlen(cmd) == 1)
		|| (ft_strcmp(cmd, "<<") == success || ft_strcmp(cmd, ">>") == success)
		|| (cmd[ft_strlen(cmd) - 1] == l_crnr
			|| cmd[ft_strlen(cmd) - 1] == r_crnr))
	{
		print_err(MSG_ERR_SYNATX, NULL, false);
		return (unsuccess);
	}
	return (success);
}

int	check_cmd_sequenses(char *cmd)
{
	if (escaped_eof(cmd) == escape)
	{
		print_err(MSG_ERR_CMD_EEOF, NULL, false);
		return (false);
	}
	if (has_opened_quotes(cmd, 0, ft_strlen(cmd)))
	{
		print_err(MSG_ERR_CMD_UQ, NULL,
			has_opened_quotes(cmd, 0, ft_strlen(cmd)));
		return (false);
	}
	if (more_two_sequenses_controls(cmd, 0, 0, 0))
	{
		print_err(MSG_ERR_MORE2CNTRLS, NULL,
			more_two_sequenses_controls(cmd, 0, 0, 0));
		return (false);
	}
	if (has_opened_parenth(cmd, 0, 0, 0))
	{
		print_err(MSG_ERR_CMD_HAS_UP, NULL, false);
		return (false);
	}
	if (empty_heredoc_or_redirect(cmd))
		return (false);
	return (true);
}

void	par_dop(char *cmd, int *i, char *redirect_type, int *count)
{
	if (cmd[*i] == ' ')
	{
		*redirect_type = '\0';
		*count = 0;
	}
	(*i)++;
}

int	par_dop_if(char *cmd, int *i, char *redirect_type, int *count)
{
	if (cmd[*i] == '>' || cmd[*i] == '<')
	{
		if ((*redirect_type) == '\0')
			*redirect_type = cmd[*i];
		else if (cmd[*i] == *redirect_type)
			(*count)++;
		else
		{
			print_err(MSG_ERR_INVRDTYPE, NULL, false);
			return (unsuccess);
		}
	}
	if (cmd[*i] == *redirect_type && *count == 2)
	{
		print_err(MSG_ERR_MORE2CNTRLS, NULL, *redirect_type);
		return (unsuccess);
	}
	par_dop(cmd, i, redirect_type, count);
	return (2);
}

void	ft_z_p_a_r(int *i, int *f, int *count, char *redirect_type)
{
	*i = 0;
	*f = 0;
	*count = 0;
	*redirect_type = '\0';
}
