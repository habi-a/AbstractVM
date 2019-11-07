/*
** ETNA PROJECT, 31/10/2019 by courta_f
** c:\Users\Fr4nck\Desktop\group-716039
** File description:
**
*/

#include <parser.h>
#include <stdlib.h>
#include <token.h>

void init_parse_utils(parse_utils_t *parse_utils, const char *line)
{
    parse_utils->index = 0;
    parse_utils->line = line;
    parse_utils->nb_token = 0;
    parse_utils->decla_type = T_UNDEFINED;
}

bool_t is_white_line(const char *line)
{
    unsigned int i = 0;

    while (line[i] != '\0') {
        if (line[i] == ';')
            break;
        else if (!my_isspace(line[i]))
            return (e_false);
        i++;
    }
    return (e_true);
}

void skip_space(parse_utils_t *parse_utils)
{
    while (my_isspace(parse_utils->line[parse_utils->index]))
        parse_utils->index++;
}

void pop_line(parse_utils_t *parse_utils)
{
    while (parse_utils->line[parse_utils->index] != '\0')
        parse_utils->index++;
    pop_token(parse_utils);
}

void expect(char expected, parse_utils_t *parse_utils)
{
    if (parse_utils->line[parse_utils->index - 1] == expected)
        pop_token(parse_utils);
    else {
       my_printf("Parse Error: Expected token '%c' at position %lu\n",
           expected, parse_utils->index);
    }
}
