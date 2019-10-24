#include <ctype.h>
#include <parser.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <token.h>

void        init_parse_utils(t_parse_utils *parse_utils, const char *line)
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
    while (line[i] != '\0')
    {
        if (line[i] == ';')
            break;
        else if (!isspace(line[i]))
            return (false);
        i++;
    }
    return (true);
}

void        skip_space(t_parse_utils *parse_utils)
{
    while (isspace(parse_utils->line[parse_utils->index]))
        parse_utils->index++;
}

void        get_number(t_parse_utils *parse_utils)
{
    int     result_int;
    float   result_float;
    char    result_buffer[32] = {0};
    size_t  old_index;

    skip_space(parse_utils);
    old_index = parse_utils->index;
    while (isdigit(parse_utils->line[parse_utils->index]))
        parse_utils->index++;
    if (parse_utils->line[parse_utils->index] == '.')
    {
        parse_utils->current_token.var_type = T_FLOAT;
        parse_utils->index++;
        while (isdigit(parse_utils->line[parse_utils->index]))
            parse_utils->index++;
    }
    else
        parse_utils->current_token.var_type = T_INT;
    if (parse_utils->index - old_index == 0)
    {
        fprintf(stderr, "Parse Error: Expected number at position %lu\n", old_index);
        exit(0);
    }
    strncpy(result_buffer, parse_utils->line + old_index, parse_utils->index - old_index);
    if (parse_utils->current_token.var_type == T_INT)
    {
        result_int = atoi(result_buffer);
        parse_utils->current_token.value_int = result_int;
        parse_utils->current_token.value_float = result_int;
    }
    else
    {
        result_float = (float)atof(result_buffer);
        parse_utils->current_token.value_float = result_float;
        parse_utils->current_token.value_int = (int)result_float;
    }
}

void            pop_line(t_parse_utils *parse_utils)
{
    while (parse_utils->line[parse_utils->index] != '\0')
        parse_utils->index++;
    pop_token(parse_utils);
}

const char  *get_variable_name(t_parse_utils *parse_utils)
{
    char    *result_buffer;
    size_t  old_index;

    skip_space(parse_utils);
    old_index = parse_utils->index;
    while (isalnum(parse_utils->line[parse_utils->index]))
        parse_utils->index++;
    if (parse_utils->index - old_index == 0)
    {
        fprintf(stderr, "Parse Error: Expected variable name at position %lu\n", old_index);
        exit(0);
    }
    result_buffer = malloc((parse_utils->index - old_index + 1) * (sizeof(char)));
    strncpy(result_buffer, parse_utils->line + old_index, parse_utils->index - old_index);
    result_buffer[parse_utils->index - old_index] = '\0';
    if (parse_utils->line[parse_utils->index] == '(')
        parse_utils->current_token.token_type = TOK_TYPE;
    else
        parse_utils->current_token.token_type = TOK_INSTRUCTION;
    return (result_buffer);
}

void        expect(char expected, t_parse_utils *parse_utils)
{
    if (parse_utils->line[parse_utils->index - 1] == expected)
        pop_token(parse_utils);
    else
    {
       fprintf(stderr, "Parse Error: Expected token '%c' at position %lu\n",
           expected, parse_utils->index);
       exit(0);
    }
}
