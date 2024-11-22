/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 20:48:31 by sahamzao          #+#    #+#             */
/*   Updated: 2024/11/22 21:34:24 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void    ft_initial_env(t_env   *env, char **environment)
{
    t_env *tmp;
    int     i;
    
    tmp = NULL;
    if(!env)
    {
        env = ft_creat_env(environment[0]);
        tmp = env;
    }
    tmp = env;
    i = 1;
    while (environment[i])
    {
        tmp->next = ft_creat_env(environment[i]);
        tmp = tmp->next;
        i++;
    }
    while(env)
        {
            printf(">>>>>>>>.......%s\n", env->var);
            env = env->next;
        }
}