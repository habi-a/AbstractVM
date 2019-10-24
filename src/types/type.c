#include <types.h>
#include <stdlib.h>
#include <string.h>

t_type              *get_type(t_type type_list[NB_TYPES], const char *type_name)
{
    unsigned short  i = 0;

    for (i = 0; i < NB_TYPES; i++)
        if (!strcmp(type_list[i].type_name, type_name))
            return (&type_list[i]);
    return (NULL);
}

void			    free_list_types(t_type type_list[NB_TYPES])
{
    unsigned short  i = 0;

    for (i = 0; i < NB_TYPES; i++)
        free((char *)type_list[i].type_name);
}
