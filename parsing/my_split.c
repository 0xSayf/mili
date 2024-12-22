/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:50:01 by sahamzao          #+#    #+#             */
/*   Updated: 2024/12/22 15:16:07 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_counter_help(char const *str, int *i)
{
	char	v;

	v = str[*i];
	while (str[*i] == v && str[*i])
		(*i)++;
	while (str[*i] && str[*i] != v)
		(*i)++;
}

int	ft_counter(char const *str, char c)
{
	int		count;
	int		i;
	char	v;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == 34 || str[i] == 39)
			ft_counter_help(str, &i);
		if (str[i] == c)
			i++;
		else
		{
			count++;
			i++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

char	**ft_ret(char *line, char **retu, char c, int word)
{
	int	index;
	int	i;

	index = 0;
	i = 0;
	while (index < word)
	{
		while (line[i] == c)
			i++;
		if (line[i] == '"' || line[i] == '\'')
			ft_ret_help(line, retu, &i, &index);
		else
		{
			retu[index] = malloc(ft_allocation(line, i, c) + 1);
			ft_help(line, retu, &i, index);
		}
		index++;
	}
	retu[index] = NULL;
	return (retu);
}

char	**ft_splitix(char *line)
{
	int word;
	char **retu;

	if (!line)
		return (NULL);
	add_history(line);
	if (ft_qt(line) == 0)
	{
		printf("syntax error\n");
		free(line);
		return (NULL);
	}
	word = ft_counter(line, 32);
	retu = malloc(sizeof(char *) * (word + 1));
	retu = ft_ret(line, retu, 32, word);
	free(line);
	return (retu);
}