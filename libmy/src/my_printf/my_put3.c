/*
** my_put_next_bis.c for my_printf in /Users/habi_a/Documents
**
** Made by HABI Açal
** Login   <habi_a@etna-alternance.net>
**
** Started on  Mon Jul 23 16:16:53 2018 HABI Açal
** Last update Mon Jul 23 16:37:43 2018 HABI Açal
*/

#include <my.h>
#include <my_puts.h>
#include <stdlib.h>

unsigned int        my_put_b(va_list variables, unsigned int count)
{
    unsigned int    var;
    unsigned int    *buffer_size;

    buffer_size = malloc(sizeof(unsigned int));
    if (buffer_size == NULL)
        return (count);
    *buffer_size = 0;
    var = va_arg(variables, unsigned int);
    my_put_un_nbr_base(var, "01");
    my_un_nbrlen_base(var, "01", buffer_size);
    count += *buffer_size;
    free(buffer_size);
    return (count);
}

static void my_putchar_S(const char c, unsigned int *buffer_size)
{
    if (c < 10 && c > 0) {
        my_putstr("\\00");
        my_putnbr_base((int) c, "01234567");
    } else if (c < 100 && c > 0) {
        my_putstr("\\0");
        my_putnbr_base((int) c, "01234567");
    } else if (c >= 0) {
        my_putchar('\\');
        my_putnbr_base((int) c, "01234567");
    }
    *buffer_size = *buffer_size + 4;
}

static void         my_putstr_S(const char *str, unsigned int *buffer_size)
{
    unsigned int    i;

    i = 0;
    while (str[i] != '\0') {
        if (my_isprintable(str[i])) {
            my_putchar(str[i]);
            *buffer_size = *buffer_size + 1;
        } else
            my_putchar_S(str[i], buffer_size);
        i++;
    }
}

unsigned int        my_put_S(va_list variables, unsigned int count)
{
    char            *var_string;
    unsigned int    *buffer_size;

    buffer_size = malloc(sizeof(unsigned int));
    if (buffer_size == NULL)
        return (count);
    *buffer_size = 0;
    var_string = my_strdup(va_arg(variables, char *));
    if (var_string == NULL) {
        my_putstr("(null)");
        count += 6;
        free(buffer_size);
        return (count);
    }
    my_putstr_S(var_string, buffer_size);
    count += *buffer_size;
    free(buffer_size);
    free(var_string);
    return (count);
}

unsigned int  my_put_l(va_list variables, unsigned int count)
{
    long var;

    var = va_arg(variables, long);
    my_put_long_nbr(var);
    count += my_long_nbrlen(var);
    return (count);
}
