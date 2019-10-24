#include <types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void    my_int8(t_ast_node *ast_node, t_ast_node *ast_node1)
{
    if (ast_node1->node_type == AST_NULL)
    {
        fprintf(stderr, "int8(): too few arguments\n");
        exit(0);
    }
    else if (ast_node1->var_type != ast_node->var_type)
    {
        fprintf(stderr, "int8(): argument of type T_INT expected\n");
        exit(0);
    }
    ast_node->value_int = ast_node1->value_int;
    ast_node->value_float = ast_node->value_int;
}

void    my_int16(t_ast_node *ast_node, t_ast_node *ast_node1)
{
    if (ast_node1->node_type == AST_NULL)
    {
        fprintf(stderr, "int16(): too few arguments\n");
        exit(0);
    }
    else if (ast_node1->var_type != ast_node->var_type)
    {
        fprintf(stderr, "int16(): argument of type T_INT expected\n");
        exit(0);
    }
    ast_node->value_int = ast_node1->value_int;
    ast_node->value_float = ast_node->value_int;
}

void    my_int32(t_ast_node *ast_node, t_ast_node *ast_node1)
{
    if (ast_node1->node_type == AST_NULL)
    {
        fprintf(stderr, "int32(): too few arguments\n");
        exit(0);
    }
    else if (ast_node1->var_type != ast_node->var_type)
    {
        fprintf(stderr, "int32(): argument of type T_INT expected\n");
        exit(0);
    }
    ast_node->value_int = ast_node1->value_int;
    ast_node->value_float = ast_node->value_int;
}

void    my_float(t_ast_node *ast_node, t_ast_node *ast_node1)
{
    if (ast_node1->node_type == AST_NULL)
    {
        fprintf(stderr, "float(): too few arguments\n");
        exit(0);
    }
    else if (ast_node1->var_type != ast_node->var_type)
    {
        fprintf(stderr, "float(): argument of type T_FLOAT expected\n");
        exit(0);
    }
    ast_node->value_int = ast_node1->value_int;
    ast_node->value_float = ast_node->value_int;
}

void    my_double(t_ast_node *ast_node, t_ast_node *ast_node1)
{
    if (ast_node1->node_type == AST_NULL)
    {
        fprintf(stderr, "double(): too few arguments\n");
        exit(0);
    }
    else if (ast_node1->var_type != ast_node->var_type)
    {
        fprintf(stderr, "double(): argument of type T_DOUBLE expected\n");
        exit(0);
    }
    ast_node->value_int = ast_node1->value_int;
    ast_node->value_float = ast_node->value_int;
}
