/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_go.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:59:49 by sahamzao          #+#    #+#             */
/*   Updated: 2024/12/20 16:09:32 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_token	*ft_init_token_node(char **token)
{
	t_token	*linked;
	t_token	*first;
	int		i;

	if (!token)
		return (NULL);
	linked = NULL;
	first = NULL;
	if (linked == NULL)
	{
		linked = ft_creat_node(token[0]);
		first = linked;
	}
	i = 1;
	while (token[i])
	{
		first->next = ft_creat_node(token[i]);
		first = first->next;
		i++;
	}
	freeing(token);
	return (linked);
}

int	ft_geave_type(t_token *type, char **env)
{
	t_token *tmp;

	if (!type || !type->string)
		return (0);
	tmp = type;
	while (tmp)
	{
		tmp->typ_e = ft_type(tmp, env);
		tmp = tmp->next;
	}
	return (1);
}