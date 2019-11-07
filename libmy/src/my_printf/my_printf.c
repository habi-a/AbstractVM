/*
** ETNA PROJECT, 31/10/2019 by courta_f
** c:\Users\Fr4nck\Desktop\group-716039
** File description:
**
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
    {'X', &my_put_xx},
    {'p', &my_put_p},
    {'b', &my_put_b},
    {'S', &my_put_ss},
    {'l', &my_put_l},
    {'f', &my_put_f},
    {'t', &my_put_t}
};

static flags_t get_flag(char key)
{
    unsigned int i;
    flags_t flag_error;

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

int my_printf(const char *format, ...)
{
    unsigned int i = 0;
    unsigned int count = 0;
    va_list variables;

    if (format == NULL)
        return (-1);
    va_start(variables, format);
    while (format[i] != '\0') {
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
