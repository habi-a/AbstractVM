#include <instructions.h>
#include <stdlib.h>

t_stack_node        *instruct_pop(t_ast_node *ast_node1, t_stack_node *stack)
{
    t_stack_data    data_popped;

    if (ast_node1->node_type != AST_NULL)
    {
        fprintf(stderr, "pop: too many arguments\n");
        exit(0);
    }
    stack = pop(stack, &data_popped);
    return (stack);
}
