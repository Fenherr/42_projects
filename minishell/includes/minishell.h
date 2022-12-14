/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:56:15 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/12/13 13:04:34 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <fcntl.h>
# include <wait.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "../libft/libft.h"

/*===================================================================
							STRUCTURES
===================================================================*/

typedef struct s_var
{
	char	*name;
	char	*value;
}	t_var;

typedef struct s_cmd
{
	char	*name;
	char	*input;
	char	*heredoc;
	char	**arg;
	int		fd_in;
	int		fd_out;
}	t_cmd;

typedef struct s_data
{
	char	**paths;
	char	**heredoc;
	t_list	*env;
	int		exit;
	int		pipe_error;
	int		*pids;
}	t_data;

extern int	g_exit_status;

/*===================================================================
								PARSING
===================================================================*/

/* ============================parsing.c========================== */
char		**get_paths(t_list *env);
t_cmd		*add_command(t_cmd *commands, t_cmd command);
t_cmd		*parse_buf(t_data *data, char *buf, char **paths);
void		free_commands(t_cmd *commands);

/* =========================parsing_utils.c======================= */
char		quote_gestion(char c, char quote);
int			is_in_str(char *str, char c);
int			len_word(char const *s, char *sep, int i);
char		**ft_split_quote(char const *s, char *sep);
int			quote_error(char *buf);

/* ============================command.c========================== */
void		free_command(t_cmd *command);
t_cmd		empty_command(char *input, int fd_int, int fd_out);
t_cmd		get_cmd(t_data *data, char *input, char **envp);
void		print_cmd(t_cmd *command);

/* =========================command_utils.c======================= */
int			is_bultin(char *name);
char		*get_command_path(char *name, char **paths);
char		**get_arg(char **split_res, char **paths, t_list *env);
char		**redo_split(char **split_res);

/* ===========================variable.c========================== */
char		*add_char(char *str, char c);
char		*add_chars_before_variable(char *res, char *str, int *i, int *text);
char		*add_value_variable(t_list *env, char *res, char *str, int *i);
char		*replace_variable_to_value(t_list *env, char *str);

/* ========================variable_utils.c======================= */
void		free_var(void *var);
char		*get_variable_value(t_list *env, char *name);
void		add_new_variable(t_list *env, char *name, char *value);
void		set_variable_value(t_list *env, char *name, char *value);
void		remove_variable(t_list *env, char *name);

/* ========================variable_utils2.c====================== */
char		*get_name_envp(char *str);
char		*get_value_envp(char *str);
t_var		*create_var(t_list *env, char **envp, int i);
t_var		*create_new_var(char *name, char *value);

/* ==============================quote.c=========================== */
char		*interprete_quote(char *str);

/* ===============================env.c============================ */
t_list		*create_env(char **envp);
char		**get_tab_env(t_list *env);
t_list		*dup_env(t_list *env);

/* ==========================redirection.c========================= */
int			get_file_next2(char **tmp, char **split_res, int i);
int			get_file_next(char **tmp, char **split_res, int i);
char		*final_check_and_return(int file_next, char **split_res, char *res);
char		*tmp_gestion(char *tmp, char *name, int file_next);
char		*interprete_redirection(t_data *data, t_cmd *cmd, char *input);

/* =======================redirection_utils.c====================== */
int			check_file(char *name, int flags);
void		input_file(t_data *data, t_cmd *cmd, char **name, int heredoc);
void		output_file(t_cmd *cmd, char **name, int append);
char		*error_file(t_cmd *cmd, char *res, char **split_res);
int			get_fd(t_data *data, t_cmd *cmd, char **name, int file_next);

/* =======================redirection_utils2.c===================== */
int			len_word_redirection(char const *s, char *sep, int *i);
char		**ft_split_redirection(char *s);
int			is_pipe_error(t_data *data, int *only_space, int *nb_cmd);
void		pipe_error(t_data *data, char *buf);

