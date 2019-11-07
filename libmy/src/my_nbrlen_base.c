/*
** ETNA PROJECT, 31/10/2019 by courta_f
** c:\Users\Fr4nck\Desktop\group-716039
** File description:
**      
*/

#include <my.h>

void        my_long_nbrlen_base(long n, const char *base
                                ,unsigned int *buffer)
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

void                my_un_nbrlen_base(unsigned int n, const char *base
                                      ,unsigned int *buffer)
{
    unsigned int    i;

    i = n / my_strlen(base);
    if (i > 0)
        my_un_nbrlen_base(i, base, buffer);
    *buffer = *buffer + 1;
}

void                my_nbrlen_base(int n, const char *base
                                   ,unsigned int *buffer)
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
