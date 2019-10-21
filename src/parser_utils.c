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

bool        is_white_line(const char *line, bool *is_comment)
{
    size_t  i;
    bool    is_comment_tmp;

    i = 0;
    is_comment_tmp = *is_comment;
    while (line[i] != '\0')
    {
        if (line[i] == '/' && line[i + 1] == '*' && !is_comment_tmp)
        {
            is_comment_tmp = true;
            i++;
        }
        else if (line[i] == '*' && line[i + 1] == '/' && is_comment_tmp)
        {
            is_comment_tmp = false;
            i++;
        }
        else if (line[i] == '/' && line[i + 1] == '/' && !is_comment_tmp)
            break;
        else if (!isspace(line[i]) && !is_comment_tmp)
            return (false);
        i++;
    }
    *is_comment = is_comment_tmp;
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

void            pop_line(t_parse_utils *parse_utils, bool *is_comment)
{
    while (parse_utils->line[parse_utils->index] != '\0')
        parse_utils->index++;
    pop_token(parse_utils, is_comment);
}

void            pop_line_until_endcomment(t_parse_utils *parse_utils, bool *is_comment)
{
    while (parse_utils->line[parse_utils->index] != '\0')
    {
        if (parse_utils->line[parse_utils->index] == '*' && parse_utils->line[parse_utils->index + 1] == '/')
        {
            *is_comment = false;
            parse_utils->index += 2;
            break;
        }
        parse_utils->index++;
    }
    pop_token(parse_utils, is_comment);
}

const char  *get_variable_name(t_parse_utils *parse_utils)
{
    char    *result_buffer;
    size_t  old_index;

    skip_space(parse_utils);
    old_index = parse_utils->index;
    while (isalnum(parse_utils->line[parse_utils->index])
            || parse_utils->line[parse_utils->index] == '_')
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
        parse_utils->current_token.token_type = TOK_FUNC_CALL;
    return (result_buffer);
}

void        expect(char expected, t_parse_utils *parse_utils, bool *is_comment)
{
    if (parse_utils->line[parse_utils->index - 1] == expected)
        pop_token(parse_utils, is_comment);
    else
    {
       fprintf(stderr, "Parse Error: Expected token '%c' at position %lu\n",
           expected, parse_utils->index);
       exit(0);
    }
}
