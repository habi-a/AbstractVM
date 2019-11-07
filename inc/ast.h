/*
** ETNA PROJECT, 31/10/2019 by courta_f
** c:\Users\Fr4nck\Desktop\group-716039
** File description:
**
*/

#ifndef _AST_H_
#define _AST_H_

#include <stack.h>

typedef enum e_ast_nodetype {
    AST_NUMBER,
    AST_PLUS,
    AST_MUL,
    AST_TYPE,
    AST_INSTRUCTION,
    AST_UNARY_MIN,
    AST_NULL
} ast_nodetype_t;

typedef struct s_ast_node {
    ast_nodetype_t node_type;
    const char *var_name;
    var_type_t var_type;
    int8_t value_int8;
    int16_t value_int16;
    int32_t value_int32;
    float value_float;
    double value_double;
    struct s_ast_node *ast_node_l;
    struct s_ast_node *ast_node_r;
} ast_node_t;

ast_node_t *create_node_binary(ast_nodetype_t type, ast_node_t *left
                                , ast_node_t *right);
ast_node_t *create_node_unary(ast_node_t* left);
ast_node_t *create_node_number(stack_data_t *tmp_stack_node);
ast_node_t *create_node_instruction(const char *var_name
                                    , ast_node_t *ast_node1);
ast_node_t *create_node_call_func(const char *var_name
                                    , ast_node_t *ast_node1);
ast_node_t *create_node_null(void);
void destruct_astnode(ast_node_t *ast_node);

#endif /* _AST_H_ */
