/*
** ETNA PROJECT, 31/10/2019 by courta_f & habi_a
** c:\Users\Fr4nck\Desktop\group-716039
** File description:
**      
*/

unsigned int my_isalnum(const char c)
{
    if (c >= 48 && c <= 57)
        return (1);
    else if (c >= 65 && c <= 90)
        return (1);
    else if (c >= 97 && c <= 122)
        return (1);
    return (0);
}
