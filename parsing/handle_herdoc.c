/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_herdoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:36:51 by sahamzao          #+#    #+#             */
/*   Updated: 2024/12/20 15:50:14 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_herdoc	*create_herdoc_node(t_token *token)
{
	t_herdoc	*new;

	if (!token)
		return (NULL);
	new = malloc(sizeof(t_herdoc));
	if (!new)
		return (NULL);
	new->delimiter = ft_strdup(token->string);
	new->next = NULL;
	return (new);
}

t_herdoc	*ft_check_herdoc(t_cmd *cmd, t_token *token)
{
	t_herdoc	*red;
	t_herdoc	*help;

	if (!cmd || !token)
		return (NULL);
	red = cmd->herdoc;
	while (token)
	{
		if (token->typ_e == PIPE)
			break ;
		if (token->typ_e == HERDOC)
		{
			if (!red)
			{
				red = create_herdoc_node(token->next);
				help = red;
			}
			else
			{
				help->next = create_herdoc_node(token->next);
				help = help->next;
			}
		}
		token = token->next;
	}
	return (red);
}

t_cmd	*ft_handle_herdoc(t_cmd *cmd, t_token *token)
{
	t_cmd *sat;
	t_token *yes;

	if (!cmd || !token)
		return (NULL);
	sat = NULL;
	yes = NULL;
	yes = token;
	sat = cmd;
	while (yes && sat)
	{
		sat->herdoc = ft_check_herdoc(sat, yes);
		sat = sat->next;
		yes = find_pipe(yes);
		if (yes && yes->next)
			yes = yes->next;
	}
	return (cmd);
}