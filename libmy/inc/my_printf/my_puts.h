/*
** ETNA PROJECT, 31/10/2019 by courta_f & habi_a
** c:\Users\Fr4nck\Desktop\group-716039
** File description:
**      
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
