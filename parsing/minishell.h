/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:49:49 by sahamzao          #+#    #+#             */
/*   Updated: 2024/11/21 16:49:15 by sahamzao         ###   ########.fr       */
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
    REDERECTION_FILE,    // N 3
    REDERECTION_INPUT,  // N 4
    REDERECTION_OUTPUT, // N 5
    HERDOC, // N 6    
    APPEND_REDIRECT // N 7
};

typedef struct minishell
{
    char *string;
    enum data_type typ_e;
    struct minishell *next;
}   t_token;

char	**ft_split(char const *s, char c);
int ft_qt(char *line);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
t_token     *ft_creat_node(char  *content);
t_token    *ft_init_token_node(char **token);
void	ft_syntax(t_token *syntax);
char **ft_splitix(char *line);
int	ft_counter(char const *str, char c);
int	ft_count(char const *str, char c);
enum data_type ft_type(t_token *type,char **env);
char	*ft_strnstr(const char *hay, const char *need, size_t len);
int	find_path(char *av, char *evp);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	freeing(char **str);

#endif