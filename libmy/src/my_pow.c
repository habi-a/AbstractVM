/*
** ETNA PROJECT, 31/10/2019 by courta_f
** c:\Users\Fr4nck\Desktop\group-716039
** File description:
**
*/

int my_pow(int nb, int pow)
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
