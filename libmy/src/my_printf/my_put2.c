/*
** ETNA PROJECT, 31/10/2019 by courta_f
** c:\Users\Fr4nck\Desktop\group-716039
** File description:
**
*/

#include <my.h>
#include <my_puts.h>
#include <stdlib.h>

unsigned int my_put_o(va_list variables, unsigned int count)
{
    unsigned int var;
    unsigned int *buffer_size;

    buffer_size = malloc(sizeof(unsigned int));
    if (buffer_size == NULL)
        return (count);
    *buffer_size = 0;
    var = va_arg(variables, unsigned int);
    my_put_un_nbr_base(var, "01234567");
    my_un_nbrlen_base(var, "01234567", buffer_size);
    count += *buffer_size;
    free(buffer_size);
    return (count);
}

unsigned int my_put_u(va_list variables, unsigned int count)
{
    unsigned int var;

    var = va_arg(variables, unsigned int);
    my_put_un_nbr(var);
    count += my_un_nbrlen(var);
    return (count);
}

unsigned int my_put_x(va_list variables, unsigned int count)
{
    unsigned int var;
    unsigned int *buffer_size;

    buffer_size = malloc(sizeof(unsigned int));
    if (buffer_size == NULL)
        return (count);
    *buffer_size = 0;
    var = va_arg(variables, unsigned int);
    my_put_un_nbr_base(var, "0123456789abcdef");
    my_un_nbrlen_base(var, "0123456789abcdef", buffer_size);
    count += *buffer_size;
    free(buffer_size);
    return (count);
}

unsigned int my_put_xx(va_list variables, unsigned int count)
{
    unsigned int var;
    unsigned int *buffer_size;

    buffer_size = malloc(sizeof(unsigned int));
    if (buffer_size == NULL)
        return (count);
    *buffer_size = 0;
    var = va_arg(variables, unsigned int);
    my_put_un_nbr_base(var, "0123456789ABCDEF");
    my_un_nbrlen_base(var, "0123456789ABCDEF", buffer_size);
    count += *buffer_size;
    free(buffer_size);
    return (count);
}

unsigned int my_put_p(va_list variables, unsigned int count)
{
    long var;
    unsigned int *buffer_size = malloc(sizeof(unsigned int));

    if (buffer_size == NULL)
        return (count);
    *buffer_size = 0;
    var = va_arg(variables, long);
    if (!var) {
        my_putstr("(nil)");
        count += 5;
        free(buffer_size);
        return (count);
    }
    my_putstr("0x");
    count += 2;
    my_put_long_nbr_base(var, "0123456789abcdef");
    my_long_nbrlen_base(var, "0123456789abcdef", buffer_size);
    count += *buffer_size;
    free(buffer_size);
    return (count);
}
