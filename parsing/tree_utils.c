#include "../includes/minishell.h"

t_tree	*new_tree_node(enum data_type type)
{
	t_tree		*node;

	node = malloc(sizeof(t_tree));
	if (!node)
		return (NULL);
	node->type = type;
	node->args = NULL;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

void	free_tree(t_tree *node)
{
	int			i;

	i = 0;
	if (!node)
		return ;
	if (node->type == STRING && node->args)
	{
		while (node->args && node->args[i])
		{
			// free(node->args[i]);
			i++;
		}
		// free(node->args);
	}
	// free_tree(node->left);
	// free_tree(node->right);
	free(node);
}

t_tree	*create_and_link_redirection(t_token **tokens, t_token *tmp)
{
	t_tree		*redirect_node;

	redirect_node = new_tree_node((*tokens)->typ_e);
	*tokens = (*tokens)->next->next;
	redirect_node->left = parse_redirection(tokens);
	redirect_node->right = create_file_node(tmp->next);
	// free(tmp->string);
	// free(tmp);
	return (redirect_node);
}

int	count_command_arguments(t_token *current)
{
	int		arg_count;

	arg_count = 0;
	while (current && current->typ_e == STRING)
	{
		arg_count++;
		current = current->next;
	}
	return (arg_count);
}

void	fill_command_arguments(t_tree *command_node, t_token **tokens, int arg_count)
{
	int		i;
	t_token	*tmp;

	i = 0;
	while (i < arg_count)
	{
		command_node->args[i] = ft_strdup((*tokens)->string);
		tmp = *tokens;
		*tokens = (*tokens)->next;
		// free(tmp->string);
		// free(tmp);
		i++;
	}
	command_node->args[arg_count] = NULL;
}