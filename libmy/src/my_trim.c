/*
** my_trim.c for libmy in /Users/habi_a/Documents
**
** Made by HABI Açal
** Login   <habi_a@etna-alternance.net>
**
** Started on  Fri Apr  6 10:02:55 2018 HABI Açal
** Last update Fri Apr  6 10:03:04 2018 HABI Açal
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
