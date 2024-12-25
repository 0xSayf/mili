/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:49:49 by sahamzao          #+#    #+#             */
/*   Updated: 2024/12/25 17:27:17 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <fcntl.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

enum					e_data_type
{
	EXPORT,
	ENV_VAR,
	UNSET,
	STRING,
	CMD,
	PIPE,
	FILESS,
	REDERECTION_INPUT,
	REDERECTION_OUTPUT,
	APPEND_REDIRECT,
	HERDOC,
};

typedef struct env
{
	struct env			*next;
	char				*var;
	char				*to_print;
}						t_env;

typedef struct t_minishell
{
	char				*string;
	enum e_data_type	typ_e;
	char				*path;
	struct t_minishell	*next;
}						t_token;

typedef struct t_herdoc
{
	char				*delimiter;
	struct t_herdoc		*next;
}						t_herdoc;

typedef struct s_red
{
	char				*red_out;
	char				*red_input;
	char				*red_append;
	enum e_data_type	typix;
	struct s_red		*next;
}						t_red;

typedef struct t_cmd
{
	char				*cmd;
	char				*path;
	int					num_args;
	char				**args;
	bool				pipe;
	t_red				*redirection;
	t_herdoc			*herdoc;
	struct t_cmd		*next;
}						t_cmd;

char					**ft_split(char const *s, char c);
int						ft_qt(char *line);
int						ft_find(t_env *env, char *line);
char					*ft_strdup(const char *s1);
size_t					ft_strlen(const char *s);
int						ft_syntax(t_token *syntax);
char					**ft_splitix(char *line);
int						ft_check_builtins(t_token *token);
int						ft_counter(char const *str, char c);
int						ft_count(char const *str, char c);
char					*ft_strnstr(const char *hay, const char *need,
							size_t len);
char					*find_path(char *av, char *evp);
char					*ft_strjoin(char *s1, char const *s2);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					freeing(char **str);
void					*ft_handle_p_h_a_re(t_cmd *cmd, t_token *tmp);
int						ft_strcmp(char *s1, char *s2);
void					ft_lstclear(t_token **lst);
int						ft_geave_type(t_token *type, char **env);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
void					ft_lst_clr(t_env **env);
void					ft_go_del(t_env **env, char *line);
int						finder(t_env *env, char *line);
char					**ft_the_args(char **ret, t_token *start, int arg);
int						find(t_env *env, char *line);
int						ft_count_args(t_token *start, t_token *end);
int						count_command_arguments(t_token *current);
enum e_data_type		ft_type(t_token *type, char **env);
enum e_data_type		ft_type_helper(t_token *type, char **env);
t_env					*ft_creat_env(char *content);
t_env					*ft_initial_env(t_env *env, char **environment);
t_token					*ft_creat_node(char *content);
t_token					*ft_init_token_node(char **token);
t_red					*ft_cr_redir_node(t_token *token,
							enum e_data_type typ_e);
t_cmd					*ft_build_nodes(t_token *token);
t_token					*find_pipe(t_token *find);
t_cmd					*creat_cmd_node(t_token *start, t_token *end);
t_cmd					*ft_handle_herdoc(t_cmd *cmd, t_token *token);
t_cmd					*ft_handle_herdoc(t_cmd *cmd, t_token *token);
void					ft_go_execute(t_cmd *cmd);
char					*ft_pwd(void);
void					ft_freeing_cmd_node(t_cmd **cmd);
t_cmd					*ft_syntax_cmd(t_cmd *cmd);
void					ft_ret_help(char *line, char **retu, int *i,
							int *index);
int						ft_allocation(char *line, int i, char c);
void					ft_help(char *line, char **retu, int *i, int index);
int						ft_syntax_helper(t_token *tmp);
void    ft_env(t_env    *env);
t_token *ft_expand_dollar(t_token *token,t_env  *env);

#endif