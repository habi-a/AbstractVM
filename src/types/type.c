/*
** ETNA PROJECT, 31/10/2019 by courta_f
** c:\Users\Fr4nck\Desktop\group-716039
** File description:
**      
*/

#include <types.h>
#include <stdlib.h>
#include <string.h>

type_t              *get_type(type_t type_list[NB_TYPES], const char *type_name)
{
    unsigned short  i = 0;

    for (i = 0; i < NB_TYPES; i++)
        if (!strcmp(type_list[i].type_name, type_name))
            return (&type_list[i]);
    return (NULL);
}

void			    free_list_types(type_t type_list[NB_TYPES])
{
    unsigned short  i = 0;

    for (i = 0; i < NB_TYPES; i++)
        free((char *)type_list[i].type_name);
}
