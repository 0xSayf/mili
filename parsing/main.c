/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:49:18 by sahamzao          #+#    #+#             */
/*   Updated: 2024/11/17 13:01:17 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int go_check_before(char *line)
{
    int i;

    if(line[0] == '|')
        return 0;
    i = 0;
    while (line[i])
    {
        if(line[i] == 39 || line[i] == 34)
        {
            i = ft_syntax(&line[i]);
            if(i == -1)
                return 0;                
        }
        i++;
    }
    return 1;
}

int ft_syntax(char *line)
{
    int i;
    char c;

    if(line[0] == 39)
        c = 39;
    else if(line[0] == 34)
        c = 34;
    i = 1;
    while (line[i])
    {
        if(line[i] == c)
            return i;
        i++;
    }    
    return -1;
}

int main (int ac , char **av, char **env)
{
    char *line;
    char **token;
    
    while (1)
    {
        line = readline("minishell % >>>>>    ");
        // if(go_check_before(line) == 0)
        //     printf("syntax error\n");
        token = ft_splitix(line);
        if(token == NULL)
            printf(">>>>>>>>>>>>ra9\n");
    }
}