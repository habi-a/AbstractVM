#include <instructions.h>
#include <stdlib.h>

stack_node_t        *instruct_pop(ast_node_t *ast_node1, stack_node_t *stack)
{
    stack_data_t    data_popped;

    if (ast_node1->node_type != AST_NULL) {
        fprintf(stderr, "pop: too many arguments\n");
        exit(0);
    }
    stack = pop(stack, &data_popped);
    return (stack);
}
