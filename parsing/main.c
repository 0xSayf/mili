/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:49:18 by sahamzao          #+#    #+#             */
/*   Updated: 2024/11/22 21:44:21 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_token    *ft_init_token_node(char **token)
{
    t_token *linked;
    t_token *first;
    int i;
    
    linked = NULL;
    first  = NULL;
    if(linked == NULL)
    {
        linked = ft_creat_node(token[0]);
        first = linked;
    }
    i = 1;
    while(token[i])
    {
        first->next = ft_creat_node(token[i]);
        first = first->next;
        i++;
    }
    return linked;
}

void    ft_geave_type(t_token *type,char **env)
{
    t_token *tmp;

    tmp = type;
    while(tmp)
    {
        tmp->typ_e = ft_type(tmp,env);
        tmp = tmp->next;    
    }
}
void ll()
{
    system("leaks minishell");
}
int main (int ac , char **av, char **env)
{
    char *line;
    char **token;
    t_token *sir;
    t_env   *evv;
    atexit(ll);
    
    while (1)
    {
        line = readline("minishell % >>>>>    ");
        if(ft_qt(line) == 0)
            printf("syntax error\n");
        token = ft_splitix(line);
        sir = ft_init_token_node(token);
        ft_geave_type(sir,env);
        ft_syntax(sir);
        ft_initial_env(evv,env);
        ft_lstclear(&sir,&del);
        free(token);
        
        exit(0);
    }
}