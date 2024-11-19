/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:50:01 by sahamzao          #+#    #+#             */
/*   Updated: 2024/11/19 12:02:18 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_counter(char const *str, char c)
{
	int	count;
	int	i;
    char v;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i])
	{
        if(str[i] == 34 || str[i] == 39)
        {
            v = str[i];
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

char **ft_ret(char *line, char **retu, char c, int word)
{
	int index;
	int len;
	int i;
	int j;
	char v;
	
	index = 0;
	i = 0;
	printf("%d\n", word);
	while (index < word)
	{
		len = 0;
		j = 0;
		while (line[i] == c)
			i++;
		if(line[i] == 34 || line[i] == 39)
		{
			v = line[i];
			i++;
			while (line[i] == c)
				i++;
			while (line[i] && line[i] != v )
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
		}
		else
		{
			while (line[i] && line[i] == c)
				i++;
			while (line[i] && line[i] != c)
			{
				i++;
				len++;
			}
			retu[index] = malloc(len + 1);
			while (len > 0)
			{
				retu[index][j] = line[i - len];
				len--;
				j++;
			}
			retu[index][j] = '\0';
		}
		index++;
	}
	retu[index] = NULL;
	return (retu);
}

char **ft_splitix(char *line)
{
    int word;
	char	**retu;
	
	word = ft_counter(line,32);
	retu = malloc(sizeof(char *) * (word + 1));
	retu = ft_ret(line,retu,32,word);
	return retu;
}