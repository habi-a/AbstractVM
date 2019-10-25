#ifndef             _PARSER_H_
# define            _PARSER_H_

# include            <ast.h>
# include            <stdbool.h>
# include            <stddef.h>
# include            <token.h>
# include            <stack.h>

typedef struct      s_parse_utils
{
    t_var_type      decla_type;
    size_t          index;
    size_t          nb_token;
    const char      *line;
    t_token         current_token;
}                   t_parse_utils;

t_ast_node          *expression(t_parse_utils *parse_utils, unsigned short *is_instruction);
t_ast_node          *factor(t_parse_utils *parse_utils, unsigned short *is_instruction);
t_ast_node          *term(t_parse_utils *parse_utils, unsigned short *is_instruction);

void                expect(char expected, t_parse_utils *parse_utils);
void                get_number(t_parse_utils *parse_utils);
const char          *get_variable_name(t_parse_utils *parse_utils);
void                init_parse_utils(t_parse_utils *parse_utils, const char *line);
bool                is_white_line(const char *line);
t_ast_node          *parse(const char *line);
void                pop_line(t_parse_utils *parse_utils);
void                pop_token(t_parse_utils *parse_utils);
bool                set_token(t_parse_utils *parse_utils);
void                skip_space(t_parse_utils *parse_utils);

#endif              /* _PARSER_H_ */
