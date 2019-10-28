#include <instructions.h>
#include <stdlib.h>

t_stack_node        *instruct_print(t_ast_node *ast_node1, t_stack_node *stack)
{
    t_stack_data    data1;

    if (ast_node1->node_type != AST_NULL)
    {
        fprintf(stderr, "print: too many arguments\n");
        exit(0);
    }
    data1 = peek(stack);
    if (data1.var_type != T_INT)
    {
        fprintf(stderr, "print: value must be an T_INT8\n");
        exit(0);
    }
    if (data1.value_int >= 0)
        printf("%c\n", data1.value_int);
    else
        printf("????\n");
    printf("print\n");
    return (stack);
}
