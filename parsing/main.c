/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:49:18 by sahamzao          #+#    #+#             */
/*   Updated: 2024/11/19 13:08:42 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main (int ac , char **av, char **env)
{
    char *line;
    char **token;
    
    while (1)
    {
        line = readline("minishell % >>>>>    ");
        token = ft_splitix(line);
        if(token == NULL)
            printf(">>>>>>>>>>>>ra9\n");
        int i = 0;
        // while (token[i])
        // {
            printf("%s\n", token[i]);
        //     i++;
        // }
    }
}