/*
** ETNA PROJECT, 31/10/2019 by courta_f
** c:\Users\Fr4nck\Desktop\group-716039
** File description:
**
*/

#include <my.h>
#include <my_puts.h>
#include <stdlib.h>

unsigned int        my_put_f(va_list variables, unsigned int count)
{
    float           var;

    var = (float)va_arg(variables, double);
    my_put_nbr_float(var);
    count += my_nbrlen(var);
    return (count);
}

unsigned int        my_put_t(va_list variables, unsigned int count)
{
    double          var;

    var = va_arg(variables, double);
    my_put_nbr_double(var);
    count += my_nbrlen(var);
    return (count);
}
