#include <instructions.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

t_stack_node *instruct_push(t_ast_node *ast_node, t_ast_node *ast_node1, t_stack_node *stack)
{
    t_stack_data    data_to_push;

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
    ast_node->var_type = T_VOID;
    data_to_push.var_type = ast_node1->var_type;
    data_to_push.value_int = ast_node1->value_int;
    data_to_push.value_float = ast_node1->value_float;
    data_to_push.value_double = ast_node1->value_double;
    stack = push(stack, data_to_push);
    printf("%d pushed to stack\n", stack->data.value_int);
    return (stack);
}

t_stack_node *            instruct_pop(t_ast_node *ast_node, t_ast_node *ast_node1, t_stack_node *stack)
{
    t_stack_data    data_popped;

    if (ast_node1->node_type != AST_NULL)
    {
        fprintf(stderr, "pop: too many arguments\n");
        exit(0);
    }
    data_popped = peek(stack);
    ast_node->var_type = T_VOID;
    ast_node->value_int = 0;
    ast_node->value_float = ast_node->value_int;
    printf("pop: %d\n", data_popped.value_int);
    return (stack);
}

t_stack_node *instruct_add(t_ast_node *ast_node, t_ast_node *ast_node1, t_stack_node *stack)
{
    if (ast_node1->node_type != AST_NULL)
    {
        fprintf(stderr, "add: too many arguments\n");
        exit(0);
    }
    (void)stack;
    ast_node->var_type = T_VOID;
    ast_node->value_int = 0;
    ast_node->value_float = ast_node->value_int;
    printf("add\n");
    return (stack);
}

t_stack_node *instruct_sub(t_ast_node *ast_node, t_ast_node *ast_node1, t_stack_node *stack)
{
    if (ast_node1->node_type != AST_NULL)
    {
        fprintf(stderr, "sub: too many arguments\n");
        exit(0);
    }
    (void)stack;
    ast_node->var_type = T_VOID;
    ast_node->value_int = 0;
    ast_node->value_float = ast_node->value_int;
    printf("sub\n");
    return (stack);
}

t_stack_node *instruct_mul(t_ast_node *ast_node, t_ast_node *ast_node1, t_stack_node *stack)
{
    if (ast_node1->node_type != AST_NULL)
    {
        fprintf(stderr, "mul: too many arguments\n");
        exit(0);
    }
    (void)stack;
    ast_node->var_type = T_VOID;
    ast_node->value_int = 0;
    ast_node->value_float = ast_node->value_int;
    printf("mul\n");
    return (stack);
}

t_stack_node *instruct_div(t_ast_node *ast_node, t_ast_node *ast_node1, t_stack_node *stack)
{
    if (ast_node1->node_type != AST_NULL)
    {
        fprintf(stderr, "div: too many arguments\n");
        exit(0);
    }
    (void)stack;
    ast_node->var_type = T_VOID;
    ast_node->value_int = 0;
    ast_node->value_float = ast_node->value_int;
    printf("div\n");
    return (stack);
}

t_stack_node *instruct_mod(t_ast_node *ast_node, t_ast_node *ast_node1, t_stack_node *stack)
{
    if (ast_node1->node_type != AST_NULL)
    {
        fprintf(stderr, "mod: too many arguments\n");
        exit(0);
    }
    (void)stack;
    ast_node->var_type = T_VOID;
    ast_node->value_int = 0;
    ast_node->value_float = ast_node->value_int;
    printf("mod\n");
    return (stack);
}

t_stack_node *instruct_assert(t_ast_node *ast_node, t_ast_node *ast_node1, t_stack_node *stack)
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
    (void)stack;
    ast_node->var_type = ast_node1->var_type;
    ast_node->value_int = ast_node1->value_int;
    ast_node->value_float = ast_node->value_int;
    printf("%d\n", ast_node1->value_int);
    return (stack);
}

t_stack_node *instruct_dump(t_ast_node *ast_node, t_ast_node *ast_node1, t_stack_node *stack)
{
    if (ast_node1->node_type != AST_NULL)
    {
        fprintf(stderr, "dump: too many arguments\n");
        exit(0);
    }
    (void)stack;
    ast_node->var_type = T_VOID;
    ast_node->value_int = 0;
    ast_node->value_float = ast_node->value_int;
    printf("dump\n");
    return (stack);
}

t_stack_node *instruct_print(t_ast_node *ast_node, t_ast_node *ast_node1, t_stack_node *stack)
{
    if (ast_node1->node_type != AST_NULL)
    {
        fprintf(stderr, "print: too many arguments\n");
        exit(0);
    }
    display(stack);
    ast_node->var_type = T_VOID;
    ast_node->value_int = 0;
    ast_node->value_float = ast_node->value_int;
    printf("print\n");
    return (stack);
}
