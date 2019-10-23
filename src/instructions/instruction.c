#include <instructions.h>
#include <stdlib.h>
#include <string.h>

t_instruct          *get_instruction(t_instruct instruct_list[NB_INSTRUCTIONS],
                                        const char *instruct_name)
{
    unsigned short  i = 0;

    for (i = 0; i < NB_INSTRUCTIONS; i++)
        if (!strcmp(instruct_list[i].instruct_name, instruct_name))
            return (&instruct_list[i]);
    return (NULL);
}

void                free_list_instructions(t_instruct instruct_list[NB_INSTRUCTIONS])
{
    unsigned short  i = 0;

    for (i = 0; i < NB_INSTRUCTIONS; i++)
        free((char *)instruct_list[i].instruct_name);
}
