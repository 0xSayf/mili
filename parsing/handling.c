/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:55:51 by sahamzao          #+#    #+#             */
/*   Updated: 2024/12/18 17:08:27 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_red    *ft_check_redirection(t_cmd  *cmd, t_token *token)
{
    t_red   *red;
    t_red   *help;
    
    if(!cmd || !token)
        return NULL;
    red = cmd->redirection;
    while(token)
    {
        if(token->typ_e == REDERECTION_OUTPUT || token->typ_e == APPEND_REDIRECT)
        {
            if(!red)
            {
                red = ft_creat_redirection_node(token->next,token->typ_e);
                help = red;
            }
            else
            {
            help->next = ft_creat_redirection_node(token->next,token->typ_e);
            help = help->next;
            // printf("%s\n", help->red_append);
            }
        }
        token = token->next;
    }
    return red;
}

void    *ft_handle_p_h_a_re(t_cmd *cmd,t_token *tmp)
{
    t_cmd   *sat;
    t_token *yes;
    
    if(!cmd || !tmp)
        return NULL;
    sat = NULL;
    yes = NULL;
    yes = tmp;
    sat = cmd;
    while (yes && sat)
    {
        sat->redirection = ft_check_redirection(sat,yes);
        sat = sat->next;
        yes = find_pipe(yes);
        if(yes && yes->next)
            yes = yes->next;
    }
    return cmd;
}
