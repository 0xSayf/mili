/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_cmd_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:52:45 by sahamzao          #+#    #+#             */
/*   Updated: 2024/12/22 18:39:20 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_count_args(t_token *start, t_token *end)
{
	t_token	*tmp;
	int		i;

	if (!start)
		return (0);
	tmp = NULL;
	tmp = start;
	i = 0;
	while ((tmp) && (tmp->typ_e != PIPE))
	{
		if (tmp->typ_e == CMD || tmp->typ_e == STRING || tmp->typ_e == FILESS)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

t_cmd	*ft_build_nodes(t_token *token)
{
	int		k;
	t_token	*tmp;
	t_token	*start;
	t_token	*end;
	t_cmd	*cmd;
	t_cmd	*exec;

	if (!token)
		return (NULL);
	cmd = NULL;
	exec = NULL;
	tmp = token;
	if (!cmd)
	{
		start = token;
		end = find_pipe(token);
		if (!end)
			k = 0;
		else
			k = 1;
		cmd = creat_cmd_node(start, end, k);
		exec = cmd;
	}
	while (tmp && end && end->next)
	{
		start = end->next;
		tmp = end->next;
		end = find_pipe(tmp);
		if (!end)
			k = 0;
		else
			k = 1;
		exec->next = creat_cmd_node(start, end, k);
		exec = exec->next;
	}
	return (cmd);
}
