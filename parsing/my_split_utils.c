/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_split_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 13:36:48 by sahamzao          #+#    #+#             */
/*   Updated: 2024/12/22 18:41:22 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_ret_help(char *line, char **retu, int *i, int *index)
{
	int		j;
	int		len;
	char	v;

	j = 0;
	v = line[*i];
	len = 0;
	while (line[*i] && line[*i] == v)
		(*i)++;
	while (line[*i] && line[*i] != v)
	{
		len++;
		(*i)++;
	}
	retu[*index] = malloc(len + 1);
	while (len > 0)
	{
		retu[*index][j] = line[*i - len];
		len--;
		j++;
	}
	retu[*index][j] = '\0';
	while (line[*i] == v)
		(*i)++;
}

void	ft_hhhhhhhhhhh(int *i, int *len)
{
	(*i)++;
	(*len)++;
}

int	ft_allocation(char *line, int i, char c)
{
	int		len;
	char	quote;

	len = 0;
	while (line[i])
	{
		if (line[i] == '"' || line[i] == '\'')
		{
			quote = line[i];
			i++;
			while (line[i] && line[i] != quote)
			{
				len++;
				i++;
			}
			if (line[i] == quote)
				i++;
		}
		else if (line[i] == c)
			break ;
		else
			ft_hhhhhhhhhhh(&i, &len);
	}
	return (len);
}

void	ft_help(char *line, char **retu, int *i, int index)
{
	int		j;
	char	quote;

	j = 0;
	while (line[*i])
	{
		if (line[*i] == '"' || line[*i] == '\'')
		{
			quote = line[*i];
			(*i)++;
			while (line[*i] && line[*i] != quote)
				retu[index][j++] = line[(*i)++];
			if (line[*i] == quote)
				(*i)++;
		}
		else if (line[*i] == 32)
			break ;
		else
			retu[index][j++] = line[(*i)++];
	}
	retu[index][j] = '\0';
}
