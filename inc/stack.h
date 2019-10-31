/*
** ETNA PROJECT, 31/10/2019 by courta_f
** c:\Users\Fr4nck\Desktop\group-716039
** File description:
**      
*/

#ifndef                 _VARIABLES_H_
# define                _VARIABLES_H_

# include               <stddef.h>
# include               <stdio.h>
# include               <stdint.h>

typedef enum            e_var_type {
                        T_UNDEFINED,
                        T_VOID,
                        T_NULL,
                        T_INT8,
                        T_INT16,
                        T_INT32,
                        T_FLOAT,
                        T_DOUBLE,
}                       var_type_t;

typedef struct          s_stack_data {
    var_type_t          var_type;
    int8_t              value_int8;
    int16_t             value_int16;
    int32_t             value_int32;
    float               value_float;
    double              value_double;
}                       stack_data_t;

typedef struct          s_stack_node {
    struct s_stack_data data;
    struct s_stack_node *next;
}                       stack_node_t;

unsigned short          isEmpty(stack_node_t *stack);
stack_node_t            *push(stack_node_t *stack, stack_data_t data);
stack_node_t            *pop(stack_node_t *stack, stack_data_t *data);
stack_data_t            peek(stack_node_t *stack);
void                    free_stack(stack_node_t *stack);


#endif                  /* _VARIABLES_H_ */
