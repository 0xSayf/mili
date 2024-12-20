/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:50:01 by sahamzao          #+#    #+#             */
/*   Updated: 2024/12/20 18:03:24 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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
		{
			v = str[i];
			while (str[i] == v && str[i])
				i++;
			while (str[i] && str[i] != v)
				i++;
		}
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
	int		index;
	int		len;
	int		ten;
	int		i;
	int		j;
	char	v;
	char	quote;

	index = 0;
	i = 0;
	while (index < word)
	{
		ten = 0;
		len = 0;
		j = 0;
		while (line[i] == c)
			i++;
		if (line[i] == 34 || line[i] == 39)
		{
			v = line[i];
			while (line[i] == v && line[i])
				i++;
			while (line[i] && line[i] != v)
			{
				len++;
				i++;
			}
			retu[index] = malloc(len + 1);
			while (len > 0)
			{
				retu[index][j] = line[i - len];
				len--;
				j++;
			}
			retu[index][j] = '\0';
			while (line[i] == v)
				i++;
		}
		else
		{
			while (line[i] && line[i] == c)
				i++;
			retu[index] = malloc(256);
			while (line[i])
			{
				if (line[i] == '\'' || line[i] == '\"')
				{
					quote = line[i];
					i++;
					while (line[i] && line[i] != quote)
						retu[index][j++] = line[i++];
					if (line[i] == quote)
						i++;
				}
				else if (line[i] == c)
					break ;
				else
					retu[index][j++] = line[i++];
			}
			retu[index][j] = '\0';
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