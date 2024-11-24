/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 20:28:23 by sahamzao          #+#    #+#             */
/*   Updated: 2024/11/24 20:52:25 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_tree    *ft_build_tree (t_token *token)
{
    t_token *tmp;
    t_tree  *tree;
    
    tmp = token;
    while (tmp)
    {
        if(tmp->typ_e == PIPE)
            break;
        tmp = tmp->next;
    }
    tree = ft_build_casual(token);
}

t_tree    *ft_build_casual(t_token *token)
{
    t_tree *tree;
    t_token *tmp;

    tmp = token;
    while (tmp)
    {
        
    }
    
    return (tree);
}