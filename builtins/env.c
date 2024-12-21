#include "../includes/minishell.h"

void    ft_env(t_env    *env)
{
    t_env   *tmp;

    if(!env)
        return;
    tmp = env;
    while(tmp)
    {
        if(tmp->var)
            printf("%s\n", tmp->var);
        tmp = tmp->next;
    }
}