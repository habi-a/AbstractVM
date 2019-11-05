/*
** ETNA PROJECT, 31/10/2019 by courta_f
** c:\Users\Fr4nck\Desktop\group-716039
** File description:
**      Le fichier principale.
*/

#include <ast.h>
#include <fcntl.h>
#include <instructions.h>
#include <interpreter.h>
#include <my.h>
#include <parser.h>
#include <stack.h>
#include <stdlib.h>
#include <types.h>
#include <unistd.h>

static void     execute(const char *cin, stack_node_t **stack,
                        type_t type_list[NB_TYPES],
                        instruct_t instruct_list[NB_INSTRUCT])
{
    ast_node_t  *ast_node;

    ast_node = parse(cin);
    interpreter(ast_node, stack, type_list, instruct_list);
    destruct_astnode(ast_node);
}

static void     loop_reader(stack_node_t **stack, type_t type_list[NB_TYPES],
                        instruct_t instruct_list[NB_INSTRUCT], int fd)
{
    char        *cin = NULL;
    bool_t      repl_exit = e_false;

    while ((cin = my_getline(fd)) != NULL && !repl_exit) {
        if (!my_strcmp(cin, "exit"))
            repl_exit = true;
        else if (!is_white_line(cin) && !repl_exit)
            execute(cin, stack, type_list, instruct_list);
        free(cin);
    }
    free(cin);
}

static void     abstractvm(type_t type_list[NB_TYPES],
                            instruct_t instruct_list[NB_INSTRUCT],
                            int argc, char **argv)
{
    int filedescriptor;

    if (argc != 2) {
        my_printf("USAGE: ./abstractvm <path_program.avm>\n");
        return ;
    }
    filedescriptor = open(argv[1], O_RDONLY);
    if (filedescriptor < 0)
        return ;
    stack_node_t  *stack = NULL;
    loop_reader(&stack, type_list, instruct_list, filedescriptor);
    free_stack(stack);
    free_list_instructions(instruct_list);
    free_list_types(type_list);
    close(filedescriptor);
}

int             main(int argc, char **argv)
{
    instruct_t  instruct_list[NB_INSTRUCT] = {
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

    abstractvm(type_list, instruct_list, argc, argv);
    return (0);
}
