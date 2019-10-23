#include <instructions.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void    instruct_push(t_ast_node *ast_node, t_ast_node *ast_node1)
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

void    instruct_pop(t_ast_node *ast_node, t_ast_node *ast_node1)
{
    if (ast_node1->node_type != AST_NULL)
    {
        fprintf(stderr, "pop: too many arguments\n");
        exit(0);
    }
    ast_node->var_type = T_VOID;
    ast_node->value_int = 0;
    ast_node->value_float = ast_node->value_int;
    printf("pop\n");
}

void    instruct_add(t_ast_node *ast_node, t_ast_node *ast_node1)
{
    if (ast_node1->node_type != AST_NULL)
    {
        fprintf(stderr, "add: too many arguments\n");
        exit(0);
    }
    ast_node->var_type = T_VOID;
    ast_node->value_int = 0;
    ast_node->value_float = ast_node->value_int;
    printf("add\n");
}

void    instruct_sub(t_ast_node *ast_node, t_ast_node *ast_node1)
{
    if (ast_node1->node_type != AST_NULL)
    {
        fprintf(stderr, "sub: too many arguments\n");
        exit(0);
    }
    ast_node->var_type = T_VOID;
    ast_node->value_int = 0;
    ast_node->value_float = ast_node->value_int;
    printf("sub\n");
}

void    instruct_mul(t_ast_node *ast_node, t_ast_node *ast_node1)
{
    if (ast_node1->node_type != AST_NULL)
    {
        fprintf(stderr, "mul: too many arguments\n");
        exit(0);
    }
    ast_node->var_type = T_VOID;
    ast_node->value_int = 0;
    ast_node->value_float = ast_node->value_int;
    printf("mul\n");
}

void    instruct_div(t_ast_node *ast_node, t_ast_node *ast_node1)
{
    if (ast_node1->node_type != AST_NULL)
    {
        fprintf(stderr, "div: too many arguments\n");
        exit(0);
    }
    ast_node->var_type = T_VOID;
    ast_node->value_int = 0;
    ast_node->value_float = ast_node->value_int;
    printf("div\n");
}

void    instruct_mod(t_ast_node *ast_node, t_ast_node *ast_node1)
{
    if (ast_node1->node_type != AST_NULL)
    {
        fprintf(stderr, "mod: too many arguments\n");
        exit(0);
    }
    ast_node->var_type = T_VOID;
    ast_node->value_int = 0;
    ast_node->value_float = ast_node->value_int;
    printf("mod\n");
}

void    instruct_assert(t_ast_node *ast_node, t_ast_node *ast_node1)
{
    if (ast_node1->node_type == AST_NULL)
    {
        fprintf(stderr, "assert: too few arguments\n");
        exit(0);
    }
    else if (ast_node1->var_type != T_INT)
    {
        fprintf(stderr, "assert: argument of type T_INT expected\n");
        exit(0);
    }
    ast_node->var_type = ast_node1->var_type;
    ast_node->value_int = ast_node1->value_int;
    ast_node->value_float = ast_node->value_int;
    printf("%d\n", ast_node1->value_int);
}

void    instruct_dump(t_ast_node *ast_node, t_ast_node *ast_node1)
{
    if (ast_node1->node_type != AST_NULL)
    {
        fprintf(stderr, "dump: too many arguments\n");
        exit(0);
    }
    ast_node->var_type = T_VOID;
    ast_node->value_int = 0;
    ast_node->value_float = ast_node->value_int;
    printf("dump\n");
}

void    instruct_print(t_ast_node *ast_node, t_ast_node *ast_node1)
{
    if (ast_node1->node_type != AST_NULL)
    {
        fprintf(stderr, "print: too many arguments\n");
        exit(0);
    }
    ast_node->var_type = T_VOID;
    ast_node->value_int = 0;
    ast_node->value_float = ast_node->value_int;
    printf("print\n");
}
