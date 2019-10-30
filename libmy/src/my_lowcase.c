/*
** my_lowcase.c for libmy in /Users/habi_a/Documents
**
** Made by HABI Açal
** Login   <habi_a@etna-alternance.net>
**
** Started on  Fri Apr  6 09:59:59 2018 HABI Açal
** Last update Thu Jul 12 17:46:16 2018 HABI Açal
*/
char my_lowcase(char c)
{
    if (c >= 'A' && c <= 'Z')
        c += 32;
    return (c);
}
