/*
** ETNA PROJECT, 31/10/2019 by courta_f
** c:\Users\Fr4nck\Desktop\group-716039
** File description:
**
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
