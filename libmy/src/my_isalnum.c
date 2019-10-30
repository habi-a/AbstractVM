/*
** my_isalnum.c for libmy in /Users/habi_a/Documents
**
** Made by HABI Açal
** Login   <habi_a@etna-alternance.net>
**
** Started on  Fri Apr  6 10:01:31 2018 HABI Açal
** Last update Fri Apr  6 10:01:33 2018 HABI Açal
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
