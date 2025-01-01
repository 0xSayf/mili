/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 13:45:23 by sahamzao          #+#    #+#             */
/*   Updated: 2024/12/25 20:25:28 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}

char    *ft_variable(char   *str)
{
    int i;
    int j;
    char    *ptr;

    i = 0;
    j = 0;
    while (str[i] && str[i] != '=')
        i++;
    if(str[i])
    {
        ptr = malloc(i + 1);
        while (j < i)
        {
            ptr[j] = str[j];
            j++;
        }
        ptr[j] = '\0';
        return ptr;
    }
    return NULL;
}

char    *ft_search(char *string, t_env  *env)
{
    int i;
    int status;
    t_env *tmp;
    char   *str;
    
    tmp = env;
    while (tmp)
    {
        str = ft_variable(tmp->var);
        status = ft_strcmp(string,str);
        free(str);
        if(!status)
            return ft_strchr(tmp->var, '=');
        tmp = tmp->next;
    }
    return NULL;
}

t_token *ft_expand_dollar(t_token *token,t_env  *env)
{
    t_token *tmp;
    char    *ptr;
    char    *str;
    
    if(!token || !env)
        return NULL;
    tmp = token;
    while (tmp)
    {
        if (tmp->typ_e != DELIM && tmp->string)
        {
            ptr = tmp->string;
            if (ptr[0] == '$' && ptr[1] && ptr[1] != ' ' && ptr[1] != '\t')
            {
                str = ft_search(&ptr[1],env);
                if(str)
                {
                    free(tmp->string);
                    tmp->string = malloc(ft_strlen(str + 1) + 1);
                    ft_memcpy(tmp->string,str + 1,ft_strlen(str + 1));
                    tmp->string[ft_strlen(str + 1)] = '\0';
                }
            }
        }
        tmp = tmp->next;
    }
    return token;
}