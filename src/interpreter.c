#include <interpreter.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static bool     is_compatible_type(t_ast_node *left_result, t_ast_node *right_result)
{
    if (left_result->var_type == right_result->var_type)
        return (true);
    else if (left_result->var_type == T_INT || right_result->var_type == T_INT)
        return (true);
    return (false);
}

/*static void     push_back_variable(t_var_list *list, t_ast_node *left_result, t_ast_node *right_result)
{
    t_var_node  *new_element;

    new_element = malloc(sizeof(t_var_node));
    if (new_element == NULL)
        return ;
    new_element->var_name = strdup(left_result->var_name);
    if (new_element->var_name == NULL)
        return ;
    new_element->var_type = left_result->var_type;
    new_element->value_float = right_result->value_float;
    if (new_element->var_type == T_INT)
        new_element->value_float = (int)right_result->value_float;
    else
        new_element->value_float = right_result->value_float;
    new_element->value_int = (int)right_result->value_float;
    new_element->next = NULL;
    list->size++;
    if (list->last != NULL)
        list->last->next = new_element;
    else
        list->first = new_element;
    list->last = new_element;
}*/

t_ast_node      *interpret(t_ast_node *ast, t_var_list *var_list, t_func_list *func_list)
{
    t_ast_node  *left_result;
    t_ast_node  *right_result;

    if (ast == NULL)
    {
        fprintf(stderr, "Syntax error");
        exit(0);
    }
    if (ast->node_type == AST_NUMBER || ast->node_type == AST_NULL)
        return (ast);
    else if (ast->node_type == AST_UNARY_MIN)
    {
        ast->ast_node_l->value_float *= (-1);
        ast->ast_node_l->value_int *= (-1);
        return (interpret(ast->ast_node_l, var_list, func_list));
    }
    else
    {
        left_result = interpret(ast->ast_node_l, var_list, func_list);
        right_result = interpret(ast->ast_node_r, var_list, func_list);
        if (ast->node_type == AST_CALL_FUNC)
        {
            if (!get_function(func_list, ast->var_name))
            {
                fprintf(stderr, "Parse Error: Unknown function '%s'\n",
                        ast->var_name);
                exit(0);
            }
            if (get_function(func_list, ast->var_name)->func_type == FUNC_BUILT_IN)
                get_function(func_list, ast->var_name)->ptr_built_in(ast, left_result, right_result);
            return (ast);
        }
        if (!is_compatible_type(left_result, right_result))
        {
            fprintf(stderr, "Impossible Cast, incompatible type\n");
            exit(0);
        }
        switch (ast->node_type)
        {
            case AST_PLUS:
                ast->node_type = AST_VARIABLE;
                if (right_result->var_type != T_INT)
                    ast->var_type = right_result->var_type;
                else
                    ast->var_type = left_result->var_type;
                ast->value_float = left_result->value_float + right_result->value_float;
                ast->value_int = (int)ast->value_float;
                return (ast);
            case AST_MINUS:
                ast->node_type = AST_VARIABLE;
                if (right_result->var_type != T_INT)
                    ast->var_type = right_result->var_type;
                else
                    ast->var_type = left_result->var_type;
                ast->value_float = left_result->value_float - right_result->value_float;
                ast->value_int = (int)ast->value_float;
                return (ast);
            case AST_MUL:
                ast->node_type = AST_VARIABLE;
                if (right_result->var_type != T_INT)
                    ast->var_type = right_result->var_type;
                else
                    ast->var_type = left_result->var_type;
                ast->value_float = left_result->value_float * right_result->value_float;
                ast->value_int = (int)ast->value_float;
                if (right_result->var_type == T_STRING && left_result->var_type == T_STRING)
                {
                    fprintf(stderr, "Operation not permitted for strings\n");
                    exit(0);
                }
                return (ast);
            case AST_DIV:
                ast->node_type = AST_VARIABLE;
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
    }
    fprintf(stderr, "Syntax error\n");
    exit(0);
}
