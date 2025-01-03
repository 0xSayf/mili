/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:59:39 by sahamzao          #+#    #+#             */
/*   Updated: 2024/12/22 15:46:04 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (!n)
		return (0);
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	find(t_env *env, char *line)
{
	t_env	*tmp;

	if (!env)
		return (0);
	tmp = env;
	while (tmp)
	{
		if (ft_strcmp(tmp->var, line) == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	finder(t_env *env, char *line)
{
	t_env	*tmp;

	if (!env)
		return (0);
	tmp = env;
	while (tmp)
	{
		if (ft_strncmp(tmp->var, line, 2) == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	ft_go_del(t_env **env, char *line)
{
	t_env	*tmp;
	t_env	*last;

	if (!env || !*env)
		return ;
	tmp = *env;
	if (ft_strncmp(tmp->var, line, 2) == 0)
	{
		*env = tmp->next;
		free(tmp);
		return ;
	}
	while (tmp && tmp->next)
	{
		last = tmp;
		tmp = tmp->next;
		if (ft_strncmp(tmp->var, line, 2) == 0)
		{
			last->next = tmp->next;
			free(tmp);
			return ;
		}
	}
}

int	ft_check_builtins(t_token *token)
{
	char	*ptr[4];
	int		i;

	if (!token)
		return (0);
	ptr[0] = "exit";
	ptr[1] = "export";
	ptr[2] = "unset";
	ptr[3] = NULL;
	i = 0;
	while (ptr[i])
	{
		if (ft_strcmp(ptr[i], token->string) == 0)
			return (1);
		i++;
	}
	return (0);
}

