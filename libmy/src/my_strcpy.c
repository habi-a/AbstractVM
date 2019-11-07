/*
** ETNA PROJECT, 31/10/2019 by courta_f
** c:\Users\Fr4nck\Desktop\group-716039
** File description:
**
*/

#include <stdlib.h>

char *my_strcpy(char *dest, const char *src)
{
    unsigned int i;

    if (src == NULL || dest == NULL)
        return (NULL);
    i = 0;
    while (src[i]) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char *my_strncpy(char *dest, const char *src, unsigned int n)
{
    unsigned int i;

    if (src == NULL || dest == NULL)
        return (NULL);
    i = 0;
    while (src[i] && i < n) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char *my_strrcpy(char *dest, const char *src, unsigned int r)
{
    unsigned int i = 0;
    unsigned int j = r;

    if (src == NULL || dest == NULL)
        return (NULL);
    while (src[j]) {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return (dest);
}
