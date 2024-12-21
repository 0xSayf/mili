/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing_cmd_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:56:17 by sahamzao          #+#    #+#             */
/*   Updated: 2024/12/21 11:05:28 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_freeing_cmd_node(t_cmd *cmd)
{
	t_cmd 	*tmp;
	t_cmd	*nex;

	if (!cmd)
		return ;
	tmp = cmd;
	while (tmp)
	{
		nex = tmp->next;
		freeing(tmp->args);
		free(tmp->path);
		free(tmp->cmd);
		free(tmp);
		tmp = nex;
	}
}