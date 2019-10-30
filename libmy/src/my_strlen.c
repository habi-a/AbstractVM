/*
** my_strlen.c for libmy in /Users/habi_a/Documents
**
** Made by HABI Açal
** Login   <habi_a@etna-alternance.net>
**
** Started on  Fri Apr  6 10:02:33 2018 HABI Açal
** Last update Fri Apr  6 10:02:41 2018 HABI Açal
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
