/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:49:49 by sahamzao          #+#    #+#             */
/*   Updated: 2024/11/20 12:04:23 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>


enum data_type
{
    STRING,
    CMD,
    PIPE,
    REDERECTION_FILE        
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