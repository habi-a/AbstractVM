/*
** my_isspace.c for libmy in /Users/habi_a/Documents
**
** Made by HABI Açal
** Login   <habi_a@etna-alternance.net>
**
** Started on  Fri Apr  6 10:01:31 2018 HABI Açal
** Last update Fri Apr  6 10:01:33 2018 HABI Açal
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
            return (0);
        return (0);
    }
}
