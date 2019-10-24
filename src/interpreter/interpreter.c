#include <interpreter.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

t_ast_node      *interpret(t_ast_node *ast, t_stack_node *stack,
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
    if (ast->node_type == AST_CALL_FUNC)
    {
        if (!get_type(type_list, ast->var_name))
        {
            fprintf(stderr, "Parse Error: Unknown type '%s'\n",
            ast->var_name);
            exit(0);
        }
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
        stack = get_instruction(instruct_list, ast->var_name)->exec_instruction(ast, left_result, stack);
        return (ast);
    }
    right_result = interpret(ast->ast_node_r, stack, type_list, instruct_list);
    switch (ast->node_type)
    {
        case AST_PLUS:
            if (right_result->var_type != T_INT)
                ast->var_type = right_result->var_type;
            else
                ast->var_type = left_result->var_type;
            ast->value_float = left_result->value_float + right_result->value_float;
            ast->value_int = (int)ast->value_float;
            return (ast);
        case AST_MINUS:
            if (right_result->var_type != T_INT)
                ast->var_type = right_result->var_type;
            else
                ast->var_type = left_result->var_type;
            ast->value_float = left_result->value_float - right_result->value_float;
            ast->value_int = (int)ast->value_float;
            return (ast);
        case AST_MUL:
            if (right_result->var_type != T_INT)
                ast->var_type = right_result->var_type;
            else
                ast->var_type = left_result->var_type;
            ast->value_float = left_result->value_float * right_result->value_float;
            ast->value_int = (int)ast->value_float;
            return (ast);
        case AST_DIV:
            if (right_result->var_type != T_INT)
                ast->var_type = right_result->var_type;
            else
                ast->var_type = left_result->var_type;
            if (right_result->value_float)
            {
                ast->value_float = left_result->value_float / right_result->value_float;
                ast->value_int = (int)ast->value_float;
            }
            else
            {
                ast->value_float = 0;
                ast->value_int = 0;
            }
            return (ast);
        default: break;
    }
    fprintf(stderr, "Syntax error\n");
    exit(0);
}
