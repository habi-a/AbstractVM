/*
** my_pow.c for libmy in /Users/habi_a/Documents
**
** Made by HABI Açal
** Login   <habi_a@etna-alternance.net>
**
** Started on  Fri Apr  6 10:03:24 2018 HABI Açal
** Last update Fri Apr  6 10:03:29 2018 HABI Açal
*/
int     my_pow(int nb, int pow)
{
    int p = 1;
    int result = 1;

    if (pow < 0)
        return (0);
    while (p <= pow) {
        result *= nb;
        p++;
    }
    return (result);
}
