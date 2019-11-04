/*
** ETNA PROJECT, 31/10/2019 by courta_f
** c:\Users\Fr4nck\Desktop\group-716039
** File description:
**
*/

#include <my.h>
#include <instructions.h>
#include <stdlib.h>

static unsigned short assert_helper(ast_node_t *ast_node1, stack_data_t *data1)
{
    switch (data1->var_type) {
        case T_INT32:
            return ((data1->value_int32 == ast_node1->value_int32) ? 1 : 0);
        case T_INT16:
            return ((data1->value_int16 == ast_node1->value_int16) ? 1 : 0);
        case T_INT8:
            return ((data1->value_int8 == ast_node1->value_int8) ? 1 : 0);
        case T_FLOAT:
            return ((data1->value_float == ast_node1->value_float) ? 1 : 0);
        case T_DOUBLE:
            return ((data1->value_double == ast_node1->value_float) ? 1 : 0);
        default:
            break;
    }
    return (0);
}

stack_node_t        *instruct_assert(ast_node_t *ast_node1, stack_node_t *stack)
{
    stack_data_t    data1;

    if (ast_node1->node_type == AST_NULL) {
        my_printf("assert: too few arguments\n");
        return (NULL);
    } else if (ast_node1->node_type != AST_TYPE) {
        my_printf("assert: argument of type AST_TYPE expected\n");
        return (NULL);
    }
    data1 = peek(stack);
    if (data1.var_type != ast_node1->var_type
        || !assert_helper(ast_node1, &data1)) {
        my_printf("assert: values not equals\n");
        return (NULL);
    }
    return (stack);
}
