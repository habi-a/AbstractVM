/*
** ETNA PROJECT, 31/10/2019 by courta_f
** c:\Users\Fr4nck\Desktop\group-716039
** File description:
**
*/

static long long my_getsigne(const char *str, unsigned long long *pointeur)
{
    long long pos_neg;
    unsigned long long k;

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

long long my_getnbrll(const char *str)
{
    long long signe;
    unsigned long long n = 0;
    unsigned long long i = 0;

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
