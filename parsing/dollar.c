/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 13:45:23 by sahamzao          #+#    #+#             */
/*   Updated: 2024/12/24 16:06:36 by sahamzao         ###   ########.fr       */
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

char    *ft_search(char *string, t_env  *env)
{
    int i;
    int status;
    t_env *tmp;

    tmp = env;
    while (tmp)
    {
        status = ft_strncmp(string,tmp->var,ft_strlen(string));
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
        if (tmp->string)
        {
            ptr = tmp->string;
            if (ptr[0] == '$' && ptr[1])
            {
                str = ft_search(&ptr[1],env);
                if(str)
                {
                    free(tmp->string);
                    tmp->string = malloc(ft_strlen(str + 1) + 1);
                    ft_memcpy(tmp->string,str + 1,ft_strlen(str + 1));
                    tmp->string[ft_strlen(str+ 1)] = '\0';
                }
            }
        }
        tmp = tmp->next;
    }
    return token;
}