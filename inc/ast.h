#ifndef                 _AST_H_
# define                _AST_H_

# include               <variables.h>
# include               <stdbool.h>
# include               <stdio.h>

typedef enum            e_ast_nodetype
{
                        AST_NUMBER,
                        AST_PLUS,
                        AST_MINUS,
                        AST_MUL,
                        AST_DIV,
                        AST_MOD,
                        AST_CALL_FUNC,
                        AST_INSTRUCTION,
                        AST_UNARY_MIN,
                        AST_NULL
}                       t_ast_nodetype;

typedef struct          s_ast_node
{
    t_ast_nodetype      node_type;
    const char          *var_name;
    t_var_type          var_type;
    int                 value_int;
    float               value_float;
    double              value_double;
    struct s_ast_node   *ast_node_l;
    struct s_ast_node   *ast_node_r;
}                       t_ast_node;

t_ast_node*             create_node_binary(t_ast_nodetype type, t_ast_node *left, t_ast_node *right);
t_ast_node*             create_node_unary(t_ast_node* left);
t_ast_node*             create_node_number(t_var_type var_type, int value_int, float value_float);
t_ast_node              *create_node_instruction(const char *var_name, t_ast_node *ast_node1);
t_ast_node              *create_node_call_func(const char *var_name, t_ast_node *ast_node1);
t_ast_node              *create_node_null();
void                    destruct_astnode(t_ast_node *ast_node);

#endif                  /* _AST_H_ */
