/*
** my_getnbrll.c for libmy in /Users/habi_a/Documents
**
** Made by HABI Açal
** Login   <habi_a@etna-alternance.net>
**
** Started on  Fri Apr  6 09:59:59 2018 HABI Açal
** Last update Fri Apr  6 10:00:28 2018 HABI Açal
*/
static long long my_getsigne(const char *str, unsigned long long *pointeur)
{
    long long           pos_neg;
    unsigned long long  k;

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

long long                 my_getnbrll(const char *str)
{
    long long             signe;
    unsigned long long    n = 0;
    unsigned long long    i = 0;

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
