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

static ast_node_t   *factor_number(parse_utils_t *parse_utils,
                                    unsigned short *is_instruction)
{
    stack_data_t    tmp_stack_node;

    if (!*is_instruction) {
        my_printf("Parse Error: Unexpected number at position %lu\n",
            parse_utils->index);
        return (NULL);
    }
    tmp_stack_node.var_type = parse_utils->current_token.var_type;
    tmp_stack_node.value_int8 = parse_utils->current_token.value_int8;
    tmp_stack_node.value_int16 = parse_utils->current_token.value_int16;
    tmp_stack_node.value_int32 = parse_utils->current_token.value_int32;
    tmp_stack_node.value_float = parse_utils->current_token.value_float;
    tmp_stack_node.value_double = parse_utils->current_token.value_double;
    pop_token(parse_utils);
    return (create_node_number(&tmp_stack_node));
}

static ast_node_t   *factor_instruction(parse_utils_t *parse_utils,
                                        unsigned short *is_instruction,
                                        ast_node_t *ast_node,
                                        ast_node_t *ast_node1)
{
    const char      *tmp_var_name;

    *is_instruction = 1;
    tmp_var_name = my_strdup(parse_utils->current_token.var_name);
    pop_token(parse_utils);
    if (parse_utils->current_token.token_type == TOK_END_TEXT)
        ast_node1 = create_node_null();
    else
        ast_node1 = factor(parse_utils, is_instruction);
    ast_node = create_node_instruction(tmp_var_name, ast_node1);
    free((char *)tmp_var_name);
    return (ast_node);
}

static ast_node_t *factor_type(parse_utils_t *parse_utils,
                                unsigned short *is_instrct,
                                ast_node_t *ast_node, ast_node_t *ast_node1)
{
    const char *tmp_var_name = my_strdup(parse_utils->current_token.var_name);

    pop_token(parse_utils);
    pop_token(parse_utils);
    if (parse_utils->current_token.token_type != TOK_NUMBER) {
        my_printf("Parse error, expected TOK_NUMBER\n");
        free((char *)tmp_var_name);
        return (NULL);
    }
    ast_node1 = expression(parse_utils, is_instrct);
    expect(')', parse_utils);
    if (parse_utils->current_token.token_type != TOK_END_TEXT || !*is_instrct) {
        my_printf("Parse Error: Unexpected token '%c'\n");
        free((char *)tmp_var_name);
        destruct_astnode(ast_node1);
        return (NULL);
    }
    ast_node = create_node_call_func(tmp_var_name, ast_node1);
    free((char *)tmp_var_name);
    return (ast_node);
}

ast_node_t          *factor(parse_utils_t *parse_utils,
                            unsigned short *is_instruction)
{
    ast_node_t      *ast_node = NULL;
    ast_node_t      *ast_node1 = NULL;

    switch (parse_utils->current_token.token_type) {
        case TOK_NUMBER:
            return(factor_number(parse_utils, is_instruction));
        case TOK_INSTRUCTION:
            return(factor_instruction(parse_utils, is_instruction,
                                        ast_node, ast_node1));
        case TOK_TYPE:
            return(factor_type(parse_utils, is_instruction,
                                ast_node, ast_node1));
        default:
            my_printf("Parse Error: Unexpected token '%c' at position %lu\n",
                parse_utils->current_token.value_symbol, parse_utils->index);
            return (NULL);
    }
}
