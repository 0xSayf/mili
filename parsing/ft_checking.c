/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checking.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:53:52 by sahamzao          #+#    #+#             */
/*   Updated: 2024/12/23 11:55:28 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

enum e_data_type	ft_type(t_token *type, char **env)
{
	if (ft_type_helper(type, env) == CMD || ft_type_helper(type, env) == FILESS)
		return (ft_type_helper(type, env));
	else if (*(type->string) == '|')
		return (PIPE);
	else if (*(type->string) == '<')
	{
		if (!ft_strcmp(type->string, "<<"))
			return (HERDOC);
		return (REDERECTION_INPUT);
	}
	else if (*(type->string) == '>')
	{
		if (!ft_strcmp(type->string, ">>"))
			return (APPEND_REDIRECT);
		return (REDERECTION_OUTPUT);
	}
	else if (ft_strcmp(type->string, "export") == 0)
		return (EXPORT);
	else if (ft_strcmp(type->string, "unset") == 0)
		return (UNSET);
	return (STRING);
}

char	*find_path(char *av, char *evp)
{
	char	**paths;
	char	*ret;
	int		i;

	if (!av || !evp)
		return (0);
	i = 0;
	paths = ft_split(evp + 5, ':');
	while (paths[i])
	{
		ret = ft_strjoin(paths[i], "/");
		ret = ft_strjoin(ret, av);
		if (access(ret, F_OK && X_OK) == 0)
		{
			while (paths[i++])
				free(paths[i]);
			free(paths);
			return (ret);
		}
		i++;
		free(ret);
	}
	free(paths);
	return (NULL);
}

int	ft_qt(char *line)
{
	int		i;
	int		num;
	char	c;

	i = 0;
	num = 0;
	while (line[i] && i < ft_strlen(line))
	{
		if (line[i] == 34 || line[i] == 39)
		{
			num++;
			c = line[i];
			i++;
			while (line[i] != c && line[i])
				i++;
			if (line[i] == c)
				num++;
			if (num % 2 != 0)
				return (0);
		}
		i++;
	}
	return (1);
}

int	ft_check_dollar(t_token *token)
{
	int		i;
	char	*str;

	if (!token)
		return (1);
	str = token->string;
	i = 0;
	if (str[i] < 'a' || str[i] > 'z')
	{
		if (str[i] != '$')
			return (0);
	}
	return (1);
}

int	ft_syntax(t_token *syntax)
{
	t_token	*tmp;

	if (!syntax || !syntax->string)
		return (0);
	tmp = syntax;
	if (*(tmp->string) == '|')
	{
		printf("syntax error\n");
		return (0);
	}
	while (tmp)
	{
		if (ft_syntax_helper(tmp) == 0)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
