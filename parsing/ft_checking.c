/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checking.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:53:52 by sahamzao          #+#    #+#             */
/*   Updated: 2024/11/21 16:51:53 by sahamzao         ###   ########.fr       */
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
		return FILESS;  
	}
	else if(*(type->string) == '|')
		return PIPE;
	else if(*(type->string) == '<')
	{
		if(!ft_strcmp(type->string, "<<"))
			return HERDOC;
		return REDERECTION_INPUT;
	}
	else if(*(type->string) == '>')
	{
		if(!ft_strcmp(type->string, ">>"))
			return APPEND_REDIRECT;
		return REDERECTION_OUTPUT;
	}
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

int ft_qt(char *line)
{
	int i;
	int len;
	int num;
	char c;

	i = 0;
	num = 0;
	len = ft_strlen(line);
	while(line[i] && i < len)
	{
		if(line[i] == 34 || line[i] == 39)
		{
			num++;
			c = line[i];
			i++;
			while(line[i] != c && line[i])
				i++;
			if(line[i] == c)
				num++;
			if(num % 2 != 0)
				return 0;
		}
		i++;
	}
	return 1;
}

void	ft_syntax(t_token *syntax)
{
	int i;
	t_token *tmp;


	i = 0;
	if(!i && *(syntax->string) == '|')
		printf("syntax error\n");
	tmp = syntax;
	while (tmp)
	{
		if(tmp->typ_e == PIPE && !tmp->next)
			printf("syntax errors\n");
		else if (tmp->typ_e == REDERECTION_INPUT && !tmp->next)
			printf("Syntax Error : No such file or directory\n");
		tmp = tmp->next;
	}
}