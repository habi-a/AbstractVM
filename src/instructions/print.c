/*
** ETNA PROJECT, 31/10/2019 by courta_f
** c:\Users\Fr4nck\Desktop\group-716039
** File description:
**
*/

#include <my.h>
#include <instructions.h>
#include <stdlib.h>

stack_node_t        *instruct_print(ast_node_t *ast_node1, stack_node_t *stack)
{
    stack_data_t    data1;

    if (ast_node1->node_type != AST_NULL) {
        my_printf("print: too many arguments\n");
        return (NULL);
    }
    data1 = peek(stack);
    if (data1.var_type != T_INT8) {
        my_printf("print: value must be an T_INT8\n");
        return (NULL);
    }
    if (data1.value_int8 >= 0)
        my_printf("print: %c\n", data1.value_int8);
    else
        my_printf("print: ????\n");
    return (stack);
}
