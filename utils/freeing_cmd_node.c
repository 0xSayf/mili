/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing_cmd_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:56:17 by sahamzao          #+#    #+#             */
/*   Updated: 2024/12/20 16:04:51 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_freeing_cmd_node(t_cmd *cmd)
{
	t_cmd *tmp;

	if (!cmd)
		return ;
	tmp = cmd;
	while (tmp)
	{
		freeing(tmp->args);
		free(tmp->path);
		free(tmp->cmd);
		tmp = tmp->next;
	}
}