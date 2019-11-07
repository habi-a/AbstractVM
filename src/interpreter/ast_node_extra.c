/*
** ETNA PROJECT, 31/10/2019 by courta_f
** c:\Users\Fr4nck\Desktop\group-716039
** File description:
**
*/

#include <ast.h>
#include <my.h>
#include <stdlib.h>

ast_node_t      *create_node_null(void)
{
    ast_node_t  *ast_node;

    ast_node = malloc(sizeof(ast_node_t));
    if (ast_node == NULL)
        return (NULL);
    ast_node->node_type = AST_NULL;
    ast_node->var_name = NULL;
    ast_node->var_type = T_NULL;
    ast_node->value_int8 = 0;
    ast_node->value_int16 = 0;
    ast_node->value_int32 = 0;
    ast_node->value_float = 0;
    ast_node->value_double = 0;
    ast_node->ast_node_l = NULL;
    ast_node->ast_node_r = NULL;
    return (ast_node);
}

void            destruct_astnode(ast_node_t *ast_node)
{
    if (ast_node == NULL)
        return ;
    if (ast_node->var_name != NULL)
        free((char *)ast_node->var_name);
    if (ast_node->ast_node_l != NULL)
        destruct_astnode(ast_node->ast_node_l);
    if (ast_node->ast_node_r != NULL)
        destruct_astnode(ast_node->ast_node_r);
    free(ast_node);
}
