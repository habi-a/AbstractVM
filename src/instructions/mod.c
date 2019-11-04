/*
** ETNA PROJECT, 31/10/2019 by courta_f
** c:\Users\Fr4nck\Desktop\group-716039
** File description:
**
*/

#include <my.h>
#include <instructions.h>
#include <stdlib.h>

static bool_t mod_helper(stack_data_t *data1, stack_data_t *data2)
{
    if (data1->var_type == T_DOUBLE || data2->var_type == T_DOUBLE) {
        my_printf("mod: modulo with T_DOUBLE forbidden\n");
        return (e_false);
    }
    if (data1->var_type == T_FLOAT || data2->var_type == T_FLOAT) {
        my_printf("mod: modulo with T_FLOAT forbidden\n");
        return (e_false);
    }
    if (data1->var_type > data2->var_type)
        data2->var_type = data1->var_type;
    if (!data1->value_int32) {
        my_printf("mod: modulo by 0 forbidden\n");
        return (e_false);
    }
    data2->value_int8 %= data1->value_int8;
    data2->value_int16 %= data1->value_int16;
    data2->value_int32 %= data1->value_int32;
    data2->value_float = data1->value_int32;
    data2->value_double = data1->value_int32;
    return (e_true);
}

stack_node_t        *instruct_mod(ast_node_t *ast_node1, stack_node_t *stack)
{
    stack_data_t    data1;
    stack_data_t    data2;

    if (ast_node1->node_type != AST_NULL) {
        my_printf("mod: too many arguments\n");
        return (NULL);
    }
    stack = pop(stack, &data1);
    stack = pop(stack, &data2);
    if (!mod_helper(&data1, &data2))
        return (NULL);
    stack = push(stack, data2);
    return (stack);
}
