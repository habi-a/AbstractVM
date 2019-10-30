/*
** my_put.c for my_printf in /Users/habi_a/Documents
**
** Made by HABI Açal
** Login   <habi_a@etna-alternance.net>
**
** Started on  Tue Dec 26 13:19:03 2017 HABI Açal
** Last update Thu Jul 19 10:12:26 2018 HABI Açal
*/

#include <my.h>
#include <my_puts.h>
#include <stdlib.h>

unsigned int my_put_percent(va_list variables, unsigned int count)
{
    (void) variables;
    my_putchar('%');
    count++;
    return (count);
}

unsigned int    my_put_c(va_list variables, unsigned int count)
{
    char        var;

    var = (char) va_arg(variables, int);
    my_putchar(var);
    count++;
    return (count);
}

unsigned int    my_put_d(va_list variables, unsigned int count)
{
    int         var;

    var = va_arg(variables, int);
    my_putnbr(var);
    count += my_nbrlen(var);
    return (count);
}

unsigned int    my_put_i(va_list variables, unsigned int count)
{
    int         var;

    var = va_arg(variables, int);
    my_putnbr(var);
    count += my_nbrlen(var);
    return (count);
}

unsigned int    my_put_s(va_list variables, unsigned int count)
{
    char        *var;

    var = my_strdup(va_arg(variables, char *));
    if (var == NULL) {
        my_putstr("(null)");
        count += 6;
        return (count);
    }
    my_putstr(var);
    count += my_strlen(var);
    free(var);
    return (count);
}
