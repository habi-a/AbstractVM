#include <types.h>
#include <stdlib.h>
#include <string.h>

void			init_list_variables(t_var_list *list)
{
    list->size = 0;
    list->first = NULL;
    list->last = NULL;
}

t_var_node      *get_variable(t_var_list *list, const char *var_name)
{
    t_var_node  *tmp;

    tmp = list->first;
    while (tmp)
    {
        if (!strcmp(tmp->var_name, var_name))
            return (tmp);
        tmp = tmp->next;
    }
    return (NULL);
}


void			free_list_variables(t_var_list *list)
{
    t_var_node	*tmp;
    t_var_node	*p_elem;

    if (list == NULL)
        return ;
    p_elem = list->first;
    while (p_elem != NULL)
    {
        tmp = p_elem;
        p_elem = p_elem->next;
        free((char *)tmp->var_name);
        free(tmp);
    }
    list->first = NULL;
    list->last = NULL;
}
