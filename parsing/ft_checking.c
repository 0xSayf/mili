/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checking.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:53:52 by sahamzao          #+#    #+#             */
/*   Updated: 2024/11/20 12:28:03 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

enum data_type ft_type(t_token *type,char **env)
{
    int i;
	int fd;
	
    i = 0;
	
    while (ft_strnstr(env[i],"PATH", 4) == NULL)
        i++;
    if(find_path(type->string,env[i]) == 1)
        return CMD;
    else if((fd = open(type->string, O_RDONLY, 0777)) != -1)
	{
		close(fd);
		return REDERECTION_FILE;  
	}
	else if(*(type->string) == '|')
		return PIPE;
    return STRING;
}

int	find_path(char *av, char *evp)
{
	char	**paths;
	char	*ret;
	int		i;
	char	**av_cmd;

	if(!av || !evp)
		return 0;
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
		i++;
	}
	free(ret);
	freeing(paths);
	return (0);
}