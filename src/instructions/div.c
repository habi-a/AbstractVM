#include <instructions.h>
#include <stdlib.h>

static void         div_helper(t_stack_data *data1, t_stack_data *data2)
{
    if (data1->var_type == T_DOUBLE || data2->var_type == T_DOUBLE)
        data2->var_type = T_DOUBLE;
    else if (data1->var_type == T_FLOAT || data2->var_type == T_FLOAT)
        data2->var_type = T_FLOAT;
    else
        data2->var_type = T_INT;
    if (!data1->value_double)
    {
        fprintf(stderr, "div: division by 0 forbidden\n");
        exit(0);
    }
    data2->value_int /= data1->value_int;
    data2->value_float /= data1->value_float;
    data2->value_double /= data1->value_double;
}

t_stack_node        *instruct_div(t_ast_node *ast_node1, t_stack_node *stack)
{
    t_stack_data    data1;
    t_stack_data    data2;

    if (ast_node1->node_type != AST_NULL)
    {
        fprintf(stderr, "div: too many arguments\n");
        exit(0);
    }
    stack = pop(stack, &data1);
    stack = pop(stack, &data2);
    div_helper(&data1, &data2);
    stack = push(stack, data2);
    printf("div\n");
    return (stack);
}
