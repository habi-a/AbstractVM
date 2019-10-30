#include <instructions.h>
#include <stdlib.h>

stack_node_t        *instruct_print(ast_node_t *ast_node1, stack_node_t *stack)
{
    stack_data_t    data1;

    if (ast_node1->node_type != AST_NULL) {
        fprintf(stderr, "print: too many arguments\n");
        exit(0);
    }
    data1 = peek(stack);
    if (data1.var_type != T_INT8) {
        fprintf(stderr, "print: value must be an T_INT8\n");
        exit(0);
    }
    if (data1.value_int8 >= 0)
        printf("print: %c\n", data1.value_int8);
    else
        printf("print: ????\n");
    return (stack);
}
