/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgwin <tgwin@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 10:35:28 by tgwin             #+#    #+#             */
/*   Updated: 2022/09/28 10:35:28 by tgwin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>

int	input_loop(t_command *args, t_env_var *vars, char *tmp)
{
	while (1)
	{
		tmp = readline(MYSHELL);
		if (!tmp)
		{
			free(tmp);
			printf("exit\n");
			return (0);
		}
		if (ft_strlen(tmp))
			add_history(tmp);
		set_signals(0, 1, vars);
		tmp = ft_chng_line(&tmp);
		if (check_cmd((&tmp)) != 0)
			continue ;
		args = parsbody(tmp, vars);
		free(tmp);
		start_path(vars);
		exec_loop(args, vars);
		set_signals(1, 0, vars);
		ft_clean(args, vars);
		if (vars->status == -1)
			return (vars->exit);
		g_interrupt = 0;
	}
}

void	dup_env(t_env_var *vars, char **env)
{
	int	i;
	int	c;

	i = -1;
	c = 0;
	while (env[++i])
		c++;
	vars->env = malloc(sizeof(char *) * (c + 1));
	vars->env[c] = NULL;
	i = -1;
	while (env[++i])
		vars->env[i] = ft_strdup(env[i]);
}

void	preprocess(t_env_var *vars, char **env)
{
	dup_env(vars, env);
	vars->status = 0;
	vars->exit = 0;
	vars->stdin_fd = dup(STDIN_FILENO);
	vars->stdout_fd = dup(STDOUT_FILENO);
}

int	main(int argc, char **argv, char **env)
{
	t_command	args;
	t_env_var	vars;
	char		*tmp;
	int			res;

	tmp = NULL;
	g_interrupt = 0;
	res = 0;
	preprocess(&vars, env);
	set_signals(1, 0, &vars);
	(void)argv;
	if (argc == 1)
	{
		res = input_loop(&args, &vars, tmp);
		rl_clear_history();
		echo_ctl(1, 0);
		last_clean(&vars);
		return (res);
	}
	printf("ERROR ARGS");
	return (res);
}
