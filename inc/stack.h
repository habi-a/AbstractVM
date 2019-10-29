#ifndef                 _VARIABLES_H_
# define                _VARIABLES_H_

# include               <stddef.h>
# include               <stdio.h>
# include               <stdint.h>

typedef enum            e_var_type
{
                        T_UNDEFINED,
                        T_INT8,
                        T_INT16,
                        T_INT32,
                        T_FLOAT,
                        T_DOUBLE,
                        T_VOID,
                        T_NULL
}                       t_var_type;

typedef struct          s_stack_data
{
    int8_t              value_int8;
    int16_t             value_int16;
    int32_t             value_int32;
    float               value_float;
    double              value_double;
    t_var_type          var_type;
}                       t_stack_data;

typedef struct          s_stack_node
{
    struct s_stack_data data;
    struct s_stack_node *next;
}                       t_stack_node;

unsigned short          isEmpty(t_stack_node *stack);
t_stack_node            *push(t_stack_node *stack, t_stack_data data);
t_stack_node            *pop(t_stack_node *stack, t_stack_data *data);
t_stack_data            peek(t_stack_node *stack);
void                    free_stack(t_stack_node *stack);


#endif                  /* _VARIABLES_H_ */
