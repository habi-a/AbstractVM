/*
** ETNA PROJECT, 31/10/2019 by courta_f
** c:\Users\Fr4nck\Desktop\group-716039
** File description:
**      
*/

unsigned int my_isspace(const char c)
{
    switch (c) {
        case ' ':
        case '\t':
        case '\r':
        case '\n':
        case '\v':
        case '\f':
            return (1);
        default:
            break;
    }
    return (0);
}
