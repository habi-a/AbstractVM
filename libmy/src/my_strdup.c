/*
** ETNA PROJECT, 31/10/2019 by courta_f
** c:\Users\Fr4nck\Desktop\group-716039
** File description:
**
*/

#include <my.h>
#include <stdlib.h>

char *my_strdup(const char *src)
{
    char *dest;
    unsigned int len;

    if (src == NULL)
        return (0);
    len = my_strlen(src) + 1;
    dest = malloc(len * sizeof(char));
    if (dest == NULL)
        return (NULL);
    my_strcpy(dest, src);
    return (dest);
}

char *my_strndup(char *str, unsigned int n)
{
    char *dest;

    if (str == NULL)
        return (NULL);
    dest = malloc((n + 1) * sizeof(char));
    if (dest == NULL)
        return (NULL);
    my_strncpy(dest, str, n);
    return (dest);
}

char *my_strrdup(char *str, unsigned int r)
{
    char *dest;
    unsigned int len;

    if (str == NULL)
        return (NULL);
    len = my_strlen(str) - r + 1;
    dest = malloc(len * sizeof(char));
    if (dest == NULL)
        return (NULL);
    my_strrcpy(dest, str, r);
    return (dest);
}
