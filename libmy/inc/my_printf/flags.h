/*
** flags.h for my_printf in /Users/habi_a/Documents
**
** Made by HABI Açal
** Login   <habi_a@etna-alternance.net>
**
** Started on  Thu Jul 19 09:42:18 2018 HABI Açal
** Last update Thu Jul 19 09:42:47 2018 HABI Açal
*/

#ifndef         _FLAGS_H_
# define        _FLAGS_H_

# define        NB_FLAGS 13
# include       <my_puts.h>

typedef struct      s_flags {
    char            key;
    ptr_my_put_t    p_my_put;
}                   flags_t;

#endif   /* _FLAGS_H_ */
