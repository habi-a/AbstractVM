/*
** ETNA PROJECT, 31/10/2019 by courta_f & habi_a
** c:\Users\Fr4nck\Desktop\group-716039
** File description:
**      
*/

#include <ast.h>
#include <my.h>
#include <stdlib.h>

ast_node_t*     create_node_binary(ast_nodetype_t type, ast_node_t *left, ast_node_t *right)
{
    ast_node_t* ast_node;

    ast_node = malloc(sizeof(ast_node_t));
    if (ast_node == NULL)
        return (NULL);
    ast_node->node_type = type;
    ast_node->var_name = NULL;
    ast_node->var_type = T_UNDEFINED;
    ast_node->value_int8 = 0;
    ast_node->value_int16 = 0;
    ast_node->value_int32 = 0;
    ast_node->value_float = 0;
    ast_node->value_double = 0;
    ast_node->ast_node_l = left;
    ast_node->ast_node_r = right;
    return (ast_node);
}

ast_node_t*     create_node_unary(ast_node_t* left)
{
    ast_node_t* ast_node;

    ast_node = malloc(sizeof(ast_node_t));
    if (ast_node == NULL)
        return (NULL);
    ast_node->node_type = AST_UNARY_MIN;
    ast_node->var_name = NULL;
    ast_node->var_type = T_UNDEFINED;
    ast_node->value_int8 = 0;
    ast_node->value_int16 = 0;
    ast_node->value_int32 = 0;
    ast_node->value_float = 0;
    ast_node->value_double = 0;
    ast_node->ast_node_l = left;
    ast_node->ast_node_r = NULL;
    return (ast_node);
}

ast_node_t*     create_node_number(stack_data_t *tmp_stack_node)
{
    ast_node_t* ast_node;

    ast_node = malloc(sizeof(ast_node_t));
    if (ast_node == NULL)
        return (NULL);
    ast_node->node_type = AST_NUMBER;
    ast_node->var_name = NULL;
    ast_node->var_type = tmp_stack_node->var_type;
    ast_node->value_int8 = tmp_stack_node->value_int8;
    ast_node->value_int16 = tmp_stack_node->value_int16;
    ast_node->value_int32 = tmp_stack_node->value_int32;
    ast_node->value_float = tmp_stack_node->value_float;
    ast_node->value_double = tmp_stack_node->value_double;
    ast_node->ast_node_l = NULL;
    ast_node->ast_node_r = NULL;
    return (ast_node);
}

ast_node_t      *create_node_call_func(const char *var_name, ast_node_t *ast_node1)
{
    ast_node_t* ast_node;

    ast_node = malloc(sizeof(ast_node_t));
    if (ast_node == NULL)
        return (NULL);
    ast_node->node_type = AST_TYPE;
    ast_node->var_name = my_strdup(var_name);
    ast_node->var_type = T_VOID;
    ast_node->value_int8 = 0;
    ast_node->value_int16 = 0;
    ast_node->value_int32 = 0;
    ast_node->value_float = 0;
    ast_node->value_double = 0;
    ast_node->ast_node_l = ast_node1;
    ast_node->ast_node_r = NULL;
    return (ast_node);
}

ast_node_t      *create_node_instruction(const char *var_name, ast_node_t *ast_node1)
{
    ast_node_t* ast_node;

    ast_node = malloc(sizeof(ast_node_t));
    if (ast_node == NULL)
        return (NULL);
    ast_node->node_type = AST_INSTRUCTION;
    ast_node->var_name = my_strdup(var_name);
    ast_node->var_type = T_VOID;
    ast_node->value_int8 = 0;
    ast_node->value_int16 = 0;
    ast_node->value_int32 = 0;
    ast_node->value_float = 0;
    ast_node->value_double = 0;
    ast_node->ast_node_l = ast_node1;
    ast_node->ast_node_r = NULL;
    return (ast_node);
}

ast_node_t      *create_node_null()
{
    ast_node_t* ast_node;

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

void    destruct_astnode(ast_node_t *ast_node)
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
