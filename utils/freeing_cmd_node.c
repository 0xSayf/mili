/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing_cmd_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:56:17 by sahamzao          #+#    #+#             */
/*   Updated: 2024/12/21 11:14:00 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_free_herdoc(t_herdoc *tmp)
{
	t_herdoc	*her;
	t_herdoc	*nex;

	if(!tmp)
		return;
	her = tmp;
	while(her)
	{
		nex = her->next;
		free(her->delimiter);
		free(her);
		her = nex;		
	}
}

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
		if(tmp->herdoc)
			ft_free_herdoc(tmp->herdoc);
		freeing(tmp->args);
		free(tmp->path);
		free(tmp->cmd);
		free(tmp);
		tmp = nex;
	}
}