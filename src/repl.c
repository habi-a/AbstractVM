#include <ast.h>
#include <function.h>
#include <interpreter.h>
#include <parser.h>
#include <repl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <variables.h>

static void     ante(const char *cin, t_var_list *var_list, t_func_list *func_list, t_instruct_list *instruct_list)
{
    t_ast_node  *ast_node;

    ast_node = parse(cin, var_list);
    interpret(ast_node, var_list, func_list, instruct_list);
    destruct_astnode(ast_node);
}

static void     loop_repl(t_var_list *var_list, t_func_list *func_list, t_instruct_list *instruct_list)
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
            ante(cin, var_list, func_list, instruct_list);
        free(cin);
        cin = NULL;
        size_cin = 0;
        printf("\033[0m");
        if (!repl_exit)
	       printf("\n\033[0;36m>> \033[0m");
	    else
	       break;
    }
    free(cin);
}

void            launch_repl()
{
    t_var_list      var_list;
    t_func_list     func_list;
    t_instruct_list instruct_list;

    init_list_variables(&var_list);
    init_list_functions(&func_list);
    init_list_instructions(&instruct_list);
    fill_functions(&func_list);
    fill_instructions(&instruct_list);
    puts("\033[0;35mWelcome to the C-Interpetor by habi-a\033[0m");
    loop_repl(&var_list, &func_list, &instruct_list);
    free_list_variables(&var_list);
    free_list_functions(&func_list);
    free_list_instructions(&instruct_list);
}
