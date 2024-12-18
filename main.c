/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:49:18 by sahamzao          #+#    #+#             */
/*   Updated: 2024/12/18 18:55:29 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

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
		cmd = ft_handle_p_h_a_re(cmd,tmp);
		// cmd = ft_handle_herdoc(cmd,tmp);
		// execve(cmd->path, cmd->args, NULL);
		while (cmd)
		{
			while (cmd->redirection)
			{
				printf("%s\n", cmd->redirection->red_append);
				cmd->redirection = cmd->redirection->next;
			}
   			cmd = cmd->next;
		}
	}
}
