#include <stack.h>
#include <stdlib.h>
#include <string.h>

unsigned short      isEmpty(t_stack_node *stack)
{
    return (!stack);
}

t_stack_node        *push(t_stack_node *stack, t_stack_data data)
{
    t_stack_node    *stack_node = (t_stack_node *)malloc(sizeof(t_stack_node));

    stack_node->data = data;
    stack_node->next = stack;
    stack = stack_node;
    return (stack);
}

t_stack_node        *pop(t_stack_node *stack, t_stack_data *data)
{
    t_stack_node    *tmp = NULL;

    if (isEmpty(stack))
        return (NULL);
    tmp = stack;
    *data = tmp->data;
    stack = stack->next;
    printf("%d popped from the stack\n", data->value_int);
    free(tmp);
    return (stack);
}

t_stack_data        peek(t_stack_node *stack)
{
    t_stack_data    empty_data = {T_VOID, 0, 0, 0};

    if (isEmpty(stack))
        return (empty_data);
    return (stack->data);
}


void                free_stack(t_stack_node *stack)
{
    t_stack_node    *tmp;

    while (stack != NULL)
    {
        tmp = stack;
        stack = stack->next;
        free(tmp);
    }
}
