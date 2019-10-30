/*
** my_strcpy.c for libmy in /Users/habi_a/Documents
**
** Made by HABI Açal
** Login   <habi_a@etna-alternance.net>
**
** Started on  Fri Apr  6 10:02:16 2018 HABI Açal
** Last update Thu Jul 12 17:48:43 2018 HABI Açal
*/
#include <stdlib.h>

char                *my_strcpy(char *dest, const char *src)
{
    unsigned int    i;

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

char                *my_strncpy(char *dest, const char *src, unsigned int n)
{
    unsigned int    i;

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

char                *my_strrcpy(char *dest, const char *src, unsigned int r)
{
    unsigned int    i;
    unsigned int    j;

    if (src == NULL || dest == NULL)
        return (NULL);
    i = 0;
    j = r;
    while (src[j]) {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return (dest);
}
