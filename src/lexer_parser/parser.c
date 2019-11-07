/*
** ETNA PROJECT, 31/10/2019 by courta_f
** c:\Users\Fr4nck\Desktop\group-716039
** File description:
**
*/

#include <ast.h>
#include <parser.h>
#include <my.h>
#include <stdlib.h>
#include <stack.h>


ast_node_t          *expression(parse_utils_t *parse_utils
                                ,unsigned short *is_instruction)
{
    stack_data_t    tmp_stack_node = {T_INT8, 0, 0, 0, 0, 0};
    ast_node_t      *expr1_ast_node;
    ast_node_t      *term_ast_node;

    term_ast_node   = term(parse_utils, is_instruction);
    expr1_ast_node  = create_node_number(&tmp_stack_node);
    return (create_node_binary(AST_PLUS, term_ast_node, expr1_ast_node));
}

ast_node_t          *term(parse_utils_t *parse_utils
                          ,unsigned short *is_instruction)
{
    stack_data_t    tmp_stack_node = {T_INT8, 1, 1, 1, 1, 1};
    ast_node_t      *fact_ast_node;
    ast_node_t      *term1_ast_node;

    fact_ast_node   = factor(parse_utils, is_instruction);
    term1_ast_node  = create_node_number(&tmp_stack_node);
    return (create_node_binary(AST_MUL, fact_ast_node, term1_ast_node));
}

ast_node_t          *parse(const char *line)
{
    parse_utils_t   parse_utils;
    unsigned short  is_instruction = 0;

    init_parse_utils(&parse_utils, line);
    parse_utils.current_token.var_name = NULL;
    pop_token(&parse_utils);
    return (expression(&parse_utils, &is_instruction));
}
