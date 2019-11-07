/*
** ETNA PROJECT, 31/10/2019 by courta_f
** c:\Users\Fr4nck\Desktop\group-716039
** File description:
**
*/

#include <my.h>
#include <stdlib.h>

void my_putstr(const char *str)
{
    unsigned int i = 0;

    if (str == NULL)
        return ;
    while (str[i]) {
        my_putchar(str[i]);
        i++;
    }
}
