/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:49:18 by sahamzao          #+#    #+#             */
/*   Updated: 2024/12/18 13:32:43 by sahamzao         ###   ########.fr       */
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
		// ft_handle_p_h_a_re(cmd,tmp);
		execve(cmd->path, cmd->args, NULL);
		// while (cmd)
		// {
		// // int i = 0 ;
		// 	// while (cmd->args)
		// 	// {
		// 		printf("%s\n", cmd->cmd);
		// 		// i++;
		// 	// }
   		// 	 cmd = cmd->next;
		// }
	}
}
