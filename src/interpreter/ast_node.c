#include <ast.h>
#include <stdlib.h>
#include <string.h>

t_ast_node*     create_node_binary(t_ast_nodetype type, t_ast_node *left, t_ast_node *right)
{
    t_ast_node* ast_node;

    ast_node = malloc(sizeof(t_ast_node));
    if (ast_node == NULL)
        return (NULL);
    ast_node->node_type = type;
    ast_node->var_name = NULL;
    ast_node->var_type = T_UNDEFINED;
    ast_node->value_int8 = 0;
    ast_node->value_int16 = 0;
    ast_node->value_int32 = 0;
    ast_node->value_float = 0;
    ast_node->value_double = 0;
    ast_node->ast_node_l = left;
    ast_node->ast_node_r = right;
    return (ast_node);
}

t_ast_node*     create_node_unary(t_ast_node* left)
{
    t_ast_node* ast_node;

    ast_node = malloc(sizeof(t_ast_node));
    if (ast_node == NULL)
        return (NULL);
    ast_node->node_type = AST_UNARY_MIN;
    ast_node->var_name = NULL;
    ast_node->var_type = T_UNDEFINED;
    ast_node->value_int8 = 0;
    ast_node->value_int16 = 0;
    ast_node->value_int32 = 0;
    ast_node->value_float = 0;
    ast_node->value_double = 0;
    ast_node->ast_node_l = left;
    ast_node->ast_node_r = NULL;
    return (ast_node);
}

t_ast_node*     create_node_number(t_stack_data *tmp_stack_node)
{
    t_ast_node* ast_node;

    ast_node = malloc(sizeof(t_ast_node));
    if (ast_node == NULL)
        return (NULL);
    ast_node->node_type = AST_NUMBER;
    ast_node->var_name = NULL;
    ast_node->var_type = tmp_stack_node->var_type;
    ast_node->value_int16 = tmp_stack_node->value_int16;
    ast_node->value_int32 = tmp_stack_node->value_int32;
    ast_node->value_float = tmp_stack_node->value_float;
    ast_node->value_double = tmp_stack_node->value_double;
    ast_node->ast_node_l = NULL;
    ast_node->ast_node_r = NULL;
    return (ast_node);
}

t_ast_node      *create_node_call_func(const char *var_name, t_ast_node *ast_node1)
{
    t_ast_node* ast_node;

    ast_node = malloc(sizeof(t_ast_node));
    if (ast_node == NULL)
        return (NULL);
    ast_node->node_type = AST_TYPE;
    ast_node->var_name = strdup(var_name);
    ast_node->var_type = T_VOID;
    ast_node->value_int8 = 0;
    ast_node->value_int16 = 0;
    ast_node->value_int32 = 0;
    ast_node->value_float = 0;
    ast_node->value_double = 0;
    ast_node->ast_node_l = ast_node1;
    ast_node->ast_node_r = NULL;
    return (ast_node);
}

t_ast_node      *create_node_instruction(const char *var_name, t_ast_node *ast_node1)
{
    t_ast_node* ast_node;

    ast_node = malloc(sizeof(t_ast_node));
    if (ast_node == NULL)
        return (NULL);
    ast_node->node_type = AST_INSTRUCTION;
    ast_node->var_name = strdup(var_name);
    ast_node->var_type = T_VOID;
    ast_node->value_int8 = 0;
    ast_node->value_int16 = 0;
    ast_node->value_int32 = 0;
    ast_node->value_float = 0;
    ast_node->value_double = 0;
    ast_node->ast_node_l = ast_node1;
    ast_node->ast_node_r = NULL;
    return (ast_node);
}

t_ast_node      *create_node_null()
{
    t_ast_node* ast_node;

    ast_node = malloc(sizeof(t_ast_node));
    if (ast_node == NULL)
        return (NULL);
    ast_node->node_type = AST_NULL;
    ast_node->var_name = NULL;
    ast_node->var_type = T_NULL;
    ast_node->value_int8 = 0;
    ast_node->value_int16 = 0;
    ast_node->value_int32 = 0;
    ast_node->value_float = 0;
    ast_node->value_double = 0;
    ast_node->ast_node_l = NULL;
    ast_node->ast_node_r = NULL;
    return (ast_node);
}

void    destruct_astnode(t_ast_node *ast_node)
{
    if (ast_node == NULL)
        return ;
    if (ast_node->var_name != NULL)
        free((char *)ast_node->var_name);
    if (ast_node->ast_node_l != NULL)
        destruct_astnode(ast_node->ast_node_l);
    if (ast_node->ast_node_r != NULL)
        destruct_astnode(ast_node->ast_node_r);
    free(ast_node);
}
