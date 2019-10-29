#include <instructions.h>
#include <stdlib.h>

static void         add_helper(t_stack_data *data1, t_stack_data *data2)
{
    if (data1->var_type == T_DOUBLE || data2->var_type == T_DOUBLE)
        data2->var_type = T_DOUBLE;
    else if (data1->var_type == T_FLOAT || data2->var_type == T_FLOAT)
        data2->var_type = T_FLOAT;
    else if (data1->var_type == T_INT32 || data2->var_type == T_INT32)
        data2->var_type = T_INT32;
    else if (data1->var_type == T_INT16 || data2->var_type == T_INT16)
        data2->var_type = T_INT16;
    else
        data2->var_type = T_INT8;
    data2->value_int8 += data1->value_int8;
    data2->value_int16 += data1->value_int16;
    data2->value_int32 += data1->value_int32;
    data2->value_float += data1->value_float;
    data2->value_double += data1->value_double;
}

t_stack_node        *instruct_add(t_ast_node *ast_node1, t_stack_node *stack)
{
    t_stack_data    data1;
    t_stack_data    data2;

    if (ast_node1->node_type != AST_NULL)
    {
        fprintf(stderr, "add: too many arguments\n");
        exit(0);
    }
    stack = pop(stack, &data1);
    stack = pop(stack, &data2);
    add_helper(&data1, &data2);
    stack = push(stack, data2);
    return (stack);
}
