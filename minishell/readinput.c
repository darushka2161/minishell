/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readinput.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgwin <tgwin@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 10:37:10 by tgwin             #+#    #+#             */
/*   Updated: 2022/09/28 10:37:10 by tgwin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "libft.h"
#include "error_msgs.h"
#include "minishell.h"

int	check_g_interrupt(void)
{
	if (g_interrupt)
		rl_done = true;
	return (0);
}

void	pipe_for_read_input(char *redirect, t_command *args, \
								int i, t_env_var *vars)
{
	int	fd[2];

	pipe(fd);
	ft_putstr_fd(redirect, fd[1]);
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	if (args->simple_commands[i]->out_file_type != 0 || \
		args->number_of_simple_commands == i + 1)
	{
		if (args->simple_commands[i]->out_file_type == 1)
			args->simple_commands[i]->out_fd = open(args->\
			simple_commands[i]->out_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		else if (args->simple_commands[i]->out_file_type == 2)
			args->simple_commands[i]->out_fd = open(args->\
			simple_commands[i]->out_file, O_WRONLY | O_CREAT | O_APPEND, 0644);
		else
			args->simple_commands[i]->out_fd = vars->stdout_fd;
		dup2(args->simple_commands[i]->out_fd, STDOUT_FILENO);
		if (args->simple_commands[i]->out_fd != vars->stdout_fd)
			close(args->simple_commands[i]->out_fd);
	}
}

void	do_update_target(char **redirect, char *readline_res)
{
	char	*res;
	char	*tmp;

	tmp = *redirect;
	res = ft_strjoinchr(readline_res, endl);
	*redirect = ft_strjoin(*redirect, res);
	free(tmp);
	free(res);
}

void	do_read_input(char *target, t_command *args, int i, t_env_var *vars)
{
	char	*readline_res;
	char	*redirect;

	readline_res = NULL;
	redirect = NULL;
	rl_event_hook = check_g_interrupt;
	while (target && g_interrupt == false)
	{
		readline_res = readline(">");
		if (!readline_res && g_interrupt == false)
			print_err(MSG_ERR_HEREDOC, target, 0);
		if (ft_strcmp(readline_res, target) == 0)
			break ;
		if (readline_res)
			do_update_target(&redirect, readline_res);
		free(readline_res);
		readline_res = NULL;
	}
	rl_event_hook = NULL;
	pipe_for_read_input(redirect, args, i, vars);
	free(target);
	free(readline_res);
	free(redirect);
}
