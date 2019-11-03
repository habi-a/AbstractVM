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


ast_node_t          *expression(parse_utils_t *parse_utils, unsigned short *is_instruction)
{
    stack_data_t    tmp_stack_node = {T_INT8, 0, 0, 0, 0, 0};
    ast_node_t      *expr1_ast_node;
    ast_node_t      *term_ast_node;

    term_ast_node   = term(parse_utils, is_instruction);
    expr1_ast_node  = create_node_number(&tmp_stack_node);
    return (create_node_binary(AST_PLUS, term_ast_node, expr1_ast_node));
}

ast_node_t          *term(parse_utils_t *parse_utils, unsigned short *is_instruction)
{
    stack_data_t    tmp_stack_node = {T_INT8, 1, 1, 1, 1, 1};
    ast_node_t      *fact_ast_node;
    ast_node_t      *term1_ast_node;

    fact_ast_node   = factor(parse_utils, is_instruction);
    term1_ast_node  = create_node_number(&tmp_stack_node);
    return (create_node_binary(AST_MUL, fact_ast_node, term1_ast_node));
}

ast_node_t          *factor(parse_utils_t *parse_utils, unsigned short *is_instruction)
{
    stack_data_t    tmp_stack_node;
    const char      *tmp_var_name;
    ast_node_t      *ast_node;
    ast_node_t      *ast_node1;

    switch (parse_utils->current_token.token_type) {
        case TOK_NUMBER:
            if (!*is_instruction) {
                my_printf("Parse Error: Unexpected number at position %lu\n",
                    parse_utils->index);
                exit(0);
            }
            tmp_stack_node.var_type = parse_utils->current_token.var_type;
            tmp_stack_node.value_int8 = parse_utils->current_token.value_int8;
            tmp_stack_node.value_int16 = parse_utils->current_token.value_int16;
            tmp_stack_node.value_int32 = parse_utils->current_token.value_int32;
            tmp_stack_node.value_float = parse_utils->current_token.value_float;
            tmp_stack_node.value_double = parse_utils->current_token.value_double;
            pop_token(parse_utils);
            return (create_node_number(&tmp_stack_node));
        case TOK_INSTRUCTION:
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
        case TOK_TYPE:
            tmp_var_name = my_strdup(parse_utils->current_token.var_name);
            pop_token(parse_utils);
            pop_token(parse_utils);
            if (parse_utils->current_token.token_type != TOK_NUMBER) {
                my_printf("Parse error, expected TOK_NUMBER at position %ld\n", parse_utils->index);
                exit(0);
            }
            ast_node1 = expression(parse_utils, is_instruction);
            expect(')', parse_utils);
            if (parse_utils->current_token.token_type != TOK_END_TEXT || !*is_instruction) {
                my_printf("Parse Error: Unexpected token '%c' at position %lu\n",
                    parse_utils->current_token.value_symbol, parse_utils->index);
                exit(0);
            }
            ast_node = create_node_call_func(tmp_var_name, ast_node1);
            free((char *)tmp_var_name);
            return (ast_node);
        default: {
            my_printf("Parse Error: Unexpected token '%c' at position %lu\n",
                parse_utils->current_token.value_symbol, parse_utils->index);
            exit(0);
        }
    }
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
