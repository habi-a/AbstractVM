/*
** my_revert_tab.c for libmy in /Users/habi_a/Documents
**
** Made by HABI Açal
** Login   <habi_a@etna-alternance.net>
**
** Started on  Fri Apr  6 10:02:16 2018 HABI Açal
** Last update Thu Jul 12 17:46:56 2018 HABI Açal
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
