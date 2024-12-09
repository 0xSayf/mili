/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:49:18 by sahamzao          #+#    #+#             */
/*   Updated: 2024/12/03 18:38:55 by sahamzao         ###   ########.fr       */
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

int	ft_geave_type(t_token *type, char **env)
{
	t_token	*tmp;

	if(!type || !type->string)
		return 0;
	tmp = type;
	while (tmp)
	{
		tmp->typ_e = ft_type(tmp, env);
		tmp = tmp->next;
	}
	return 1;
}
void	ll(void)
{
	system("leaks minishell");
}
int	main(int ac, char **av, char **env)
{
	char *line;
	char **token;
	t_var	var;
	t_token *sir;
	t_env *evv;
	evv = ft_initial_env(evv, env);
	while (1)
	{
		atexit(ll);
		line = readline("minishell % >>>>>    ");
		if (ft_qt(line) == 0)
			printf("syntax error\n");
		token = ft_splitix(line);
		int i = 0 ;
		while (token[i])
		{
			printf("%s\n", token[i]);
			i++;
		}
		// sir = ft_init_token_node(token);
		// var.a = ft_geave_type(sir, env);
		// var.i = ft_syntax(sir);
		// ft_expand(token,evv);
		// // if(var.a && var.i)
		// // {
		// // 	ft_build_tree(sir);
			
		// // }
		// ft_lstclear(&sir, &del);
		// free(token);
	}
	// ft_lst_clr(&evv);
	exit(0);
}