/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:49:18 by sahamzao          #+#    #+#             */
/*   Updated: 2024/12/26 18:40:30 by sahamzao         ###   ########.fr       */
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

void	ft_cmd(t_env	*env, t_token *sir)
{
	t_cmd	*cmd;
	
	if (!sir)
		return ;
	cmd = ft_build_nodes(sir);
	cmd = check(cmd);
	cmd = ft_handle_p_h_a_re(cmd, sir);
	cmd = ft_handle_herdoc(cmd, sir);
	t_cmd	*tmp = cmd;
	ft_go_execute(tmp);
	ft_freeing_cmd_node(&cmd);
}

t_token	*ft_main(t_env	*env)
{
	t_token	*sir;
	char	*line;
	
	line = readline("minishell % >>>>>    ");
	sir = ft_token_init(line);
	if(!sir)
		return NULL;
	return	sir;
}

int	main(int ac, char **av, char **env)
{
	t_token	*sir;
	t_env	*evv;
	int		c;

	evv = ft_initial_env(evv, env);
	while (1)
	{
		sir = ft_main(evv);
		ft_geave_type(sir, env);
		sir = ft_expand_dollar(sir,evv);
		c = ft_syntax(sir);
		if (c == 1)
			ft_cmd(evv,sir);
		ft_lstclear(&sir);
	}
	ft_lst_clr(&evv);
}
