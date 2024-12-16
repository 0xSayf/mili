/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_node_tree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 20:57:46 by sahamzao          #+#    #+#             */
/*   Updated: 2024/11/24 21:30:23 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"



t_token *find_pipe(t_token *find)
{
    t_token *tmp;

    if(!tmp)
        return NULL;
    tmp = find;
    while (tmp)
    {
        if(tmp->typ_e == PIPE)
            return tmp;
        tmp = tmp->next;
    }
    return NULL;
}