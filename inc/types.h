#ifndef                 _TYPE_H_
# define                _TYPE_H_

# include               <ast.h>
# include               <stdbool.h>
# include               <stddef.h>

# define                NB_TYPES        5

typedef void            (*t_ptr_type)(t_ast_node *ast_node, t_ast_node *ast_node1);

typedef struct          s_type
{
    const char          *type_name;
    t_var_type          return_type;
    t_ptr_type          exec_type;
}                       t_type;

t_type                  *get_type(t_type type_list[NB_TYPES], const char *type_name);
void                    free_list_types(t_type type_list[NB_TYPES]);

void                    my_int8(t_ast_node *ast_node, t_ast_node *ast_node1);
void                    my_int16(t_ast_node *ast_node, t_ast_node *ast_node1);
void                    my_int32(t_ast_node *ast_node, t_ast_node *ast_node1);
void                    my_float(t_ast_node *ast_node, t_ast_node *ast_node1);
void                    my_double(t_ast_node *ast_node, t_ast_node *ast_node1);


#endif                  /* _TYPE_H_ */
