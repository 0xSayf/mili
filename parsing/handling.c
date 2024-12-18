/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:55:51 by sahamzao          #+#    #+#             */
/*   Updated: 2024/12/18 12:59:27 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void    *ft_handle_p_h_a_re(t_cmd *cmd,t_token *tmp)
{
    t_cmd   *sat;

    if(!cmd || !tmp)
        return NULL;
    sat = NULL;
    sat = cmd;
}
