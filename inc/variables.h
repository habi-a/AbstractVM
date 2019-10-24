#ifndef                 _VARIABLES_H_
# define                _VARIABLES_H_

# include               <stddef.h>
# include               <stdio.h>

typedef enum            e_var_type
{
                        T_UNDEFINED,
                        T_INT,
                        T_FLOAT,
                        T_DOUBLE,
                        T_VOID,
                        T_NULL
}                       t_var_type;

typedef struct          s_stack_data
{
    t_var_type          var_type;
    int                 value_int;
    float               value_float;
    double              value_double;
}                       t_stack_data;

typedef struct          s_stack_node
{
    struct s_stack_data data;
    struct s_var_node   *next;
}                       t_stack_node;

unsigned short          isEmpty(t_stack_node *stack)
void                    push(t_stack_node **stack, t_stack_data data)
t_stack_data            pop(t_stack_node **stack)
t_stack_data            peek(t_stack_node *stack)
void                    free_stack(t_stack_node *stack)


#endif                  /* _VARIABLES_H_ */
