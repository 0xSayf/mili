/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:38:37 by sahamzao          #+#    #+#             */
/*   Updated: 2024/11/22 11:01:30 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_token     *ft_creat_node(char  *content)
{
    t_token *new;
    
    new = (t_token *)malloc(sizeof(t_token));
    if(!new)
        return NULL;
    new->string = content;
    new->next = NULL;
    return new;
}

