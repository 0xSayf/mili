#include "../includes/minishell.h"

char    *ft_pwd(void)
{
    char str_pwd[PATH_MAX];
    
    if (getcwd(str_pwd, sizeof(str_pwd)) == NULL)
        return NULL;
    return str_pwd;
}