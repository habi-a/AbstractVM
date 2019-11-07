/*
** ETNA PROJECT, 31/10/2019 by courta_f
** c:\Users\Fr4nck\Desktop\group-716039
** File description:
**
*/

#include <instructions.h>
#include <my.h>
#include <stdlib.h>

static void add_helper(stack_data_t *data1, stack_data_t *data2)
{
    if (data1->var_type > data2->var_type)
        data2->var_type = data1->var_type;
    data2->value_int8 += data1->value_int8;
    data2->value_int16 += data1->value_int16;
    data2->value_int32 += data1->value_int32;
    data2->value_float += data1->value_float;
    data2->value_double += data1->value_double;
}

stack_node_t *instruct_add(ast_node_t *ast_node1, stack_node_t *stack)
{
    stack_data_t data1;
    stack_data_t data2;

    if (ast_node1->node_type != AST_NULL) {
        my_printf("add: too many arguments\n");
        return (stack);
    }
    stack = pop(stack, &data1);
    stack = pop(stack, &data2);
    if (data1.var_type == T_NULL || data2.var_type == T_NULL) {
        my_printf("add: not enough element in the stack\n");
        data2 = data1;
    }
    else
        add_helper(&data1, &data2);
    stack = push(stack, data2);
    return (stack);
}
