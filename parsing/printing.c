#include "../includes/minishell.h"
#include <stdio.h>

// Helper function to print the data_type as a string
void	print_tree(t_tree *node, int depth)
{
	if (!node)
		return ;

	// Indentation for readability
	for (int i = 0; i < depth; i++)
	{
		printf("  ");
	}

	// Print the type directly using a switch statement
	printf("Node Type: ");
	switch (node->type)
	{
	case STRING:
		printf("STRING");
		break ;
	case CMD:
		printf("CMD");
		break ;
	case PIPE:
		printf("PIPE");
		break ;
	case FILESS:
		printf("FILESS");
		break ;
	case REDERECTION_INPUT:
		printf("REDIRECTION_INPUT (<)");
		break ;
	case REDERECTION_OUTPUT:
		printf("REDIRECTION_OUTPUT (>)");
		break ;
	case HERDOC:
		printf("HERDOC (<<)");
		break ;
	case APPEND_REDIRECT:
		printf("APPEND_REDIRECT (>>)");
		break ;
	default:
		printf("UNKNOWN");
	}
	printf("\n");

	// Print arguments if present
	if (node->args)
	{
		for (int i = 0; node->args[i]; i++)
		{
			for (int j = 0; j < depth + 1; j++)
			{
				printf("  ");
			}
			printf("Arg[%d]: %s\n", i, node->args[i]);
		}
	}

	// Recursively print the left and right children
	print_tree(node->left, depth + 1);
	print_tree(node->right, depth + 1);
}