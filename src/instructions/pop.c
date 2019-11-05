/*
** ETNA PROJECT, 31/10/2019 by courta_f
** c:\Users\Fr4nck\Desktop\group-716039
** File description:
**
*/

#include <my.h>
#include <instructions.h>
#include <stdlib.h>

stack_node_t        *instruct_pop(ast_node_t *ast_node1, stack_node_t *stack)
{
    stack_data_t    data_popped;

    if (ast_node1->node_type != AST_NULL) {
        my_printf("pop: too many arguments\n");
        return (stack);
    }
    stack = pop(stack, &data_popped);
    return (stack);
}
