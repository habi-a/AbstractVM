#ifndef             _TOKEN_H_
# define            _TOKEN_H_

# include           <stack.h>
# include           <stdint.h>

typedef enum        e_token_type {
                    TOK_NUMBER,
                    TOK_LEFT_PAREN,
                    TOK_RIGHT_PAREN,
                    TOK_TYPE,
                    TOK_INSTRUCTION,
                    TOK_END_TEXT,
                    TOK_ERROR
}                   token_type_t;

typedef struct      s_token {
    token_type_t    token_type;
    const char      *var_name;
    var_type_t      var_type;
    int8_t          value_int8;
    int16_t         value_int16;
    int32_t         value_int32;
    float           value_float;
    double          value_double;
    char            value_symbol;
}                   token_t;

void                init_token(token_t *token);

#endif              /* _TOKEN_H_ */
