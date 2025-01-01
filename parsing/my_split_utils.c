/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_split_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 13:36:48 by sahamzao          #+#    #+#             */
/*   Updated: 2024/12/23 18:33:35 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_ret_help(char *line, char **retu, int *i, int *index)
{
	int		j;
	int		len;
	char	v;
	int		save;

	j = 0;
	v = line[*i];
	len = 0;
	while (line[*i] && line[*i] != 32)
	{
		while (line[*i] && line[*i] == v)
			(*i)++;
		while (line[*i] && line[*i] != v)
		{
			len++;
			(*i)++;
		}
	}
	retu[*index] = malloc(len++);
	// printf("len      ==  %d\n", len);
	save = *i - 1;
	// printf("save      ==  %d\n", save);
	while (len > 0 )
	{
		if(line[save - len] != v)
		{
			retu[*index][j] = line[save - len];
			len--;
			j++;
		}
		else
			save++;
	}
	retu[*index][j] = '\0';
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
		if (line[*i] == 34 || line[*i] == 39)
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
