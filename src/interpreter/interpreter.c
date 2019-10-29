#include <interpreter.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

t_ast_node      *interpret(t_ast_node *ast, t_stack_node **stack,
                            t_type type_list[NB_TYPES],
                            t_instruct instruct_list[NB_INSTRUCTIONS])
{
    t_ast_node  *left_result;
    t_ast_node  *right_result;

    if (ast == NULL)
    {
        fprintf(stderr, "Syntax error\n");
        exit(0);
    }
    if (ast->node_type == AST_NUMBER || ast->node_type == AST_NULL)
        return (ast);

    left_result = interpret(ast->ast_node_l, stack, type_list, instruct_list);
    if (ast->node_type == AST_TYPE)
    {
        if (!get_type(type_list, ast->var_name))
        {
            fprintf(stderr, "Parse Error: Unknown type '%s'\n",
            ast->var_name);
            exit(0);
        }
        ast->var_type = get_type(type_list, ast->var_name)->return_type;
        get_type(type_list, ast->var_name)->exec_type(ast, left_result);
        return (ast);
    }
    if (ast->node_type == AST_INSTRUCTION)
    {
        if (!get_instruction(instruct_list, ast->var_name))
        {
            fprintf(stderr, "Parse Error: Unknown instruction '%s'\n",
            ast->var_name);
            exit(0);
        }
        ast->var_type = get_instruction(instruct_list, ast->var_name)->return_type;
        *stack = get_instruction(instruct_list, ast->var_name)->exec_instruction(left_result, *stack);
        return (ast);
    }
    right_result = interpret(ast->ast_node_r, stack, type_list, instruct_list);
    switch (ast->node_type)
    {
        case AST_PLUS:
            ast->node_type = left_result->node_type;
            ast->var_type = left_result->var_type;
            ast->value_int8 = left_result->value_int8 + right_result->value_int8;
            ast->value_int16 = left_result->value_int16 + right_result->value_int16;
            ast->value_int32 = left_result->value_int32 + right_result->value_int32;
            ast->value_float = left_result->value_float + right_result->value_float;
            ast->value_double = left_result->value_double + right_result->value_double;
            return (ast);
        case AST_MUL:
            ast->node_type = left_result->node_type;
            ast->var_type = left_result->var_type;
            ast->value_int8 = left_result->value_int8 + right_result->value_int8;
            ast->value_int16 = left_result->value_int16 + right_result->value_int16;
            ast->value_int32 = left_result->value_int32 + right_result->value_int32;
            ast->value_float = left_result->value_float + right_result->value_float;
            ast->value_double = left_result->value_double + right_result->value_double;
            return (ast);
        default: break;
    }
    fprintf(stderr, "Syntax error\n");
    exit(0);
}
