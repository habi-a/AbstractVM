#include <instruction.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void    my_push(t_ast_node *ast_node, t_ast_node *ast_node1)
{
    if (ast_node1->node_type == AST_NULL)
    {
        fprintf(stderr, "push: too few arguments\n");
        exit(0);
    }
    else if (ast_node1->var_type != T_INT)
    {
        fprintf(stderr, "push: argument of type T_INT expected\n");
        exit(0);
    }
    ast_node->var_type = ast_node1->var_type;
    ast_node->value_int = ast_node1->value_int;
    ast_node->value_float = ast_node->value_int;
    printf("%d\n", ast_node1->value_int);
}
