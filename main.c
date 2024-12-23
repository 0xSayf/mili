/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:49:18 by sahamzao          #+#    #+#             */
/*   Updated: 2024/12/24 20:49:39 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

t_cmd	*check(t_cmd	*cmd)
{
	char	*str;
	
	if(!cmd)
		return NULL;
	if(cmd->pipe == false)
	{
		str = cmd->cmd;
		if(ft_strncmp(str, "$",1) == 0)
		{
			if(str[1])
			{
				ft_freeing_cmd_node(&cmd);
				return NULL;
			}	
		}
	}
	return cmd;
}

t_token	*ft_main(t_env	*env)
{
	char 	**tok;
	t_token	*sir;
	
	tok = ft_splitix(readline("minishell % >>>>>    "));
	if(!tok)
		return NULL;
	sir = ft_init_token_node(tok);
	sir = ft_expand_dollar(sir,env);
	if(!sir)
		return NULL;
	return	sir;
}

int	main(int ac, char **av, char **env)
{
	t_token	*sir;
	t_env	*evv;
	t_cmd	*cmd;
	int		c;

	evv = ft_initial_env(evv, env);
	while (1)
	{
		sir = ft_main(evv);
		ft_geave_type(sir, env);
		c = ft_syntax(sir);
		if (c == 1)
		{
			cmd = ft_build_nodes(sir);
			cmd = check(cmd);
			cmd = ft_handle_p_h_a_re(cmd, sir);
			cmd = ft_handle_herdoc(cmd, sir);
			ft_go_execute(cmd);
			ft_freeing_cmd_node(&cmd);
		}
		ft_lstclear(&sir);
	}
	ft_lst_clr(&evv);
}
