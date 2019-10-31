/*
** ETNA PROJECT, 31/10/2019 by courta_f & habi_a
** c:\Users\Fr4nck\Desktop\group-716039
** File description:
**      
*/

#ifndef             _PARSER_H_
# define            _PARSER_H_

# include            <ast.h>
# include            <stdbool.h>
# include            <stddef.h>
# include            <token.h>
# include            <stack.h>

typedef struct      s_parse_utils {
    var_type_t      decla_type;
    size_t          index;
    size_t          nb_token;
    const char      *line;
    token_t         current_token;
}                   parse_utils_t;

ast_node_t          *expression(parse_utils_t *parse_utils, unsigned short *is_instruction);
ast_node_t          *factor(parse_utils_t *parse_utils, unsigned short *is_instruction);
ast_node_t          *term(parse_utils_t *parse_utils, unsigned short *is_instruction);

void                expect(char expected, parse_utils_t *parse_utils);
void                get_number(parse_utils_t *parse_utils);
const char          *get_variable_name(parse_utils_t *parse_utils);
void                init_parse_utils(parse_utils_t *parse_utils, const char *line);
bool                is_white_line(const char *line);
ast_node_t          *parse(const char *line);
void                pop_line(parse_utils_t *parse_utils);
void                pop_token(parse_utils_t *parse_utils);
bool                set_token(parse_utils_t *parse_utils);
void                skip_space(parse_utils_t *parse_utils);

#endif              /* _PARSER_H_ */
