/*
** ETNA PROJECT, 31/10/2019 by courta_f
** c:\Users\Fr4nck\Desktop\group-716039
** File description:
**      
*/

#include <my.h>

void                my_put_un_long_nbr(const unsigned long n)
{
    unsigned long   i;
    unsigned long   divisible;

    divisible = n / 10;
    i = n % 10;
    if (divisible != 0)
        my_put_un_long_nbr(divisible);
    my_putchar((char)i + (char)'0');
}

void                my_put_long_nbr(long n)
{
    if (n < 0) {
        my_putchar('-');
        n *= (-1);
    }
    my_put_un_long_nbr((unsigned long)n);
}

void                my_put_un_nbr(const unsigned int n)
{
    int             i;
    unsigned int    divisible;

    divisible = n / 10;
    i = n % 10;
    if (divisible != 0)
        my_put_un_nbr(divisible);
    my_putchar((char)i + (char)'0');
}

void my_putnbr(int n)
{
    if (n < 0) {
        my_putchar('-');
        n *= (-1);
    }
    my_put_un_nbr((unsigned int)n);
}
