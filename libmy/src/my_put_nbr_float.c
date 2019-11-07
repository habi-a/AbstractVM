/*
** ETNA PROJECT, 31/10/2019 by courta_f
** c:\Users\Fr4nck\Desktop\group-716039
** File description:
**
*/

#include <my.h>

void        my_put_nbr_float(float n)
{
    long    ent = n;
    long    dec = n * (float)1000000 - ent * 1000000;
    float	aff_dec = (float)dec;

    my_put_long_nbr_base(ent, "0123456789");
    my_putchar('.');
    if (aff_dec < 0)
        aff_dec *= (-1);
    my_put_long_nbr_base((long)aff_dec, "0123456789");
 }

 void        my_put_nbr_double(double n)
 {
     long    ent = n;
     long    dec = n * (double)1000000 - ent * 1000000;
     double	 aff_dec = (double)dec;

     my_put_long_nbr_base(ent, "0123456789");
     my_putchar('.');
     if (aff_dec < 0)
        aff_dec *= (-1);
     my_put_long_nbr_base((long)aff_dec, "0123456789");
  }
