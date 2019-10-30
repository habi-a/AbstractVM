/*
** my_nbrlen.c for libmy in /Users/habi_a/Documents
**
** Made by HABI Açal
** Login   <habi_a@etna-alternance.net>
**
** Started on  Tue Dec 26 13:18:38 2017 HABI Açal
** Last update Sat Jan  6 22:34:59 2018 HABI Açal
*/
unsigned int        my_long_nbrlen(long n)
{
    unsigned int    i;

    i = 1;
    while (n > 9) {
        n /= 10;
        i++;
    }
    return (i);
}

unsigned int        my_un_nbrlen(unsigned int n)
{
    unsigned int    i;

    i = 1;
    while (n > 9) {
        n /= 10;
        i++;
    }
    return (i);
}

unsigned int        my_nbrlen(int n)
{
    unsigned int    i;

    i = 1;
    while (n > 9) {
        n /= 10;
        i++;
    }
    return (i);
}
