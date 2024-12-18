/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_cmd_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:52:45 by sahamzao          #+#    #+#             */
/*   Updated: 2024/12/18 10:52:47 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char    **ft_the_args(char **ret,t_token *start, int arg)
{
    t_token *s;
    size_t     i;

    if(!ret || !start || !arg)
        return NULL;
    s = start;
    i = 0;
    while (s && (i < arg) && (s->typ_e != PIPE))
    {
        ret[i] = malloc(ft_strlen(s->string) + 1);
        ret[i][ft_strlen(s->string)] = '\0';
        if(s->typ_e == CMD || s->typ_e == STRING)
        {
            ft_memcpy(ret[i], s->string, ft_strlen(s->string) + 1);
            i++;
        }
        s = s->next;
    }
    ret[i] = NULL;
    return ret;
}

int ft_count_args(t_token *start , t_token *end)
{
    t_token *tmp;
    int     i;

    if(!start)
        return 0;
    tmp = NULL;
    tmp = start;
    i = 0;
    while ((tmp) && (tmp->typ_e != PIPE ))
    {
        if(tmp->typ_e == CMD || tmp->typ_e == STRING || tmp->typ_e == FILESS)
            i++;
        tmp = tmp->next;
    }
    return i;
}

t_cmd   *ft_build_nodes(t_token *token)
{
    t_token *tmp;
    t_token *start;
    t_token *end;
    t_cmd   *cmd;
    t_cmd   *exec;
    int     k;

    if(!token)
        return NULL;
    cmd = NULL;
    exec = NULL;
    tmp = token;
    if(!cmd)
    {
        start = token;
        end = find_pipe(token);
        if(!end)
            k = 0;
        else
            k = 1;
        cmd = creat_cmd_node(start, end,k);
        exec = cmd;
    }
    while(tmp && end && end->next)
    {
        start = end->next;
        tmp = end->next;
        end = find_pipe(tmp);
        if(!end)
            k = 0;
        else
            k = 1;
        exec->next = creat_cmd_node(start, end,k);
        exec = exec->next;
    }
    return cmd;
}