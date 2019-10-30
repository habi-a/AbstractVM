/*
** my_putchar.c for libmy in /Users/habi_a/Documents
**
** Made by HABI Açal
** Login   <habi_a@etna-alternance.net>
**
** Started on  Fri Apr  6 10:03:24 2018 HABI Açal
** Last update Fri Apr  6 10:03:29 2018 HABI Açal
*/
#include <unistd.h>

void my_putchar(const char c)
{
    write(1, &c, 1);
}
