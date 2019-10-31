/*
** ETNA PROJECT, 31/10/2019 by courta_f & habi_a
** c:\Users\Fr4nck\Desktop\group-716039
** File description:
**      
*/

#include <stdlib.h>

int                 my_strcmp(const char *s1, const char *s2)
{
    unsigned int    i;

    if (s1 == NULL || s2 == NULL)
        return (0);
    i = 0;
    while (s1[i] && s2[i] && s1[i] == s2[i])
        ++i;
    return (s1[i] - s2[i]);
}
