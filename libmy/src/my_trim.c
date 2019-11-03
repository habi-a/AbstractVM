/*
** ETNA PROJECT, 31/10/2019 by courta_f
** c:\Users\Fr4nck\Desktop\group-716039
** File description:
**      
*/

#include <stdlib.h>
#include <my.h>

char                *my_trim(const char *str)
{
    unsigned int    offset1;
    unsigned int    offset2;
    char            *res;

    if (str == NULL)
        return (NULL);
    offset1 = 0;
    offset2 = 0;
    res = malloc(sizeof(char *) * (my_strlen(str) + 1));
    if (res == NULL)
        return (NULL);
    while (str[offset1]) {
        if (my_isalnum(str[offset1]))
            res[(offset2++)] = str[offset1];
        offset1++;
    }
    res[offset2] = '\0';
    return (res);
}
