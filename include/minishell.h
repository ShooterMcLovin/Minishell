/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:37:50 by alpicard          #+#    #+#             */
/*   Updated: 2025/05/04 10:54:54 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../Readline/history.h"
# include "../Readline/readline.h"
# include "../libft/include/libft.h"
# include <fcntl.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define PROMPT "Minishell-1.1$ "
# define HEREDOC "heredoc > "
# define EMPTY 0
# define CMD 1
# define ARGS 2
# define PIPE 3
# define REDIR_IN 4
# define REDIR_OUT 5
# define REDIR_DBL 9
# define REDIR_DBL2 10
# define HEREDOC_T 10
# define ABS 6
# define FILE_OUT 7
# define INTERACTIVE 11
# define CHILD 12
# define HD_SIG 13

typedef struct s_token
{
	int					token_no;
	int					type;
	char				**cmd;
	char				*next_sep;
	pid_t				child_pid;
	pid_t				pid;
	int					p_fd[2];
	int					fd_in;
	int					fd_out;
	int					fd_hd;
	struct s_environ	*env;
	struct s_mini		*mini;
	struct s_token		*next;
}						t_token;

typedef struct s_mini
{
	char				*input;
	char				**cmds;
	char				**new_cmds;
	int					no_wrds;
	char				**env;
	char				*shlvl;
	int					env_len;
	t_token				*heredoc_temp;
	struct s_environ	*env_test;
	struct s_export		*_export;
	struct s_token		*tokens;
	int					no_of_tokens;
}						t_mini;

typedef struct s_environ
{
	char				**temp;
	char				*env_var;
	char				*env_val;
	struct s_environ	*next;
}						t_environ;

typedef struct s_export
{
	char				**temp;
	char				*env_var;
	char				*env_val;
	struct s_export		*next;
}						t_export;

int						g_errno;

/*Builtins*/
int						ft_echo(t_token *token);
int						ft_pwd(t_token *token);
int						ft_env(t_token *token);
void					set_env(t_mini *mini, char **env);
int						ft_cd(t_mini *mini, t_token *token);
int						update_env_part3(t_mini *mini, char *part, char *_new);
char					*get_env_part(t_mini *mini, char *part);
int						ft_unset(t_token *token);
int						ft_export(t_mini *mini, char **var);
int						ft_builtins(t_token *token);
int						is_builtin(t_token *token);
int						export_no_input(t_mini *mini);
int						check_export(char **var);
int						check_input(t_mini *mini);
void					init_export(t_mini *mini, char **var);

/*Parse*/
t_token					*init_tokens(t_mini *mini, int cmd_index, int x);
int						ft_parse(t_mini *mini);
int						is_empty(char *input);
int						is_char_sep(int c);
int						tokeniser(t_mini *mini);
char					**env_l_to_dbl_arr(t_environ *env);
char					*check_part(char *part);
int						check_valid_quotes(char *input);
int						has_dollar_sign(char *input);
int						dollar_len(char *input);
char					*dollar_sign(char *mini_cmd);
int						has_quotes(char *str);
int						check_cmd(t_token *token);
int						check_file_exists(t_token *token);
void					set_mini_no_wrds(void);

/*Env*/

int						set_shlvl(void);
t_environ				*new_env(char *var);
t_environ				*ft_envlast(t_environ *env);
t_environ				*init_item(char *to_split);
void					ft_envadd_back(t_environ **env, t_environ *neo);
void					print_env(t_environ *environ);
void					do_export(t_mini *mini, char **var);
int						ft_set_env(t_mini *mini, char **env);

/*Mini_split*/
int						no_of_words(char *s, int trigger, int i, int no_wrds);
char					**mini_split(char *s);

/*Execute*/
t_mini					*get_data(void);
void					exec_and_stuff(t_token *token);
void					exec_and_stuff2(t_token *token);
char					*get_path(t_token *token);
void					absolute_path(t_token *token);
int						exec(t_token *token);
void					wait_pids(t_token *token);
int						do_heredoc(t_token *token);
int						heredoc(t_token *token);
void					do_pipe3(t_token *token);
void					do_pipe2(t_token *token);
void					do_pipe(t_token *token);
void					do_pipe_cat(t_token *token);
void					dup2_0(t_token *token);
void					dup2_1(t_token *token);
void					redir(t_token *token);
void					redir2(t_token *token);
void					child_redir_to(t_token *token);
void					redir_append(t_token *token);

/*Utils*/
char					*get_prompt(char *prt);
char					*get_hd_prompt(char *prt);
int						is_sep(char *str);
int						is_sep2(char *str);
int						is_quote(int c);
int						ft_isspace(int c);

/*Signals*/
void					init_signals(int mode);

/*Errors*/
int						set_error(t_token *token);
int						syntax_error(void);
int						invalid_path(char *error);
int						command_not_found(char *error);
int						is_a_directory(char *error);
int						update_error(t_mini *mini);
int						ft_exit(char **cmds);
int						launch_fail(char **env);

/*Free*/
void					*releaser(char **table);
void					free_tokens(t_token *tokens);
void					free_env(t_environ *env);
int						free_minishell(t_mini *mini);
void					free_export(t_export *exp);
void					free_child(t_mini *mini);

#endif
