/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:23:05 by sahamzao          #+#    #+#             */
/*   Updated: 2024/11/25 21:33:08 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void    ft_expand(char **line, t_env *env)
{
    int i;
    t_env *tmp;
    
    i = 0;
    if(!line || !env)
        return ;
    tmp = env;
    while (tmp->next != NULL)
        tmp = tmp->next;
    while (line[i])
    {
        if(ft_strcmp(line[i],"export") == 0 && line[i+1])
        {
            if(!ft_finder(env,line[i+1]) || !ft_find(env,line[i+1]))
            {
                tmp->next = ft_creat_env(ft_strdup(line[i+1]));
                tmp = tmp->next;
            }
            else if (ft_finder(env,line[i+1]) && ft_find(env,line[i+1]))
            {
                ft_go_del(env,line[i+1]);
            }
        }
        i++;
    }
    t_env *tt;
    tt = env;
    while (tt)
    {
        printf("%s\n", tt->var);
        tt = tt->next;
    }
    
}