/*
** my_printf.c for my_printf in /Users/habi_a/Documents
**
** Made by HABI Açal
** Login   <habi_a@etna-alternance.net>
**
** Started on  Thu Jul 19 09:52:11 2018 HABI Açal
** Last update Thu Jul 19 10:03:46 2018 HABI Açal
*/

#include <flags.h>
#include <my.h>
#include <my_puts.h>
#include <stdlib.h>

static const flags_t g_flags[] = {
    {'%', &my_put_percent},
    {'c', &my_put_c},
    {'s', &my_put_s},
    {'d', &my_put_d},
    {'i', &my_put_i},
    {'o', &my_put_o},
    {'u', &my_put_u},
    {'x', &my_put_x},
    {'X', &my_put_X},
    {'p', &my_put_p},
    {'b', &my_put_b},
    {'S', &my_put_S},
    {'l', &my_put_l}
};

static flags_t      get_flag(char key)
{
    unsigned int    i;
    flags_t         flag_error;

    i = 0;
    while (i < NB_FLAGS) {
        if (key == g_flags[i].key)
            return (g_flags[i]);
        i++;
    }
    flag_error.key = '\0';
    flag_error.p_my_put = NULL;
    return (flag_error);
}

int   my_printf(const char *format, ...)
{
    unsigned int i = 0;
    unsigned int count = 0;
    va_list  variables;

    if (format == NULL)
        return (-1);
    va_start(variables, format);
    while (format[i] != '\0')
    {
        if (format[i] == '%' && get_flag(format[i + 1]).key) {
            count = get_flag(format[i + 1]).p_my_put(variables, count);
            i++;
        } else {
            my_putchar(format[i]);
            count++;
        }
        i++;
    }
    va_end(variables);
    return ((signed) count);
}
