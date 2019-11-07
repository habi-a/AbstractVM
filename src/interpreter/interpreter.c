/*
** ETNA PROJECT, 31/10/2019 by courta_f
** c:\Users\Fr4nck\Desktop\group-716039
** File description:
**
*/

#include <my.h>
#include <interpreter.h>
#include <stdlib.h>

ast_node_t *interpreter(ast_node_t *ast, stack_node_t **stack
                        , type_t type_list[NB_TYPES]
                        , instruct_t instruct_list[NB_INSTRUCT])
{
    if (ast == NULL) {
        my_printf("Syntax error\n");
        return (NULL);
    }
    return (interpret_node(ast, stack, type_list, instruct_list));
}
