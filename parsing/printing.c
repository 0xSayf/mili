#include "../includes/minishell.h"
void traverse_tree(t_tree *node, int depth) {
    if (!node)
        return;

    for (int i = 0; i < depth; i++)
        printf("  "); // Indentation for visualizing depth

    if (node->type == CMD)
        printf("CMD: %s\n", node->args[0]);
    else if (node->type == PIPE)
        printf("PIPE\n");
    else if (node->type == REDERECTION_OUTPUT)
        printf("REDIR OUT\n");
    else if (node->type == APPEND_REDIRECT)
        printf("APPEND REDIR\n");
    else if (node->type == REDERECTION_INPUT)
        printf("REDIR IN\n");
    else if (node->type == HERDOC)
        printf("HEREDOC\n");
    else if (node->type == FILESS)
        printf("FILE: %s\n", node->args[0]);

    traverse_tree(node->left, depth + 1);
    traverse_tree(node->right, depth + 1);
}