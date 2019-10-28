#include <instructions.h>
#include <stdlib.h>

static unsigned short assert_helper(t_ast_node *ast_node1, t_stack_data *data1)
{
    switch (data1->var_type) {
        case T_INT:
            return ((data1->value_int == ast_node1->value_int) ? 1 : 0);
        case T_FLOAT:
            return ((data1->value_float == ast_node1->value_float) ? 1 : 0);
        case T_DOUBLE:
            return ((data1->value_double == ast_node1->value_float) ? 1 : 0);
        default:
            break;
    }
    return (0);
}

t_stack_node        *instruct_assert(t_ast_node *ast_node1, t_stack_node *stack)
{
    t_stack_data    data1;

    if (ast_node1->node_type == AST_NULL)
    {
        fprintf(stderr, "assert: too few arguments\n");
        exit(0);
    }
    else if (ast_node1->node_type != AST_TYPE)
    {
        fprintf(stderr, "assert: argument of type AST_TYPE expected\n");
        exit(0);
    }
    data1 = peek(stack);
    if (data1.var_type != ast_node1->var_type || !assert_helper(ast_node1, &data1)) {
        fprintf(stderr, "assert: values not equals\n");
        exit(0);
    }
    printf("assert\n");
    return (stack);
}