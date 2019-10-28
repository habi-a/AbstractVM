#include <instructions.h>
#include <stdlib.h>

static void         mod_helper(t_stack_data *data1, t_stack_data *data2)
{
    if (data1->var_type == T_DOUBLE || data2->var_type == T_DOUBLE) {
        fprintf(stderr, "mod: modulo with T_DOUBLE forbidden\n");
        exit(0);
    }
    if (data1->var_type == T_FLOAT || data2->var_type == T_FLOAT) {
        fprintf(stderr, "mod: modulo with T_FLOAT forbidden\n");
        exit(0);
    }
    data2->var_type = T_INT;
    if (!data1->value_int) {
        fprintf(stderr, "mod: modulo by 0 forbidden\n");
        exit(0);
    }
    data2->value_int %= data1->value_int;
}

t_stack_node        *instruct_mod(t_ast_node *ast_node1, t_stack_node *stack)
{
    t_stack_data    data1;
    t_stack_data    data2;

    if (ast_node1->node_type != AST_NULL)
    {
        fprintf(stderr, "mod: too many arguments\n");
        exit(0);
    }
    stack = pop(stack, &data1);
    stack = pop(stack, &data2);
    mod_helper(&data1, &data2);
    stack = push(stack, data2);
    printf("mod\n");
    return (stack);
}
