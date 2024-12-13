/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_node_tree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 20:57:46 by sahamzao          #+#    #+#             */
/*   Updated: 2024/11/24 21:30:23 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// t_tree *ft_creat_tree(t_token *token)
// {
//     t_tree *new;

//     new = malloc(sizeof(t_tree));
//     if (!new)
//         return (NULL);
//     new->args = malloc(sizeof(char *) * 2);
//     new->args[0] = token->string;
//     new->args[1] = NULL;
//     new->type = token->typ_e;
//     new->right = NULL;
//     new->left = NULL;
// }