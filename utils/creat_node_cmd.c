/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_node_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 20:57:46 by sahamzao          #+#    #+#             */
/*   Updated: 2024/12/21 12:45:35 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_token	*find_pipe(t_token *find)
{
	t_token	*tmp;

	if (!tmp)
		return (NULL);
	tmp = find;
	while (tmp)
	{
		if (tmp->typ_e == PIPE)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

char	**ft_the_args(char **ret, t_token *start, int arg)
{
	t_token	*s;
	size_t	i;

	if (!ret || !start || !arg)
		return (NULL);
	s = start;
	i = 0;
	while (s && (i < arg) && (s->typ_e != PIPE))
	{
		ret[i] = malloc(ft_strlen(s->string) + 1);
		ret[i][ft_strlen(s->string)] = '\0';
		if (s->typ_e == CMD || s->typ_e == STRING || s->typ_e == FILESS)
		{
			ft_memcpy(ret[i], s->string, ft_strlen(s->string) + 1);
			i++;
		}
		s = s->next;
	}
	ret[i] = NULL;
	return (ret);
}

t_cmd	*creat_cmd_node(t_token *start, t_token *end, int k)
{
	t_cmd	*new;

	if (!start)
		return (NULL);
	new = malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	if (!k)
		new->pipe = false;
	else
		new->pipe = true;
	new->cmd = ft_strdup(start->string);
	new->num_args = ft_count_args(start, end);
	new->args = malloc(sizeof(char *) * (new->num_args + 1));
	new->args = ft_the_args(new->args, start, new->num_args);
	new->path = ft_strdup(start->path);
	new->herdoc = NULL;
	new->redirection = NULL;
	new->next = NULL;
	return (new);
}

t_red	*ft_creat_redirection_node(t_token *token, enum data_type typ_e)
{
	t_red *red;

	red = malloc(sizeof(t_red));
	if (!red)
		return (NULL);
	red->typix = typ_e;
	if (typ_e == REDERECTION_OUTPUT)
	{
		red->red_out = ft_strdup(token->string);
		red->red_append = NULL;
		red->red_input = NULL;
	}
	else if (typ_e == APPEND_REDIRECT)
	{
		red->red_append = ft_strdup(token->string);
		red->red_out = NULL;
		red->red_input = NULL;
	}
	else if (typ_e == REDERECTION_INPUT)
	{
		red->red_append = NULL;
		red->red_out = NULL;
		red->red_input = ft_strdup(token->string);
	}
	red->next = NULL;
	return (red);
}