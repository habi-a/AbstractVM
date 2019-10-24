#include <ast.h>
#include <instructions.h>
#include <interpreter.h>
#include <parser.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <types.h>
#include <variables.h>

static void     execute(const char *cin, t_var_list *var_list,
                        t_type type_list[NB_TYPES],
                        t_instruct instruct_list[NB_INSTRUCTIONS])
{
    t_ast_node  *ast_node;

    ast_node = parse(cin, var_list);
    interpret(ast_node, var_list, type_list, instruct_list);
    destruct_astnode(ast_node);
}

static void     loop_reader(t_var_list *var_list, t_type type_list[NB_TYPES],
                        t_instruct instruct_list[NB_INSTRUCTIONS])
{
    char        *cin;
    bool        repl_exit;
    size_t      size_cin;

    cin = NULL;
    size_cin = 0;
    repl_exit = false;
    printf("\033[0;36m>> \033[0m");
    while (getline(&cin, &size_cin, stdin) != -1 && cin && !repl_exit)
    {
        printf("\033[0;32m");
        cin[strlen(cin) - 1] = '\0';
        if (!strcmp(cin, "exit"))
            repl_exit = true;
        else if (!is_white_line(cin))
            execute(cin, var_list, type_list, instruct_list);
        free(cin);
        cin = NULL;
        size_cin = 0;
        printf("\033[0m");
        if (!repl_exit)
	       printf("\n\033[0;36m>> \033[0m");
    }
    free(cin);
}

static void     abstractvm(t_var_list *var_list, t_type type_list[NB_TYPES],
                        t_instruct instruct_list[NB_INSTRUCTIONS])
{
    init_list_variables(var_list);
    loop_reader(var_list, type_list, instruct_list);
    free_list_variables(var_list);
    free_list_instructions(instruct_list);
    free_list_types(type_list);
}

int             main()
{
    t_var_list  var_list;
    t_instruct  instruct_list[NB_INSTRUCTIONS] = {
        {strdup("push"),    T_VOID,     &instruct_push},
        {strdup("pop"),     T_VOID,     &instruct_pop},
        {strdup("add"),     T_VOID,     &instruct_add},
        {strdup("sub"),     T_VOID,     &instruct_sub},
        {strdup("mul"),     T_VOID,     &instruct_mul},
        {strdup("div"),     T_VOID,     &instruct_div},
        {strdup("mod"),     T_VOID,     &instruct_mod},
        {strdup("assert"),  T_VOID,     &instruct_assert},
        {strdup("dump"),    T_VOID,     &instruct_dump},
        {strdup("print"),   T_VOID,     &instruct_print}
    };
    t_type      type_list[NB_TYPES] = {
        {strdup("int8"),    T_INT,      &my_int8},
        {strdup("int16"),   T_INT,      &my_int16},
        {strdup("int32"),   T_INT,      &my_int32},
        {strdup("float"),   T_FLOAT,    &my_float},
        {strdup("double"),  T_DOUBLE,   &my_double}
    };

    abstractvm(&var_list, type_list, instruct_list);
    return (0);
}
