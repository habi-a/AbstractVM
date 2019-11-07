/*
** ETNA PROJECT, 31/10/2019 by courta_f
** c:\Users\Fr4nck\Desktop\group-716039
** File description:
**
*/

#include <my.h>
#include <parser.h>
#include <stdlib.h>
#include <token.h>

static void         get_int(parse_utils_t *parse_utils, char result_buffer[64])
{
    long long int   result_int = my_getnbrll(result_buffer);

    if (result_int >= -128 && result_int <= 127)
        parse_utils->current_token.var_type = T_INT8;
    else if (result_int >= -32768 && result_int <= 32767)
        parse_utils->current_token.var_type = T_INT16;
    else if (result_int >= -2147483648 && result_int <= 2147483647)
        parse_utils->current_token.var_type = T_INT32;
    else
        parse_utils->current_token.var_type = T_UNDEFINED;
    parse_utils->current_token.value_int8 = result_int;
    parse_utils->current_token.value_int16 = result_int;
    parse_utils->current_token.value_int32 = result_int;
    parse_utils->current_token.value_float = result_int;
    parse_utils->current_token.value_double = result_int;
}

static void get_float(parse_utils_t *parse_utils, char result_buffer[64])
{
    float   result_float = (float)atof(result_buffer);

    parse_utils->current_token.value_int8 = (int)result_float;
    parse_utils->current_token.value_int16 = (int)result_float;
    parse_utils->current_token.value_int32 = (int)result_float;
    parse_utils->current_token.value_float = result_float;
    parse_utils->current_token.value_double = (double)result_float;
}

static bool_t       get_number_type(parse_utils_t *parse_utils
                                    ,unsigned int old_index)
{
    if (parse_utils->line[parse_utils->index] == '.') {
        parse_utils->current_token.var_type = T_FLOAT;
        parse_utils->index++;
        while (my_isdigit(parse_utils->line[parse_utils->index]))
            parse_utils->index++;
    }
    else if (parse_utils->line[parse_utils->index] == '+'
            || parse_utils->line[parse_utils->index] == '-') {
        my_printf("Parse Error: Expected number at position %lu\n", old_index);
        return (e_false);
    } else
        parse_utils->current_token.var_type = T_INT32;
    if (parse_utils->index - old_index == 0) {
        my_printf("Parse Error: Expected number at position %lu\n", old_index);
        return (e_false);
    }
    return (e_true);
}

bool_t              get_number(parse_utils_t *parse_utils)
{
    unsigned int    old_index;
    char            result_buffer[64] = {0};

    skip_space(parse_utils);
    old_index = parse_utils->index;
    while (parse_utils->line[parse_utils->index] == '-'
            || parse_utils->line[parse_utils->index] == '+')
        parse_utils->index++;
    while (my_isdigit(parse_utils->line[parse_utils->index]))
        parse_utils->index++;
    if (!get_number_type(parse_utils, old_index))
        return (e_false);
    my_strncpy(result_buffer, parse_utils->line + old_index,
                parse_utils->index - old_index);
    if (parse_utils->current_token.var_type == T_INT32)
        get_int(parse_utils, result_buffer);
    else
        get_float(parse_utils, result_buffer);
    return (e_true);
}

const char  *get_variable_name(parse_utils_t *parse_utils)
{
    char            *result_buf;
    unsigned int    old_index;

    skip_space(parse_utils);
    old_index = parse_utils->index;
    while (my_isalnum(parse_utils->line[parse_utils->index]))
        parse_utils->index++;
    if (parse_utils->index - old_index == 0) {
        my_printf("Parse Error: Expected name at position %lu\n", old_index);
        return (NULL);
    }
    result_buf = malloc((parse_utils->index - old_index + 1) * (sizeof(char)));
    my_strncpy(result_buf, parse_utils->line + old_index,
                parse_utils->index - old_index);
    result_buf[parse_utils->index - old_index] = '\0';
    if (parse_utils->line[parse_utils->index] == '(')
        parse_utils->current_token.token_type = TOK_TYPE;
    else
        parse_utils->current_token.token_type = TOK_INSTRUCTION;
    return (result_buf);
}
