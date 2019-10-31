/*
** ETNA PROJECT, 31/10/2019 by courta_f & habi_a
** c:\Users\Fr4nck\Desktop\group-716039
** File description:
**      
*/

#include <my.h>
#include <stdlib.h>

void                my_sort_str_tab(char **tab, unsigned int size)
{
    char            *temp;
    unsigned int    i;
    unsigned int    j;

    i = 0;
    while (i < size - 1) {
        j = 0;
        while (j < size - i - 1) {
            if (my_strcmp(tab[j], tab[j + 1]) > 0) {
                temp = my_strdup(tab[j]);
                free(tab[j]);
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
            j++;
        }
        i++;
    }
}

void                my_sort_rev_str_tab(char **tab, unsigned int size)
{
    char            *temp;
    unsigned int    i;
    unsigned int    j;

    i = 0;
    while (i < size - 1) {
        j = 0;
        while (j < size - i - 1) {
            if (my_strcmp(tab[j], tab[j + 1]) < 0) {
                temp = my_strdup(tab[j]);
                free(tab[j]);
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
            j++;
        }
        i++;
    }
}
