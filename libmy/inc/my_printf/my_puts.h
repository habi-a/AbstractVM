/*
** my_puts.h for my_printf in /Users/habi_a/Documents
**
** Made by HABI Açal
** Login   <habi_a@etna-alternance.net>
**
** Started on  Thu Jul 19 09:48:54 2018 HABI Açal
** Last update Mon Jul 23 16:40:22 2018 HABI Açal
*/

#ifndef     _MY_PUTS_H_
# define    _MY_PUTS_H_

# include   <stdarg.h>

typedef unsigned int (*ptr_my_put_t)(va_list, unsigned int);

unsigned int    my_put_percent(va_list variables, unsigned int count);
unsigned int    my_put_c(va_list variables, unsigned int count);
unsigned int    my_put_i(va_list variables, unsigned int count);
unsigned int    my_put_d(va_list variables, unsigned int count);
unsigned int    my_put_s(va_list variables, unsigned int count);
unsigned int    my_put_o(va_list variables, unsigned int count);
unsigned int    my_put_u(va_list variables, unsigned int count);
unsigned int    my_put_x(va_list variables, unsigned int count);
unsigned int    my_put_X(va_list variables, unsigned int count);
unsigned int    my_put_p(va_list variables, unsigned int count);
unsigned int    my_put_b(va_list variables, unsigned int count);
unsigned int    my_put_S(va_list variables, unsigned int count);
unsigned int    my_put_l(va_list variables, unsigned int count);

#endif   /* _MY_PUTS_H_ */
