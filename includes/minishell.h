/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:49:49 by sahamzao          #+#    #+#             */
/*   Updated: 2024/11/26 22:14:21 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <readline/readline.h>
#include <readline/history.h>


enum data_type
{
    STRING, // N 0
    CMD,    // N 1
    PIPE,   // N 2
    FILESS,    // N 3
    REDERECTION_INPUT,  // N 4 <
    REDERECTION_OUTPUT, // N 5 >
    HERDOC, // N 6    <<
    APPEND_REDIRECT // N 7 >>
};

typedef struct env
{
    char *var;
    char *to_print;
    struct env *next;
} t_env;

typedef struct t_var
{
    int i;
    int z;
    int j;
    int k;
    int a;
    int t;
}  t_var;

typedef struct t_minishell
{
    char *string;
    enum data_type typ_e;
    struct t_minishell *next;
}   t_token;

typedef struct t_tree
{
    struct t_tree *left;
    struct t_tree *right;
    char *word;
    
} t_tree;

char	**ft_split(char const *s, char c);
t_env     *ft_creat_env(char  *content);
int ft_qt(char *line);
int		ft_find(t_env *env, char *line);
t_env    *ft_initial_env(t_env   *env, char **environment);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
t_token     *ft_creat_node(char  *content);
t_token    *ft_init_token_node(char **token);
int	ft_syntax(t_token *syntax);
char **ft_splitix(char *line);
int	ft_counter(char const *str, char c);
int	ft_count(char const *str, char c);
enum data_type ft_type(t_token *type,char **env);
char	*ft_strnstr(const char *hay, const char *need, size_t len);
int	find_path(char *av, char *evp);
char	*ft_strjoin(char  *s1, char const *s2);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	freeing(char **str);
int	ft_strcmp(char *s1, char *s2);
void    del(char *string);
void	ft_lstclear(t_token **lst, void (*del)(char *));
int	ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_lst_clr(t_env **env);
void    ft_expand(char **line, t_env *env);
void	ft_go_del(t_env **env, char *line);
int	finder(t_env *env, char *line);
int	find(t_env *env, char *line);

#endif