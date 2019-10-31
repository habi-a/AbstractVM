/*
** ETNA PROJECT, 31/10/2019 by courta_f & habi_a
** c:\Users\Fr4nck\Desktop\group-716039
** File description:
**      
*/

#include <instructions.h>
#include <stdlib.h>

static void         mod_helper(stack_data_t *data1, stack_data_t *data2)
{
    if (data1->var_type == T_DOUBLE || data2->var_type == T_DOUBLE) {
        fprintf(stderr, "mod: modulo with T_DOUBLE forbidden\n");
        exit(0);
    }
    if (data1->var_type == T_FLOAT || data2->var_type == T_FLOAT) {
        fprintf(stderr, "mod: modulo with T_FLOAT forbidden\n");
        exit(0);
    }
    if (data1->var_type > data2->var_type)
        data2->var_type = data1->var_type;
    if (!data1->value_int32) {
        fprintf(stderr, "mod: modulo by 0 forbidden\n");
        exit(0);
    }
    data2->value_int8 %= data1->value_int8;
    data2->value_int16 %= data1->value_int16;
    data2->value_int32 %= data1->value_int32;
    data2->value_float = data1->value_int32;
    data2->value_double = data1->value_int32;
}

stack_node_t        *instruct_mod(ast_node_t *ast_node1, stack_node_t *stack)
{
    stack_data_t    data1;
    stack_data_t    data2;

    if (ast_node1->node_type != AST_NULL) {
        fprintf(stderr, "mod: too many arguments\n");
        exit(0);
    }
    stack = pop(stack, &data1);
    stack = pop(stack, &data2);
    mod_helper(&data1, &data2);
    stack = push(stack, data2);
    return (stack);
}
