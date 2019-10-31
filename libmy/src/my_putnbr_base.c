/*
** ETNA PROJECT, 31/10/2019 by courta_f
** c:\Users\Fr4nck\Desktop\group-716039
** File description:
**      
*/

#include <my.h>

void        my_put_long_nbr_base(long n, const char *base)
{
    long    i;
    long    j;

    if (n < 0) {
        my_putchar('-');
        n *= (-1);
    }
    j = n % my_strlen(base);
    i = n / my_strlen(base);
    if (i > 0)
        my_put_long_nbr_base(i, base);
    my_putchar(base[j]);
}

void                my_put_un_nbr_base(unsigned int n, const char *base)
{
    unsigned int    i;
    unsigned int    j;

    j = n % my_strlen(base);
    i = n / my_strlen(base);
    if (i > 0)
        my_put_un_nbr_base(i, base);
    my_putchar(base[j]);
}

void        my_putnbr_base(int n, const char *base)
{
    int     i;
    int     j;

    if (n < 0) {
        my_putchar('-');
        n *= (-1);
    }
    j = n % my_strlen(base);
    i = n / my_strlen(base);
    if (i > 0)
        my_putnbr_base(i, base);
    my_putchar(base[j]);
}
