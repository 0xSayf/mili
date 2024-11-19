/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:49:18 by sahamzao          #+#    #+#             */
/*   Updated: 2024/11/19 16:08:08 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token    *ft_init_token_node(char **token)
{
    t_token *linked;
    t_token *first;
    int i;
    
    linked = NULL;
    first  = linked;
    if(linked == NULL)
    {
        linked = ft_creat_node(token[0]);
        printf("%s\n", linked->string);
    }
    i = 1;
    while(token[i])
    {
        linked->next = ft_creat_node(token[i]);
        linked = linked->next;
         printf("%s\n", linked->string);
        i++;
    }
    return first;
}

int main (int ac , char **av, char **env)
{
    char *line;
    char **token;
    t_token *sir;
    while (1)
    {
        line = readline("minishell % >>>>>    ");
        token = ft_splitix(line);
        ft_init_token_node(token);
        // printf("%s\n", sir->string);
    }
}