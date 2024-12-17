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

t_cmd   *creat_cmd_node(t_token *start, t_token *end, int k)
{
    t_cmd *new;

    if(!start)
        return NULL;
    new = malloc(sizeof(t_cmd));
    if(!new)
        return NULL;
    if (!k)
        new->pipe = false;
    else
        new->pipe = true;
    new->cmd = start->string;
    new->num_args = ft_count_args(start, end);
    new->args = malloc(sizeof(char *) * (new->num_args + 1));
    new->args = ft_the_args(new->args,start,new->num_args);
    new->path = start->path; 
    new->file_input = NULL;
    new->file_output = NULL;
    new->file_append = NULL;    
    new->t_herdoc = NULL;
    new->next = NULL;
    return new;
}