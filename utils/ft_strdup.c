/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:57:52 by sahamzao          #+#    #+#             */
/*   Updated: 2024/12/22 15:25:46 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int i;
	int size;
	char *ptr;

	i = 0;
	if(!s1)
		return NULL;
	size = ft_strlen(s1) + 1;
	ptr = malloc(size);
	if (ptr == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

t_cmd *ft_syntax_cmd(t_cmd *com)
{
    t_cmd *tmp;

    if (!com)
        return NULL;
    tmp = com;
    if (tmp->cmd)
    {
        if (!tmp->path)
        {
			if (access(tmp->cmd, F_OK | X_OK) != 0)
			{
				printf("CMD not found\n");
				return tmp->next;
			}
		}
	}
	else
		printf("Syntax error: Command is NULL.\n");
    return NULL;    
}

