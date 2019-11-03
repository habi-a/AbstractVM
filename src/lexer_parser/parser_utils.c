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

void        init_parse_utils(parse_utils_t *parse_utils, const char *line)
{
    parse_utils->index = 0;
    parse_utils->line = line;
    parse_utils->nb_token = 0;
    parse_utils->decla_type = T_UNDEFINED;
}

bool        is_white_line(const char *line)
{
    size_t  i;

    i = 0;
    while (line[i] != '\0') {
        if (line[i] == ';')
            break;
        else if (!my_isspace(line[i]))
            return (false);
        i++;
    }
    return (true);
}

void        skip_space(parse_utils_t *parse_utils)
{
    while (my_isspace(parse_utils->line[parse_utils->index]))
        parse_utils->index++;
}

void                get_number(parse_utils_t *parse_utils)
{
    size_t          old_index;
    float           result_float;
    char            result_buffer[64] = {0};
    long long int   result_int;

    skip_space(parse_utils);
    old_index = parse_utils->index;
    while (parse_utils->line[parse_utils->index] == '-'
            || parse_utils->line[parse_utils->index] == '+')
        parse_utils->index++;
    while (my_isdigit(parse_utils->line[parse_utils->index]))
        parse_utils->index++;
    if (parse_utils->line[parse_utils->index] == '.') {
        parse_utils->current_token.var_type = T_FLOAT;
        parse_utils->index++;
        while (my_isdigit(parse_utils->line[parse_utils->index]))
            parse_utils->index++;
    }
    else if (parse_utils->line[parse_utils->index] == '+'
            || parse_utils->line[parse_utils->index] == '-') {
        my_printf("Parse Error: Expected number at position %lu\n", old_index);
        exit(0);
    } else
        parse_utils->current_token.var_type = T_INT32;
    if (parse_utils->index - old_index == 0) {
        my_printf("Parse Error: Expected number at position %lu\n", old_index);
        exit(0);
    }
    my_strncpy(result_buffer, parse_utils->line + old_index, parse_utils->index - old_index);
    if (parse_utils->current_token.var_type == T_INT32) {
        result_int = my_getnbrll(result_buffer);
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
    } else {
        result_float = (float)my_getnbr_double(result_buffer);
        parse_utils->current_token.value_int8 = (int)result_float;
        parse_utils->current_token.value_int16 = (int)result_float;
        parse_utils->current_token.value_int32 = (int)result_float;
        parse_utils->current_token.value_float = result_float;
        parse_utils->current_token.value_double = (double)result_float;
    }
}

void            pop_line(parse_utils_t *parse_utils)
{
    while (parse_utils->line[parse_utils->index] != '\0')
        parse_utils->index++;
    pop_token(parse_utils);
}

const char  *get_variable_name(parse_utils_t *parse_utils)
{
    char    *result_buffer;
    size_t  old_index;

    skip_space(parse_utils);
    old_index = parse_utils->index;
    while (my_isalnum(parse_utils->line[parse_utils->index]))
        parse_utils->index++;
    if (parse_utils->index - old_index == 0) {
        my_printf("Parse Error: Expected variable name at position %lu\n", old_index);
        exit(0);
    }
    result_buffer = malloc((parse_utils->index - old_index + 1) * (sizeof(char)));
    my_strncpy(result_buffer, parse_utils->line + old_index, parse_utils->index - old_index);
    result_buffer[parse_utils->index - old_index] = '\0';
    if (parse_utils->line[parse_utils->index] == '(')
        parse_utils->current_token.token_type = TOK_TYPE;
    else
        parse_utils->current_token.token_type = TOK_INSTRUCTION;
    return (result_buffer);
}

void        expect(char expected, parse_utils_t *parse_utils)
{
    if (parse_utils->line[parse_utils->index - 1] == expected)
        pop_token(parse_utils);
    else {
       my_printf("Parse Error: Expected token '%c' at position %lu\n",
           expected, parse_utils->index);
       exit(0);
    }
}
