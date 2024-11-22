/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:23:05 by sahamzao          #+#    #+#             */
/*   Updated: 2024/11/23 22:43:35 by sahamzao         ###   ########.fr       */
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
            if(ft_find(tmp,line[i+1]) == 0)
            {
                tmp->next = ft_creat_env(ft_strdup(line[i+1]));
                tmp = tmp->next;
            }
        }
        i++;
    }
}