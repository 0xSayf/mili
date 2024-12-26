#include "../includes/minishell.h"

void    ft_echo(char    *str, t_env *env)
{
    t_env   *tmp;
    t_env   *tot;
    char    *is;

    if(!str || !env)
        return;
    tmp = env;
    tot = env;
    if(str[0] = '$')
    {
        if(!str[1])
            write(1, "\n", 1);
        else if(str[1])
        {
            while (tmp)
            {
                if(ft_strcnmp(tmp->var,str[1], ft_strlen(str[1])) == 0)
                {
                    is = tmp->var;
                    break;
                }
                tmp = tmp->next;
            }
            
        }
        
    }
}