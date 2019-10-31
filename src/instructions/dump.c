/*
** ETNA PROJECT, 31/10/2019 by courta_f & habi_a
** c:\Users\Fr4nck\Desktop\group-716039
** File description:
**      
*/

#include <instructions.h>
#include <stdlib.h>

static void         print_value_by_type(stack_data_t *data)
{
    switch (data->var_type) {
        case T_INT8:
            printf("%d\n", data->value_int8);
            break;
        case T_INT16:
            printf("%d\n", data->value_int16);
            break;
        case T_INT32:
            printf("%d\n", data->value_int32);
            break;
        case T_FLOAT:
            printf("%f\n", data->value_float);
            break;
        case T_DOUBLE:
            printf("%lf\n", data->value_double);
            break;
        default:
            break;
    }
}

static void         dump_helper(stack_node_t* head)
{
    stack_node_t    *current;

    current = head;
    if (current!= NULL) {
        printf("Stack:\n");
        do {
            print_value_by_type(&(current->data));
            current = current->next;
        }
        while (current!= NULL);
    }
    else
        printf("The Stack is empty\n");

}

stack_node_t        *instruct_dump(ast_node_t *ast_node1, stack_node_t *stack)
{
    if (ast_node1->node_type != AST_NULL) {
        fprintf(stderr, "dump: too many arguments\n");
        exit(0);
    }
    dump_helper(stack);
    return (stack);
}
