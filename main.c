/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:49:18 by sahamzao          #+#    #+#             */
/*   Updated: 2024/12/14 16:51:30 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

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
	return (linked);
}

int	ft_geave_type(t_token *type, char **env)
{
	t_token	*tmp;

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

int	main(int ac, char **av, char **env)
{
	t_token *sir;
	t_env *evv;
	t_token *tmp;
	char *line;
	char **tok;

	evv = NULL;
	evv = ft_initial_env(evv, env);
	while (1)
	{
		line = readline("minishell % >>>>>    ");
		if (ft_qt(line) == 0)
			printf("syntax error\n");
		tok = ft_splitix(line);
		sir = ft_init_token_node(tok);
		tmp = sir;
		ft_geave_type(sir, env);
		ft_syntax(sir);
		t_cmd *cmd = ft_build_nodes(sir);
		// int i = 0 ;
		// while (cmd)
		// {
		// 	while (cmd->args[i])
		// 	{
		// 		printf("%s\n", cmd->args[i]);
		// 		i++;
		// 	}
   		// 	 cmd = cmd->next;
		// }
	}
}
