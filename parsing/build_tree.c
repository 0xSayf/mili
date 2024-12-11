/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 20:28:23 by sahamzao          #+#    #+#             */
/*   Updated: 2024/11/24 20:52:25 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

const char* node_type_to_string(enum data_type type) {
    switch (type) {
        case CMD: return "CMD";
        case PIPE: return "PIPE";
        case FILESS: return "FILESS";
        case REDERECTION_INPUT: return "REDIRECTION INPUT";
        case REDERECTION_OUTPUT: return "REDIRECTION OUTPUT";
        case HERDOC: return "HERDOC";
        case APPEND_REDIRECT: return "APPEND REDIRECT";
        default: return "STRING";
    }
}

t_tree *create_tree_node(enum data_type type, char **args, int file) {
    t_tree *new_node = (t_tree *)malloc(sizeof(t_tree));
    new_node->type = type;
    new_node->args = args;
    new_node->file = file;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Function to build the tree from the tokenized linked list
t_tree *build_tree(t_token **tokens) {
    t_tree *root = NULL;
    t_tree *current_node = NULL;
    t_tree *last_operator = NULL;
    char **args = NULL;
    int file = -1;  // To be used for redirection

    while (*tokens) {
        t_token *current_token = *tokens;

        // Handle commands (CMD) and arguments (STRING)
        if (current_token->typ_e == CMD || current_token->typ_e == STRING) {
            // Collect arguments for the command
            args = (char **)malloc(2 * sizeof(char *));
            args[0] = current_token->string;
            args[1] = NULL;

            t_tree *new_node = create_tree_node(CMD, args, -1);
            if (!root) {
                root = new_node;  // First command becomes the root
            } else {
                if (last_operator) {
                    // Attach to the last operator's right child
                    last_operator->right = new_node;
                }
            }
        }
        // Handle pipes
        else if (current_token->typ_e == PIPE) {
            t_tree *new_node = create_tree_node(PIPE, NULL, -1);
            if (current_node) {
                current_node->right = new_node;
            }
            last_operator = new_node;
        }
        // Handle redirection (input or output)
        else if (current_token->typ_e == REDERECTION_INPUT || current_token->typ_e == REDERECTION_OUTPUT ||
                 current_token->typ_e == APPEND_REDIRECT || current_token->typ_e == HERDOC) {
            t_tree *new_node = create_tree_node(current_token->typ_e, NULL, -1);
            if (current_token->typ_e == REDERECTION_INPUT || current_token->typ_e == REDERECTION_OUTPUT ||
                current_token->typ_e == APPEND_REDIRECT) {
                file = open(current_token->string, O_RDWR | O_CREAT | O_TRUNC, 0644);  // Example file opening
                new_node->file = file;
            }

            if (last_operator) {
                last_operator->right = new_node;
            }
            last_operator = new_node;
        }

        // Move to the next token
        *tokens = current_token->next;
    }

    return root;
}

void print_tree(t_tree *root, int depth) {
    if (root == NULL) return;

    // Print spaces for indentation based on depth
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }

    // Print the node type and the arguments (for CMD nodes)
    printf("[%s]", node_type_to_string(root->type));

    if (root->type == CMD && root->args != NULL) {
        printf(" %s", root->args[0]); // Print the command
    } else if (root->type == REDERECTION_INPUT || root->type == REDERECTION_OUTPUT) {
        printf(" -> %d", root->file); // Print the file descriptor for redirections
    }

    printf("\n");

    // Recursively print the left and right children
    if (root->left) {
        print_tree(root->left, depth + 1);
    }
    if (root->right) {
        print_tree(root->right, depth + 1);
    }
}