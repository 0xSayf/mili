/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_and_rem_node.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:38:37 by sahamzao          #+#    #+#             */
/*   Updated: 2024/12/12 20:21:31 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_token	*ft_creat_node(char *content)
{
	t_token	*new;

	new = (t_token *)malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->string = content;
	new->next = NULL;
	return (new);
}

t_env	*ft_creat_env(char *content)
{
	t_env	*new;

	new = (t_env *)malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	new->var = ft_strdup(content);
	new->to_print = NULL;
	new->next = NULL;
	return (new);
}

void	del(char *string)
{
	free(string);
}

void	ft_lstclear(t_token **lst)
{
	t_token	*curr;
	t_token	*ne;

	if (!lst)
		return ;
	curr = *lst;
	while (curr)
	{
		ne = curr->next;
		// (*del)(curr->string);
		free(curr);
		curr = ne;
	}
	*lst = NULL;
}


void	ft_lst_clr(t_env **env)
{
	t_env *curr;
	t_env *ne;

	if (!env)
		return ;
	curr = *env;
	while (curr)
	{
		ne = curr->next;
		free(curr);
		curr = ne;
	}
	*env = NULL;
}