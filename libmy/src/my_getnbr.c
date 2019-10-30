/*
** my_getnbr.c for libmy in /Users/habi_a/Documents
**
** Made by HABI Açal
** Login   <habi_a@etna-alternance.net>
**
** Started on  Fri Apr  6 09:59:59 2018 HABI Açal
** Last update Fri Apr  6 10:00:28 2018 HABI Açal
*/
static int          my_getsigne(const char *str, unsigned int *pointeur)
{
    int             pos_neg;
    unsigned int    k;

    k = 0;
    pos_neg = 1;
    while (str[k] == '-' || str[k] == '+') {
        if (str[k] == '+')
            pos_neg *= 1;
        if (str[k] == '-')
            pos_neg *= (-1);
        ++k;
    }
    *pointeur = k;
    return (pos_neg);
}

int                 my_getnbr(const char *str)
{
    int             signe;
    unsigned int    n = 0;
    unsigned int    i = 0;

    signe = my_getsigne(str, &i);
    while (str[i]) {
        if (str[i] >= '0' && str[i] <= '9') {
            n *= 10;
            n += str[i];
            n -= '0';
            ++i;
        }
        else
            return (n * signe);
    }
    return (n * signe);
}
