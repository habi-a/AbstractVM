/*
** ETNA PROJECT, 31/10/2019 by courta_f
** c:\Users\Fr4nck\Desktop\group-716039
** File description:
**
*/

#include <my.h>
#include <instructions.h>
#include <stdlib.h>

instruct_t          *get_instruction(instruct_t instruct_list[NB_INSTRUCT],
                                        const char *instruct_name)
{
    unsigned short  i = 0;

    for (i = 0; i < NB_INSTRUCT; i++)
        if (!my_strcmp(instruct_list[i].instruct_name, instruct_name))
            return (&instruct_list[i]);
    return (NULL);
}

void                free_list_instructions(instruct_t instrct_list[NB_INSTRUCT])
{
    unsigned short i = 0;

    for (i = 0; i < NB_INSTRUCT; i++)
        free((char *)instrct_list[i].instruct_name);
}
