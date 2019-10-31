/*
** ETNA PROJECT, 31/10/2019 by courta_f & habi_a
** c:\Users\Fr4nck\Desktop\group-716039
** File description:
**      
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
