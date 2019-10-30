/*
** my_strcat.c for libmy in /Users/habi_a/Documents
**
** Made by HABI Açal
** Login   <habi_a@etna-alternance.net>
**
** Started on  Fri Apr  6 10:01:48 2018 HABI Açal
** Last update Fri Apr  6 10:01:55 2018 HABI Açal
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
