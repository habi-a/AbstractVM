/*
** ETNA PROJECT, 31/10/2019 by courta_f & habi_a
** c:\Users\Fr4nck\Desktop\group-716039
** File description:
**      
*/

#include <stdlib.h>

unsigned int        my_strlen(const char *str)
{
    unsigned int    i;

    if (str == NULL)
        return (0);
    i = 0;
    while (str[i])
        ++i;
    return (i);
}
