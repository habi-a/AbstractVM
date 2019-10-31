/*
** ETNA PROJECT, 31/10/2019 by courta_f & habi_a
** c:\Users\Fr4nck\Desktop\group-716039
** File description:
**      Définition des différents types
*/

#include <types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void    my_int8(ast_node_t *ast_node, ast_node_t *ast_node1)
{
    if (ast_node1->node_type == AST_NULL) {
        fprintf(stderr, "int8(): too few arguments\n");
        exit(0);
    }
    else if (ast_node1->var_type != ast_node->var_type) {
        fprintf(stderr, "int8(): argument of type T_INT8 expected\n");
        exit(0);
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
        fprintf(stderr, "int16(): too few arguments\n");
        exit(0);
    } else if (ast_node1->var_type < T_INT8 || ast_node1->var_type > ast_node->var_type) {
        fprintf(stderr, "int16(): argument of type T_INT16 expected\n");
        exit(0);
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
        fprintf(stderr, "int32(): too few arguments\n");
        exit(0);
    } else if (ast_node1->var_type < T_INT8 || ast_node1->var_type > ast_node->var_type) {
        fprintf(stderr, "int32(): argument of type T_INT32 expected\n");
        exit(0);
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
        fprintf(stderr, "float(): too few arguments\n");
        exit(0);
    } else if (ast_node1->var_type < T_INT8 || ast_node1->var_type > ast_node->var_type) {
        fprintf(stderr, "float(): argument of type T_FLOAT expected\n");
        exit(0);
    }
    ast_node->value_int8 = ast_node1->value_int8;
    ast_node->value_int16 = ast_node1->value_int16;
    ast_node->value_int32 = ast_node1->value_int32;
    ast_node->value_float = ast_node1->value_float;
    ast_node->value_double = ast_node1->value_double;
    printf("float(): %f\n", ast_node->value_float);
}

void    my_double(ast_node_t *ast_node, ast_node_t *ast_node1)
{
    if (ast_node1->node_type == AST_NULL) {
        fprintf(stderr, "double(): too few arguments\n");
        exit(0);
    } else if (ast_node1->var_type < T_INT8 || ast_node1->var_type > ast_node->var_type) {
        fprintf(stderr, "double(): argument of type T_DOUBLE expected\n");
        exit(0);
    }
    ast_node->value_int8 = ast_node1->value_int8;
    ast_node->value_int16 = ast_node1->value_int16;
    ast_node->value_int32 = ast_node1->value_int32;
    ast_node->value_float = ast_node1->value_float;
    ast_node->value_double = ast_node1->value_double;
}
