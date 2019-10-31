/*
** ETNA PROJECT, 31/10/2019 by courta_f & habi_a
** c:\Users\Fr4nck\Desktop\group-716039
** File description:
**      Le fichier principale.
*/

#include <ast.h>
#include <instructions.h>
#include <interpreter.h>
#include <my.h>
#include <parser.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <types.h>
#include <stack.h>
#include <unistd.h>
#include <fcntl.h>

static void     execute(const char *cin, stack_node_t **stack,
                        type_t type_list[NB_TYPES],
                        instruct_t instruct_list[NB_INSTRUCTIONS])
{
    ast_node_t  *ast_node;

    ast_node = parse(cin);
    interpret(ast_node, stack, type_list, instruct_list);
    destruct_astnode(ast_node);
}

static void     loop_reader(stack_node_t **stack, type_t type_list[NB_TYPES],
                        instruct_t instruct_list[NB_INSTRUCTIONS])
{
    char        *cin = NULL;
    bool        repl_exit = false;
    size_t      size_cin = 0;

    while (getline(&cin, &size_cin, stdin) != -1 && cin && !repl_exit) {
        if (!strcmp(cin, "exit"))
            repl_exit = true;
        else if (!is_white_line(cin))
            execute(cin, stack, type_list, instruct_list);
        free(cin);
        cin = NULL;
        size_cin = 0;
    }
    free(cin);
}

static void     abstractvm(type_t type_list[NB_TYPES],
                        instruct_t instruct_list[NB_INSTRUCTIONS])
{
    stack_node_t  *stack = NULL;
    loop_reader(&stack, type_list, instruct_list);
    //free_stack(&stack);
    //free_list_instructions(instruct_list);
    //free_list_types(type_list);
}

int             main()
{
    instruct_t  instruct_list[NB_INSTRUCTIONS] = {
        {my_strdup("push"),    T_VOID,     &instruct_push},
        {my_strdup("pop"),     T_VOID,     &instruct_pop},
        {my_strdup("add"),     T_VOID,     &instruct_add},
        {my_strdup("sub"),     T_VOID,     &instruct_sub},
        {my_strdup("mul"),     T_VOID,     &instruct_mul},
        {my_strdup("div"),     T_VOID,     &instruct_div},
        {my_strdup("mod"),     T_VOID,     &instruct_mod},
        {my_strdup("assert"),  T_VOID,     &instruct_assert},
        {my_strdup("dump"),    T_VOID,     &instruct_dump},
        {my_strdup("print"),   T_VOID,     &instruct_print}
    };
    type_t      type_list[NB_TYPES] = {
        {my_strdup("int8"),    T_INT8,     &my_int8},
        {my_strdup("int16"),   T_INT16,    &my_int16},
        {my_strdup("int32"),   T_INT32,    &my_int32},
        {my_strdup("float"),   T_FLOAT,    &my_float},
        {my_strdup("double"),  T_DOUBLE,   &my_double}
    };

    abstractvm(type_list, instruct_list);
    return (0);
}
