#include "../includes/minishell.h"
#include <stdio.h>

void print_escaped(FILE *stream, const char *str)
{

    if (!str) return;

    while (*str)

	{

        switch (*str)

		{

            case '\n': fprintf(stream, "\\n"); break;

            case '\"': fprintf(stream, "\\\""); break;

            case '\\': fprintf(stream, "\\\\"); break;

            default: fputc(*str, stream);

        }

        str++;

    }
}

void print_ast_dot(t_tree *node, FILE *stream)
{
    if (node == NULL) return;

    // Print the current node with its type and arguments
    fprintf(stream, "\"%p\" [label=\"", (void*)node);
    switch (node->type)
    {
        case CMD: fprintf(stream, "CMD: "); break;
        case PIPE: fprintf(stream, "|"); break;
        case REDERECTION_INPUT: fprintf(stream, "<"); break;
        case REDERECTION_OUTPUT: fprintf(stream, ">"); break;
        case HERDOC: fprintf(stream, "<<"); break;
        case APPEND_REDIRECT: fprintf(stream, ">>"); break;
        default: fprintf(stream, "UNKNOWN"); break;
    }
    if (node->args)
    {
        for (int i = 0; node->args[i] != NULL; i++)
        {
            if (i > 0) fprintf(stream, " "); // Add space between arguments
            print_escaped(stream, node->args[i]);
        }
    }
    fprintf(stream, "\"];\n");

    // Recursively print left and right children
    if (node->left != NULL)
    {
        fprintf(stream, "\"%p\" -> \"%p\" [label=\"L\"];\n", (void*)node, (void*)node->left);
        print_ast_dot(node->left, stream);
    }
    if (node->right != NULL)
    {
        fprintf(stream, "\"%p\" -> \"%p\" [label=\"R\"];\n", (void*)node, (void*)node->right);
        print_ast_dot(node->right, stream);
    }
}
void generate_ast_diagram(t_tree *root)

{

    FILE *stream = fopen("ast.dot", "w");

    if (stream == NULL)

	{

        perror("fopen");

        return;

    }



    fprintf(stream, "digraph AST {\n");

    print_ast_dot(root, stream);

    fprintf(stream, "}\n");

	fclose(stream);

}