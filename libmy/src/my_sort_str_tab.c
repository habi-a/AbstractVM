/*
** my_sort_str_tab.c for libmy in /Users/habi_a/Documents
**
** Made by HABI Açal
** Login   <habi_a@etna-alternance.net>
**
** Started on  Fri Apr  6 10:02:16 2018 HABI Açal
** Last update Thu Jul 12 17:47:42 2018 HABI Açal
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