/* ============================here_doc.c========================== */
char		*write_in_here_doc(char *limiter, t_data *data, int nb_cmd);
int			get_start_limiter(char *buf, int start);
int			parse_heredoc(t_data *data, char *buf);
char		*get_and_remove_first_heredoc(t_data *data);
int			here_doc(t_data *data, t_cmd *cmd);

/* =========================here_doc_utils.c======================= */
char		*get_to_write(int *start, char *buf, t_data *data, int nb_cmd);
char		*free_and_do_heredoc(t_data *data, char *limiter, char *to_write);
void		in_fork_heredoc(t_data *data, char *limiter, char *to_write,
				int nb_cmd);
int			fork_heredoc(char *limiter, t_data *data, int nb_cmd);

/* ==============================error.c=========================== */
int			test_input_bad_redirection(char *str, int *i, int j);
int			test_output_bad_redirection(char *str, int *i, int j);

int			test_bad_redirection(char *str);
int			error_arg(t_cmd *cmd);

/* ===========================error_utils.c======================== */
int			is_redirection(char *str);
int			test_bad_redirection2(char *str, int j);
int			check_buf_heredoc(char *tmp, char *limiter);

/*===================================================================
								SIGNALS
===================================================================*/

/*=============================signal.c============================*/
void		prompt_ctrlc_management(int sig);
void		ctrlc_management(int sig);
void		backslach_management(int sig);
void		ft_signals(int sig);
void		exit_heredoc(int sig);

/*===================================================================
								EXECUTION
===================================================================*/

/*===========================execution.c===========================*/
void		exec_and_quit_fork(t_data *data, t_cmd *cmds, int i,
				char **env_tmp);
int			execute_cmd(t_data *data, t_cmd *cmds, int i, int **pipes);
void		execution_loop(t_data *data, t_cmd *cmds, int **pipes);
void		waitpid_loop(t_data *data, t_cmd *cmds);
void		interprete_cmds(t_data *data, t_cmd *cmds);

/*=========================execution_utils.c========================*/
int			check_minus(char *arg);
int			unset_error(t_cmd *cmd);
void		execute_builtins(t_data *data, t_cmd *cmd);
int			modify_env2(t_cmd *cmd);
int			modify_env(t_data *data, t_cmd *cmd);

/*=========================execution_utils2.c=======================*/
int			init_pids(t_data *data, t_cmd *cmds, int **pipes);
void		pipe_gestion(t_cmd *cmds, int i, int *pipe1, int *pipe2);
void		close_fds(t_cmd *cmd, int **pipes);
void		change_g_status(t_cmd *cmd);
void		execution_error(char *str);

/*============================bultins.c============================*/
char		*ft_pwd(void);
void		print_pwd(void);
void		cd_implement(t_list *env, t_cmd *cmd);
void		unset_builtin(t_data *data, t_cmd *cmd);
void		env_builtin(t_list *env);

/*==========================bultins_utils.c=========================*/
void		variables_changement(t_list *env, char *tmp);
void		change_pwd_variable(t_list *env, char *home, t_cmd *cmd, char *tmp);

/*=============================export.c============================*/
int			is_sort(t_list *elem1, t_list *elem2);
void		sort_lst(t_list *lst);
void		print_export(t_list *env);
void		export_builtin(t_data *data, t_cmd *cmd);

/*==========================export_utils.c=========================*/
int			bad_name(char *str);
int			export_error(char *arg);
void		if_char_is_plus(char *str, int i, t_data *data);
void		if_char_is_egal(char *str, int i, t_data *data);
int			check_arg_export(t_data *data, char *str);

/*===============================exit.c============================*/
long long	ft_atoll(const char *nptr);
int			is_longlong_overflow(char *str, int start, int len, int neg);
int			is_longlong(char *str);
void		change_exit_status(t_data *data, unsigned char status);
void		exit_builtins(t_data *data, t_cmd *cmd);

/*=============================echo.c==============================*/
int			only_n_option(char *str);
void		echo_print(char **arg);
void		echo_builtin(t_cmd *cmd);

/*===================================================================
								UTILS
===================================================================*/

/*==============================init.c=============================*/
t_data		init_data(void);
t_data		ft_init(char **envp);

#endif
