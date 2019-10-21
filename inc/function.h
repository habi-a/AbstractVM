#ifndef                 _FUNCTION_H_
# define                _FUNCTION_H_

# include               <ast.h>
# include               <stdbool.h>
# include               <stddef.h>
# include               <variables.h>

typedef void            (*t_ptr_function)(t_ast_node *ast_node, t_ast_node *ast_node1);

typedef struct          s_func_node
{
    const char          *func_name;
    t_var_type          return_type;
    t_ptr_function      exec_function;
    struct s_func_node  *next;
}                       t_func_node;

typedef struct          s_func_list
{
    size_t              size;
    t_func_node         *first;
    t_func_node         *last;

}                       t_func_list;

void				    init_list_functions(t_func_list *list);
t_func_node             *get_function(t_func_list *list, const char *func_name);
void                    push_back_function(t_func_list *list, const char *func_name, t_ptr_function function_b_in);
void                    fill_functions(t_func_list *list);
void                    free_list_functions(t_func_list *list);

void                    my_int8(t_ast_node *ast_node, t_ast_node *ast_node1);
void                    my_int16(t_ast_node *ast_node, t_ast_node *ast_node1);
void                    my_int32(t_ast_node *ast_node, t_ast_node *ast_node1);
void                    my_float(t_ast_node *ast_node, t_ast_node *ast_node1);
void                    my_double(t_ast_node *ast_node, t_ast_node *ast_node1);


#endif                  /* _FUNCTION_H_ */
