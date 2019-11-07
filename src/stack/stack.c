/*
** ETNA PROJECT, 31/10/2019 by courta_f
** c:\Users\Fr4nck\Desktop\group-716039
** File description:
**
*/

#include <stack.h>
#include <stdlib.h>

unsigned short is_empty(stack_node_t *stack)
{
    return (!stack);
}

stack_node_t *push(stack_node_t *stack, stack_data_t data)
{
    stack_node_t *stack_node = (stack_node_t *)malloc(sizeof(stack_node_t));

    stack_node->data = data;
    stack_node->next = stack;
    stack = stack_node;
    return (stack);
}

stack_node_t *pop(stack_node_t *stack, stack_data_t *data)
{
    stack_node_t *tmp = NULL;

    if (is_empty(stack)) {
        data->var_type = T_NULL;
        return (NULL);
    }
    tmp = stack;
    *data = tmp->data;
    stack = stack->next;
    free(tmp);
    return (stack);
}

stack_data_t peek(stack_node_t *stack)
{
    stack_data_t empty_data = {T_VOID, 0, 0, 0, 0, 0};

    if (is_empty(stack))
        return (empty_data);
    return (stack->data);
}

void free_stack(stack_node_t *stack)
{
    stack_node_t *tmp;

    while (stack != NULL) {
        tmp = stack;
        stack = stack->next;
        free(tmp);
    }
}
