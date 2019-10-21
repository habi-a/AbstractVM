#include <functions.h>
#include <stdlib.h>
#include <string.h>

void			init_list_functions(t_func_list *list)
{
    list->size = 0;
    list->first = NULL;
    list->last = NULL;
}

t_func_node      *get_function(t_func_list *list, const char *func_name)
{
    t_func_node  *tmp;

    tmp = list->first;
    while (tmp)
    {
        if (!strcmp(tmp->func_name, func_name))
            return (tmp);
        tmp = tmp->next;
    }
    return (NULL);
}

void            push_back_function(t_func_list *list, const char *func_name, t_ptr_built_in function_b_in)
{
    t_func_node *new_element;

    new_element = malloc(sizeof(t_func_node));
    if (new_element == NULL)
        return ;
    new_element->func_name = func_name;
    new_element->func_type = FUNC_BUILT_IN;
    new_element->ptr_built_in = function_b_in;
    new_element->next = NULL;
    list->size++;
    if (list->last != NULL)
        list->last->next = new_element;
    else
        list->first = new_element;
    list->last = new_element;
}

void            fill_built_int_functions(t_func_list *list)
{
    push_back_function(list, strdup("int8"), &my_int8);
    push_back_function(list, strdup("int16"), &my_int16);
    push_back_function(list, strdup("int32"), &my_int32);
    push_back_function(list, strdup("float"), &my_int);
    push_back_function(list, strdup("double"), &my_int8);
}

void			free_list_functions(t_func_list *list)
{
    t_func_node	*tmp;
    t_func_node	*p_elem;

    if (list == NULL)
        return ;
    p_elem = list->first;
    while (p_elem != NULL)
    {
        tmp = p_elem;
        p_elem = p_elem->next;
        free((char *)tmp->func_name);
        free(tmp);
    }
    list->first = NULL;
    list->last = NULL;
}
