/*
** ETNA PROJECT, 31/10/2019 by courta_f
** c:\Users\Fr4nck\Desktop\group-716039
** File description:
**
*/

#include <parser.h>
#include <stdlib.h>
#include <token.h>

void init_token(token_t *token)
{
    if (token->var_name != NULL)
        free((char *)token->var_name);
    token->var_name = NULL;
    token->var_type = T_UNDEFINED;
    token->value_int8 = 0;
    token->value_int16 = 0;
    token->value_int32 = 0;
    token->value_float = 0;
    token->value_symbol = '\0';
}

static bool_t set_token_extra(parse_utils_t *parse_utils)
{
    switch (parse_utils->line[parse_utils->index]) {
        case '(': parse_utils->current_token.token_type = TOK_LEFT_PAREN;
            break;
        case ')': parse_utils->current_token.token_type = TOK_RIGHT_PAREN;
            break;
        default: parse_utils->current_token.token_type = TOK_ERROR;
            break;
    }
    return (e_false);
}

bool_t set_token(parse_utils_t *parse_utils)
{
    if (!parse_utils->line[parse_utils->index]) {
        parse_utils->current_token.token_type = TOK_END_TEXT;
        return (e_true);
    } else if (my_isdigit(parse_utils->line[parse_utils->index])
                || parse_utils->line[parse_utils->index] == '+'
                || parse_utils->line[parse_utils->index] == '-') {
        parse_utils->current_token.token_type = TOK_NUMBER;
        return (get_number(parse_utils));
    } else if (my_isalpha(parse_utils->line[parse_utils->index])) {
        parse_utils->current_token.token_type = TOK_ERROR;
        parse_utils->current_token.var_name = get_variable_name(parse_utils);
        return ((parse_utils->current_token.var_name == NULL) ? 0 : 1);
    } else if (parse_utils->line[parse_utils->index] == ';') {
        pop_line(parse_utils);
        return (e_true);
    }
    return (set_token_extra(parse_utils));
}

void pop_token(parse_utils_t *parse_utils)
{
    skip_space(parse_utils);
    init_token(&parse_utils->current_token);
    parse_utils->nb_token++;
    if (set_token(parse_utils))
        return ;
    if (parse_utils->current_token.token_type != TOK_ERROR) {
        parse_utils->current_token.value_symbol =
            parse_utils->line[parse_utils->index];
        parse_utils->index++;
    } else {
        my_printf("Parse Error: Unexpected token '%c' at position %lu\n",
            parse_utils->line[parse_utils->index], parse_utils->index);
        return ;
    }
}
