/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checking.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:53:52 by sahamzao          #+#    #+#             */
/*   Updated: 2024/11/20 12:13:02 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

enum data_type ft_type(t_token *type,char **env)
{
    int i;

    i = 0;
    while (ft_strnstr(env[i],"PATH", 4) == NULL)
        i++;
    if(find_path(type->string,env[i]) == 1)
        return CMD;
        
    return STRING;
}

int	find_path(char *av, char *evp)
{
	char	**paths;
	char	*ret;
	int		i;
	char	**av_cmd;

	i = 0;
	av_cmd = ft_split(av, ' ');
	paths = ft_split(evp + 5, ':');
	while (paths[i])
	{
		ret = ft_strjoin(paths[i], "/");
		ret = ft_strjoin(ret, av_cmd[0]);
		if (access(ret, F_OK && X_OK) == 0)
		{
			free(ret);
			freeing(paths);
			return (1);
		}
		else
			i++;
	}
	free(ret);
	freeing(paths);
	return (0);
}