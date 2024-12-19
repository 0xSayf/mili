/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:49:18 by sahamzao          #+#    #+#             */
/*   Updated: 2024/12/19 17:16:17 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	main(int ac, char **av, char **env)
{
	t_token	*sir;
	t_env	*evv;
	t_cmd	*cmd;
	char	**tok;
	int	c;

	evv = ft_initial_env(evv, env);
	while (1)
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
			execve(cmd->path,cmd->args, NULL);
		}
	}
}
