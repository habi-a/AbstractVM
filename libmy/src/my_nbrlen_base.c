/*
** my_nbrlen_base.c for libmy in /Users/habi_a/Documents
**
** Made by HABI Açal
** Login   <habi_a@etna-alternance.net>
**
** Started on  Tue Dec 26 13:18:38 2017 HABI Açal
** Last update Tue Jul 24 09:51:36 2018 HABI Açal
*/
#include <my.h>

void        my_long_nbrlen_base(long n, const char *base,
                                  unsigned int *buffer)
{
    long    i;

    if (n < 0) {
        *buffer = *buffer + 1;
        n *= (-1);
    }
    i = n / my_strlen(base);
    if (i > 0)
        my_long_nbrlen_base(i, base, buffer);
    *buffer = *buffer + 1;
}

void                my_un_nbrlen_base(unsigned int n, const char *base,
                                unsigned int *buffer)
{
    unsigned int    i;

    i = n / my_strlen(base);
    if (i > 0)
        my_un_nbrlen_base(i, base, buffer);
    *buffer = *buffer + 1;
}

void                my_nbrlen_base(int n, const char *base,
                                    unsigned int *buffer)
{
    unsigned int    i;

    if (n < 0) {
        *buffer = *buffer + 1;
        n *= (-1);
    }
    i = n / my_strlen(base);
    if (i > 0)
        my_nbrlen_base(i, base, buffer);
    *buffer = *buffer + 1;
}
