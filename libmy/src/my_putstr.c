/*
** my_putstr.c for libmy in /Users/habi_a/Documents
**
** Made by HABI Açal
** Login   <habi_a@etna-alternance.net>
**
** Started on  Fri Apr  6 10:02:16 2018 HABI Açal
** Last update Fri Apr  6 10:02:21 2018 HABI Açal
*/
#include <my.h>
#include <stdlib.h>

void                my_putstr(const char *str)
{
    unsigned int    i = 0;

    if (str == NULL)
        return ;
    while (str[i]) {
        my_putchar(str[i]);
        i++;
    }
}
