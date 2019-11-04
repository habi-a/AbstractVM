/*
** ETNA PROJECT, 31/10/2019 by courta_f
** c:\Users\Fr4nck\Desktop\group-716039
** File description:
**      Définition des différents types
*/

#include <my.h>
#include <types.h>
#include <stdlib.h>

void    my_int8(ast_node_t *ast_node, ast_node_t *ast_node1)
{
    if (ast_node1->node_type == AST_NULL) {
        my_printf("int8(): too few arguments\n");
        return ;
    }
    else if (ast_node1->var_type != ast_node->var_type) {
        my_printf("int8(): argument of type T_INT8 expected\n");
        return ;
    }
    ast_node->value_int8 = ast_node1->value_int8;
    ast_node->value_int16 = ast_node1->value_int16;
    ast_node->value_int32 = ast_node1->value_int32;
    ast_node->value_float = ast_node1->value_float;
    ast_node->value_double = ast_node1->value_double;
}

void    my_int16(ast_node_t *ast_node, ast_node_t *ast_node1)
{
    if (ast_node1->node_type == AST_NULL) {
        my_printf("int16(): too few arguments\n");
        return ;
    } else if (ast_node1->var_type < T_INT8
                || ast_node1->var_type > ast_node->var_type) {
        my_printf("int16(): argument of type T_INT16 expected\n");
        return ;
    }
    ast_node->value_int8 = ast_node1->value_int8;
    ast_node->value_int16 = ast_node1->value_int16;
    ast_node->value_int32 = ast_node1->value_int32;
    ast_node->value_float = ast_node1->value_float;
    ast_node->value_double = ast_node1->value_double;
}

void    my_int32(ast_node_t *ast_node, ast_node_t *ast_node1)
{
    if (ast_node1->node_type == AST_NULL) {
        my_printf("int32(): too few arguments\n");
        return ;
    } else if (ast_node1->var_type < T_INT8
                || ast_node1->var_type > ast_node->var_type) {
        my_printf("int32(): argument of type T_INT32 expected\n");
        return ;
    }
    ast_node->value_int8 = ast_node1->value_int8;
    ast_node->value_int16 = ast_node1->value_int16;
    ast_node->value_int32 = ast_node1->value_int32;
    ast_node->value_float = ast_node1->value_float;
    ast_node->value_double = ast_node1->value_double;
}

void    my_float(ast_node_t *ast_node, ast_node_t *ast_node1)
{
    if (ast_node1->node_type == AST_NULL) {
        my_printf("float(): too few arguments\n");
        return ;
    } else if (ast_node1->var_type < T_INT8
                || ast_node1->var_type > ast_node->var_type) {
        my_printf("float(): argument of type T_FLOAT expected\n");
        return ;
    }
    ast_node->value_int8 = ast_node1->value_int8;
    ast_node->value_int16 = ast_node1->value_int16;
    ast_node->value_int32 = ast_node1->value_int32;
    ast_node->value_float = ast_node1->value_float;
    ast_node->value_double = ast_node1->value_double;
}

void    my_double(ast_node_t *ast_node, ast_node_t *ast_node1)
{
    if (ast_node1->node_type == AST_NULL) {
        my_printf("double(): too few arguments\n");
        return ;
    } else if (ast_node1->var_type < T_INT8
                || ast_node1->var_type > ast_node->var_type) {
        my_printf("double(): argument of type T_DOUBLE expected\n");
        return ;
    }
    ast_node->value_int8 = ast_node1->value_int8;
    ast_node->value_int16 = ast_node1->value_int16;
    ast_node->value_int32 = ast_node1->value_int32;
    ast_node->value_float = ast_node1->value_float;
    ast_node->value_double = ast_node1->value_double;
}
