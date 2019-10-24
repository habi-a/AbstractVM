#include <variables.h>
#include <stdlib.h>
#include <string.h>

unsigned short      isEmpty(t_stack_node *stack)
{
    return (!stack);
}

void                push(t_stack_node **stack, t_stack_data data)
{
    t_stack_node    *stack_node = (t_stack_node *)malloc(sizeof(t_stack_node));

    stack_node->data = data;
    stack_node->next = *stack;
    *stack = stack_node;
}

t_stack_data        pop(t_stack_node **stack)
{
    t_stack_node    *temp = NULL;
    t_stack_data    popped = NULL;

    if (isEmpty(*stack))
        return NULL;
    temp = *stack;
    *stack = (*stack)->next;
    popped = temp->data;
    free(temp);
    return (popped);
}

t_stack_data        peek(t_stack_node *stack)
{
    if (isEmpty(stack))
        return NULL;
    return (stack->data);
}


void                free_stack(t_stack_node *stack)
{
    t_stack_nod     *tmp;
    t_stack_node    *p_elem;

    if (stack == NULL)
        return ;
    p_elem = stack->first;
    while (p_elem != NULL)
    {
        tmp = p_elem;
        p_elem = p_elem->next;
        free(tmp);
    }
    stack->first = NULL;
    stack->last = NULL;
}
