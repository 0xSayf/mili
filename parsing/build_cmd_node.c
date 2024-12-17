#include "../includes/minishell.h"

// char    
int ft_count_args(t_token *start , t_token *end)
{
    t_token *tmp;
    int     i;

    if(!start)
        return 0;
    tmp = start;
    i = 0;
    while ((tmp < end) && (tmp))
    {
        if(tmp->typ_e == CMD || tmp->typ_e == STRING || tmp->typ_e == FILESS)
            i++;
        tmp = tmp->next;
    }
    return i;
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
    if(start->typ_e == CMD)
        new->cmd = start->string;
    else
        new->cmd = NULL;
    new->num_args = ft_count_args(start, end);
    new->args = malloc(sizeof(char*) * (new->num_args + 1));
    // new->args = ft_the_args(new->args,start,end,new->num_args);
    new->path = start->path; 
    new->next = NULL;
    return new;
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