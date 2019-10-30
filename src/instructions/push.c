#include <instructions.h>
#include <stdlib.h>

stack_node_t        *instruct_push(ast_node_t *ast_node1, stack_node_t *stack)
{
    stack_data_t    data_to_push;

    if (ast_node1->node_type == AST_NULL) {
        fprintf(stderr, "push: too few arguments\n");
        exit(0);
    } else if (ast_node1->node_type != AST_TYPE) {
        fprintf(stderr, "push: argument of type AST_TYPE expected\n");
        exit(0);
    }
    data_to_push.var_type = ast_node1->var_type;
    data_to_push.value_int8 = ast_node1->value_int8;
    data_to_push.value_int16 = ast_node1->value_int16;
    data_to_push.value_int32 = ast_node1->value_int32;
    data_to_push.value_float = ast_node1->value_float;
    data_to_push.value_double = ast_node1->value_double;
    stack = push(stack, data_to_push);
    return (stack);
}
