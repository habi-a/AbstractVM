/*
** ETNA PROJECT, 31/10/2019 by courta_f
** c:\Users\Fr4nck\Desktop\group-716039
** File description:
**
*/

#include <my.h>
#include <interpreter.h>
#include <stdlib.h>

static ast_node_t *interpret_type(ast_node_t *ast, ast_node_t *left_result,
                                    type_t type_list[NB_TYPES])
{
    if (!get_type(type_list, ast->var_name)) {
        my_printf("Parse Error: Unknown type '%s'\n",
        ast->var_name);
        exit(0);
    }
    ast->var_type = get_type(type_list, ast->var_name)->return_type;
    get_type(type_list, ast->var_name)->exec_type(ast, left_result);
    return (ast);
}

static ast_node_t *interpret_instruction(ast_node_t *ast,
                                        ast_node_t *left_result,
                                        stack_node_t **stack,
                                        instruct_t instruct_list[NB_INSTRUCT])
{
    if (!get_instruction(instruct_list, ast->var_name)) {
        my_printf("Parse Error: Unknown instruction '%s'\n",
        ast->var_name);
        exit(0);
    }
    ast->var_type = get_instruction(instruct_list, ast->var_name)->return_type;
    *stack = get_instruction(instruct_list, ast->var_name)
                ->exec_instruction(left_result, *stack);
    return (ast);
}

static ast_node_t *interpret_plus(ast_node_t *ast, ast_node_t *left_result,
                                    ast_node_t *right_result)
{
    if (left_result->var_type > right_result->var_type)
        ast->var_type = left_result->var_type;
    else
        ast->var_type = left_result->var_type;
    ast->value_int8 = left_result->value_int8 + right_result->value_int8;
    ast->value_int16 = left_result->value_int16 + right_result->value_int16;
    ast->value_int32 = left_result->value_int32 + right_result->value_int32;
    ast->value_float = left_result->value_float + right_result->value_float;
    ast->value_double = left_result->value_double + right_result->value_double;
    return (ast);
}

static ast_node_t *interpret_mul(ast_node_t *ast, ast_node_t *left_result,
                                    ast_node_t *right_result)
{
    if (left_result->var_type > right_result->var_type)
        ast->var_type = left_result->var_type;
    else
        ast->var_type = left_result->var_type;
    ast->value_int8 = left_result->value_int8 * right_result->value_int8;
    ast->value_int16 = left_result->value_int16 * right_result->value_int16;
    ast->value_int32 = left_result->value_int32 * right_result->value_int32;
    ast->value_float = left_result->value_float * right_result->value_float;
    ast->value_double = left_result->value_double * right_result->value_double;
    return (ast);
}

ast_node_t      *interpret_node(ast_node_t *ast, stack_node_t **stack,
                            type_t type_list[NB_TYPES],
                            instruct_t instruct_list[NB_INSTRUCT])
{
    ast_node_t  *left_result;
    ast_node_t  *right_result;

    if (ast->node_type == AST_NUMBER || ast->node_type == AST_NULL)
        return (ast);
    left_result = interpreter(ast->ast_node_l, stack, type_list, instruct_list);
    if (ast->node_type == AST_TYPE)
        return (interpret_type(ast, left_result, type_list));
    if (ast->node_type == AST_INSTRUCTION)
        return (interpret_instruction(ast, left_result, stack, instruct_list));
    right_result = interpreter(ast->ast_node_r, stack, type_list,
                                instruct_list);
    switch (ast->node_type) {
        case AST_PLUS:
            return (interpret_plus(ast, left_result, right_result));
        case AST_MUL:
            return (interpret_mul(ast, left_result, right_result));
        default: break;
    }
    my_printf("Syntax error\n");
    exit(0);
}
