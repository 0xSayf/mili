/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:49:18 by sahamzao          #+#    #+#             */
/*   Updated: 2024/12/13 20:32:09 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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
void	ll(void)
{
	system("leaks -q minishell");
}

int	main(int ac, char **av, char **env)
{
	t_tree *tree;
	t_token *sir;
	t_env *evv;
	t_token *tmp;
	char *line;
	char **tok;

	evv = NULL;
	evv = ft_initial_env(evv, env);
	int i = 0;
	while (i < 1)
	{
		line = readline("minishell % >>>>>    ");
		if (ft_qt(line) == 0)
			printf("syntax error\n");
		tok = ft_splitix(line);
		char **ptr = tok;
		sir = ft_init_token_node(tok);
		tmp = sir;
		ft_geave_type(sir, env);
		ft_syntax(sir);
		tree = parse_tokens(&tmp);
		print_tree(tree, 0);
		ft_lstclear(&sir);
		free_tree(tree);
		i++;
	}
	atexit(ll);
	exit(0);
}