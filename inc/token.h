#ifndef             _TOKEN_H_
# define            _TOKEN_H_

# include           <stack.h>
# include           <stdint.h>

typedef enum        e_token_type
{
                    TOK_NUMBER,
                    TOK_LEFT_PAREN,
                    TOK_RIGHT_PAREN,
                    TOK_COMMA,
                    TOK_TYPE,
                    TOK_INSTRUCTION,
                    TOK_END_TEXT,
                    TOK_ERROR
}                   t_token_type;

typedef struct      s_token
{
    t_token_type    token_type;
    const char      *var_name;
    t_var_type      var_type;
    int8_t          value_int8;
    int16_t         value_int16;
    int32_t         value_int32;
    float           value_float;
    double          value_double;
    char            value_symbol;
}                   t_token;

void                init_token(t_token *token);

#endif              /* _TOKEN_H_ */
