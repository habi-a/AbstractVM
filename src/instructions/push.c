#include <instructions.h>
#include <stdlib.h>

t_stack_node        *instruct_push(t_ast_node *ast_node1, t_stack_node *stack)
{
    t_stack_data    data_to_push;

    if (ast_node1->node_type == AST_NULL)
    {
        fprintf(stderr, "push: too few arguments\n");
        exit(0);
    }
    else if (ast_node1->node_type != AST_TYPE)
    {
        fprintf(stderr, "push: argument of type AST_TYPE expected\n");
        exit(0);
    }
    data_to_push.var_type = ast_node1->var_type;
    data_to_push.value_int = ast_node1->value_int;
    data_to_push.value_float = ast_node1->value_float;
    data_to_push.value_double = ast_node1->value_double;
    stack = push(stack, data_to_push);
    printf("%d pushed to stack\n", stack->data.value_int);
    return (stack);
}
