/*
** ETNA PROJECT, 31/10/2019 by courta_f & habi_a
** c:\Users\Fr4nck\Desktop\group-716039
** File description:
**      
*/

#include <my.h>
#include <stdlib.h>

void                my_revert_tab(char **tab, unsigned n)
{
    char            *tmp;
    unsigned int    i = 0;
    unsigned int    end = n - 1;

    while (i < n / 2) {
        tmp = my_strdup(tab[i]);
        free(tab[i]);
        tab[i] = tab[end];
        tab[end] = tmp;
        end--;
        i++;
    }
}
