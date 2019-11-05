/*
** ETNA PROJECT, 31/10/2019 by courta_f
** c:\Users\Fr4nck\Desktop\group-716039
** File description:
**
*/

#ifndef                 _TYPE_H_
# define                _TYPE_H_

# include               <ast.h>

# define                NB_TYPES        5

typedef void            (*t_ptr_type)(ast_node_t *ast_node,
                                        ast_node_t *ast_node1);

typedef struct          s_type {
    const char          *type_name;
    var_type_t          return_type;
    t_ptr_type          exec_type;
}                       type_t;

type_t                  *get_type(type_t type_list[NB_TYPES],
                                    const char *type_name);
void                    free_list_types(type_t type_list[NB_TYPES]);

void                    my_int8(ast_node_t *ast_node, ast_node_t *ast_node1);
void                    my_int16(ast_node_t *ast_node, ast_node_t *ast_node1);
void                    my_int32(ast_node_t *ast_node, ast_node_t *ast_node1);
void                    my_float(ast_node_t *ast_node, ast_node_t *ast_node1);
void                    my_double(ast_node_t *ast_node, ast_node_t *ast_node1);


#endif                  /* _TYPE_H_ */
