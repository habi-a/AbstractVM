#include <ast.h>
#include <parser.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stack.h>


t_ast_node          *expression(t_parse_utils *parse_utils)
{
    t_ast_node      *expr1_ast_node;
    t_ast_node      *term_ast_node;

    term_ast_node   = term(parse_utils);
    expr1_ast_node  = create_node_number(T_INT, 0, 0);
    return (create_node_binary(AST_PLUS, term_ast_node, expr1_ast_node));
}

t_ast_node          *term(t_parse_utils *parse_utils)
{
    t_ast_node      *fact_ast_node;
    t_ast_node      *term1_ast_node;

    fact_ast_node   = factor(parse_utils);
    term1_ast_node  = create_node_number(T_INT, 1, 1);
    return (create_node_binary(AST_MUL, fact_ast_node, term1_ast_node));
}

t_ast_node          *factor(t_parse_utils *parse_utils)
{
    int             tmp_value_int;
    float           tmp_value_float;
    t_var_type      tmp_var_type;
    const char      *tmp_var_name;
    t_ast_node      *ast_node;
    t_ast_node      *ast_node1;

    switch (parse_utils->current_token.token_type)
    {
        case TOK_LEFT_PAREN:
            pop_token(parse_utils);
            ast_node = expression(parse_utils);
            expect(')', parse_utils);
            return (ast_node);
        case TOK_NUMBER:
            tmp_var_type = parse_utils->current_token.var_type;
            tmp_value_int = parse_utils->current_token.value_int;
            tmp_value_float = parse_utils->current_token.value_float;
            pop_token(parse_utils);
            return (create_node_number(tmp_var_type, tmp_value_int, tmp_value_float));
        case TOK_INSTRUCTION:
            tmp_var_name = strdup(parse_utils->current_token.var_name);
            pop_token(parse_utils);
            if (parse_utils->current_token.token_type == TOK_END_TEXT)
                ast_node1 = create_node_null();
            else
                ast_node1 = factor(parse_utils);
            ast_node = create_node_instruction(tmp_var_name, ast_node1);
            free((char *)tmp_var_name);
            return (ast_node);
        case TOK_TYPE:
            tmp_var_name = strdup(parse_utils->current_token.var_name);
            pop_token(parse_utils);
            pop_token(parse_utils);
            if (parse_utils->current_token.token_type != TOK_NUMBER)
            {
                fprintf(stderr, "Parse error, expected TOK_NUMBER at position %ld\n", parse_utils->index);
                exit(0);
            }
            ast_node1 = expression(parse_utils);
            expect(')', parse_utils);
            ast_node = create_node_call_func(tmp_var_name, ast_node1);
            free((char *)tmp_var_name);
            return (ast_node);
        default:
        {
            fprintf(stderr, "Parse Error: Unexpected token '%c' at position %lu\n",
                parse_utils->current_token.value_symbol, parse_utils->index);
            exit(0);
        }
    }
}

t_ast_node            *parse(const char *line)
{
    t_parse_utils   parse_utils;

    init_parse_utils(&parse_utils, line);
    parse_utils.current_token.var_name = NULL;
    pop_token(&parse_utils);
    return (expression(&parse_utils));
}
