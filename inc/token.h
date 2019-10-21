#ifndef             _TOKEN_H_
# define            _TOKEN_H_

# include           <variables.h>

typedef enum        e_token_type
{
                    TOK_NUMBER,
                    TOK_PLUS,
                    TOK_MINUS,
                    TOK_MUL,
                    TOK_DIV,
                    TOK_LEFT_PAREN,
                    TOK_RIGHT_PAREN,
                    TOK_COMMA,
                    TOK_FUNC_CALL,
                    TOK_END_TEXT,
                    TOK_ERROR
}                   t_token_type;

typedef struct      s_token
{
    t_token_type    token_type;
    const char      *var_name;
    t_var_type      var_type;
    int             value_int;
    float           value_float;
    double          value_double;
    char            value_symbol;
}                   t_token;

void                init_token(t_token *token);

#endif              /* _TOKEN_H_ */
