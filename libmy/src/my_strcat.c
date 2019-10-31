/*
** ETNA PROJECT, 31/10/2019 by courta_f
** c:\Users\Fr4nck\Desktop\group-716039
** File description:
**      
*/

#include <my.h>
#include <stdlib.h>

char                *my_strcat(char *dest, const char *src)
{
    unsigned int    i;
    unsigned int    len;

    if (src == NULL || dest == NULL)
        return (NULL);
    i = 0;
    len = my_strlen(dest);
    while (src[i]) {
        dest[len + i] = src[i];
        i++;
    }
    dest[len + i] = '\0';
    return (dest);
}
