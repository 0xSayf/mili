/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:49:49 by sahamzao          #+#    #+#             */
/*   Updated: 2024/11/19 15:59:22 by sahamzao         ###   ########.fr       */
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


#endif