#include <instruction.h>
#include <stdlib.h>
#include <string.h>

void			init_list_instructions(t_instruct_list *list)
{
    list->size = 0;
    list->first = NULL;
    list->last = NULL;
}

t_instruct_node      *get_instruction(t_instruct_list *list, const char *instruct_name)
{
    t_instruct_node  *tmp;

    tmp = list->first;
    while (tmp)
    {
        if (!strcmp(tmp->instruct_name, instruct_name))
            return (tmp);
        tmp = tmp->next;
    }
    return (NULL);
}

void            push_back_instruction(t_instruct_list *list, const char *instruct_name, t_ptr_instruction instruction_b_in)
{
    t_instruct_node *new_element;

    new_element = malloc(sizeof(t_instruct_node));
    if (new_element == NULL)
        return ;
    new_element->instruct_name = instruct_name;
    new_element->exec_function = instruction_b_in;
    new_element->next = NULL;
    list->size++;
    if (list->last != NULL)
        list->last->next = new_element;
    else
        list->first = new_element;
    list->last = new_element;
}

void            fill_instructions(t_instruct_list *list)
{
    push_back_instruction(list, strdup("push"), &my_push);
}

void			free_list_instructions(t_instruct_list *list)
{
    t_instruct_node	*tmp;
    t_instruct_node	*p_elem;

    if (list == NULL)
        return ;
    p_elem = list->first;
    while (p_elem != NULL)
    {
        tmp = p_elem;
        p_elem = p_elem->next;
        free((char *)tmp->instruct_name);
        free(tmp);
    }
    list->first = NULL;
    list->last = NULL;
}
