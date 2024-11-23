/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:49:18 by sahamzao          #+#    #+#             */
/*   Updated: 2024/11/23 11:29:21 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_token	*ft_init_token_node(char **token)
{
	if(!token)
		return NULL;
	t_token	*linked;
	t_token	*first;
	int		i;

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
	return (linked);
}

void	ft_geave_type(t_token *type, char **env)
{
	if(type->string == NULL)
		return ;
	t_token	*tmp;

	tmp = type;
	while (tmp)
	{
		tmp->typ_e = ft_type(tmp, env);
		tmp = tmp->next;
	}
}
void	ll(void)
{
	system("leaks minishell");
}
int	main(int ac, char **av, char **env)
{
	char *line;
	char **token;
	t_token *sir;
	t_env *evv;

	evv = ft_initial_env(evv, env);
	// atexit(ll);
	while (1)
	{
		line = readline("minishell % >>>>>    ");
		if (ft_qt(line) == 0)
			printf("syntax error\n");
		token = ft_splitix(line);
		sir = ft_init_token_node(token);
		ft_geave_type(sir, env);
		ft_syntax(sir);
		ft_lstclear(&sir, &del);
		ft_lst_clr(&evv);
		free(token);
		// exit(0);
	}
}