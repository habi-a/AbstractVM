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
                        T_STRING,
                        T_VOID,
                        T_NULL
}                       t_var_type;

typedef struct          s_var_node
{
    const char          *var_name;
    t_var_type          var_type;
    int                 value_int;
    float               value_float;
    double              value_double;
    struct s_var_node   *next;
}                       t_var_node;

typedef struct          s_var_list
{
    size_t              size;
    t_var_node          *first;
    t_var_node          *last;

}                       t_var_list;

void				            init_list_variables(int argc, char **argv, t_var_list *list);
t_var_node              *get_variable(t_var_list *list, const char *var_name);
void                    free_list_variables(t_var_list *list);

#endif                  /* _VARIABLES_H_ */
