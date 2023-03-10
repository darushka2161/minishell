/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyoda <chyoda@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 10:26:00 by chyoda            #+#    #+#             */
/*   Updated: 2022/09/28 10:26:00 by chyoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# ifdef __APPLE__
#  define MAC_OS 1
# else
#  define MAC_OS 0
# endif
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <sys/stat.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>
# include "libft.h"
# include "enums.h"
# include "error_msgs.h"
# define MYSHELL	"\e[0;36mMyShell >\e[0m"

int	g_interrupt;

typedef struct s_simpleCommand
{
	int		number_of_available_arguments;
	int		number_of_arguments;
	char	**arguments;
	char	*out_file;
	int		out_file_type;
	int		out_fd;
	char	*in_file;
	int		in_file_type;
	int		in_fd;
	int		db_fd[2];
	int		extra_fd;
}	t_simpleCommand;

typedef struct s_command
{
	char					*cmd;
	int						number_of_available_simple_commands;
	int						number_of_simple_commands;
	t_simpleCommand			**simple_commands;
	int						background;
	char					**env;
	int						tmp;
	int						result;
}	t_command;

typedef struct s_env_var
{
	char			**env;
	char			**path;
	int				stdin_fd;
	int				stdout_fd;
	int				status;
	unsigned char	exit;
}	t_env_var;

int				args_size(char **args);
int				ft_echo(char **args);
int				ft_dollar_leng(int i, char *pipe_line);
char			*ft_env_var(int i, char *pipe_line, int k, t_command *command);
char			*ft_find_env_var(char **var, char **env);
char			*ft_pipe_line_chng(char **pipe_line, char *res, \
					int *i_k, t_command *command);
char			*ft_dollar(char **pipe_line, t_command *command);
int				ft_file_fill(char **pipe_line, int l, char **file);
int				ft_file_out(char **pipe_line, int *ch, int n, char **file);
void			ft_file_find2(char **pipe_line, t_command *command, int k);
void			ft_file_find(char **pipe_line, t_command *command, int k);
int				ft_strlen_space(char *str);
int				ft_flags(char *pipe_line, int flag, int i);
int				ft_chek_leng_com(char *pipe_line);
int				ft_alloc_for_pattern(int n, char *pipe_line, \
					t_command *command);
void			ft_copy_pipe(char **pipe_line, \
					t_command *command, int i, int k);
t_command		*parsbody(char *pipe_line, t_env_var *vars);
void			ft_pars_dop1(char **pipe_line, \
					t_command *command, int i, int *k);
void			ft_pars_dop2(char **pipe_line, \
					t_command *command, int i, int *k);
void			ft_pars_simple(char **pipe_line, t_command *command);
void			ft_find_pipe(char *pipe_line, t_command *command);
int				ft_quotes_for_pipe(char *pipe_line);
int				ft_quotes(char *pipe_line);
int				deteck_flag(int k, int l, int *count);
void			ft_alloc_dup(int n, char **pipe_line, int *j, \
					t_command *command);
char			*ft_without_un_quotes(char *pipe_line, char q);
t_command		*zero_struk_command(char *pipe_line, t_env_var *vars);
t_simpleCommand	*zero_struk_simple(void);
void			ft_zero_var(int *i, int *k, int *m, char **res);
int				ft_small_stuped_bull_sheet(int i, char *pipe_line);
void			fkng_bll_shit(char **pipe_line, int *j);
int				ft_pwd(t_env_var *vars);
int				find_env(char **env, char *s);
char			*ft_quotes_chng_end(char *pipe_line, int *i);
char			*ft_quotes_chng_strt(char *pipe_line, int i);
void			ft_show(t_command *command);
void			ft_ps_dop(char **pipe_line, t_command *command, int i);
void			ft_cl_pl(int *del, t_command *command, char **pipe_line);
void			ft_cp_dop(t_command *command, char *f, char **pipe_line);
void			ft_wuq_dop(char **pipe_line, int *i, int *flag, char g);
void			ft_fev_dop(char **res, char **env, int i, int *k);
void			ft_ff_dop(char **pipe_line, int *i, int l, char **file);
char			escaped_eof(char *cmd);
char			has_opened_quotes(char *cmd, int start, int end);
int				has_opened_parenth(char *cmd, char parenth, \
					char opened_quote, int i);
char			more_two_sequenses_controls(char *cmd, \
					char opened_qoute, int i, int j);
int				is_space(char *cmd, int i);
int				build_in(char *com, t_env_var *vars, \
					t_simpleCommand *cur_command);
int				execute_command(char *tmp, char **arg, t_env_var *vars);
int				do_redirections(t_command *args, int i, t_env_var *vars);
int				get_db_redirections(t_command *args, int i, t_env_var *vars);
int				do_db_redirections(t_command *args, int i);
int				count_colomns(char *s);
char			*check_exec(char *dir, char *cmd);
void			make_path_vector(char *path, char **path_vector, int l);
char			*get_env_value(char *env);

char			*ft_strdup(const char *s1);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strlen(const char *s);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
void			no_handler(int s);

void			set_signals(int handler, int ctl, t_env_var *vars);
int				escaped(char *cmd, int i);
int				check_cmd(char **cmd);
int				print_err(char *main, char	*word, char ch);
char			*ft_chng_line(char **cmd);
int				start_path(t_env_var *vars);
int				ft_env(t_env_var *vars, t_simpleCommand *cur_command);
int				ft_export(t_env_var *vars, t_simpleCommand *cur_command);
void			ft_clean(t_command *args, t_env_var *vars);
int				exec_loop(t_command *args, t_env_var *vars);
void			last_clean(t_env_var *vars);
int				ft_unset(t_env_var *vars, \
					t_simpleCommand *cur_command);
void			add_new_env(t_env_var *vars, char *new);
int				ft_cd(char **args, t_env_var *env);
void			ft_putendl_fd(const char *s, int fd);
void			do_read_input(char *target, t_command *args, int i, \
				t_env_var *vars);
void			find_and_del(t_env_var *vars, char *del);
void			echo_ctl(char on, int fd);
void			ft_z_p_a_r(int *i, int *f, int *count, char *redirect_type);
int				par_dop_if(char *cmd, int *i, char *redirect_type, int *count);
int				check_cmd_sequenses(char *cmd);
int				find_equal(char *s);
int				print_export(t_env_var *var);
void			free_pointers(char ***tmp, int **len);
int				check_args_cd(char **args, t_env_var *env);
int				ft_exit(t_env_var *vars, t_simpleCommand *cur_command);
#endif