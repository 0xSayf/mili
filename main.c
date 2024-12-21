/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:49:18 by sahamzao          #+#    #+#             */
/*   Updated: 2024/12/21 11:06:50 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
void	ll()
{
	system("leaks -q minishell");
}

int	main(int ac, char **av, char **env)
{
	t_token	*sir;
	t_env	*evv;
	t_cmd	*cmd;
	char	**tok;
	int	c;
	
	evv = ft_initial_env(evv, env);
	int i = 0;
	atexit(ll);
	while (i < 5)
	{
		tok = ft_splitix(readline("minishell % >>>>>    "));
		sir = ft_init_token_node(tok);
		ft_geave_type(sir, env);
		c = ft_syntax(sir);
		if(c == 1)
		{
			cmd = ft_build_nodes(sir);
			cmd = ft_handle_p_h_a_re(cmd,sir);
			cmd = ft_handle_herdoc(cmd,sir);
			ft_go_execute(cmd);
			ft_freeing_cmd_node(cmd);
		}
		ft_lstclear(&sir);
		i++;
	}
	ft_lst_clr(&evv);
}
