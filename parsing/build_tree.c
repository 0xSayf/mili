/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 20:28:23 by sahamzao          #+#    #+#             */
/*   Updated: 2024/12/14 18:07:35 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_tree	*parse_command(t_token **tokens)
{
	t_tree	*command_node;
	int		arg_count;

	command_node = new_tree_node(CMD);
	arg_count = count_command_arguments(*tokens);
	command_node->args = malloc(sizeof(char *) * (arg_count + 1));
	if (!command_node->args)
		return (NULL);
	fill_command_arguments(command_node, tokens, arg_count);
	return (command_node);
}

t_tree	*create_file_node(t_token *token)
{
	t_tree	*node;

	node = malloc(sizeof(t_tree));
	if (!node)
		return (NULL);
	node->type = token->typ_e;
	node->args = malloc(sizeof(char *) * 2);
	if (!node->args)
	{
		free(node);
		return (NULL);
	}
	node->args[0] = token->string;
	node->args[1] = NULL;
	node->left = NULL;
	node->right = NULL;
	free(token);
	return (node);
}

t_tree	*parse_redirection(t_token **tokens)
{
	t_token	*tmp;
	t_tree	*redirect_node;
	t_token	*next_token;

	if (!*tokens)
		return (NULL);
	tmp = *tokens;
	if ((*tokens)->typ_e >= REDERECTION_INPUT && (*tokens)->typ_e <= HERDOC)
		return (create_and_link_redirection(tokens, tmp));
	while (*tokens && (*tokens)->next)
	{
		next_token = (*tokens)->next;
		if ((*tokens)->next->typ_e >= REDERECTION_INPUT
			&& (*tokens)->next->typ_e <= HERDOC)
		{
			redirect_node = new_tree_node((*tokens)->next->typ_e);
			(*tokens)->next = next_token->next->next;
			redirect_node->left = parse_redirection(&tmp);
			redirect_node->right = create_file_node((next_token->next));
			return (free(next_token->string), free(next_token), redirect_node);
		}
		*tokens = next_token;
	}
	return (parse_command(&tmp));
}

t_tree	*parse_pipeline(t_token **token)
{
	t_token	*tmp;
	t_token	*next_token;
	t_tree	*pipe_node;

	tmp = *token;
	while (*token && (*token)->next)
	{
		next_token = (*token)->next;
		if ((*token)->next->typ_e == PIPE)
		{
			pipe_node = new_tree_node((*token)->next->typ_e);
			(*token)->next = NULL;
			pipe_node->left = parse_redirection(&tmp);
			pipe_node->right = parse_pipeline(&(next_token->next));
			// free(next_token->string);
			free(next_token);
			return (pipe_node);
		}
		*token = next_token;
	}
	return (parse_redirection(&tmp));
}

t_tree	*parse_tokens(t_token **tokens)
{
	if (!tokens || !*tokens)
		return (NULL);
	return (parse_pipeline(tokens));
}
