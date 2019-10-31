/*
** ETNA PROJECT, 31/10/2019 by courta_f
** c:\Users\Fr4nck\Desktop\group-716039
** File description:
**      
*/

#ifndef                     _INSTRUCTIONS_H_
# define                    _INSTRUCTIONS_H_

# include                   <ast.h>
# include                   <stdbool.h>
# include                   <stddef.h>
# include                   <stack.h>

# define                    NB_INSTRUCTIONS     10

typedef stack_node_t        *(*t_ptr_instruction)(ast_node_t *ast_node1, stack_node_t *stack);

typedef struct              s_instruct {
    const char              *instruct_name;
    var_type_t              return_type;
    t_ptr_instruction       exec_instruction;
}                           instruct_t;


instruct_t                  *get_instruction(instruct_t instruct_list[NB_INSTRUCTIONS], const char *instruct_name);
void                        free_list_instructions(instruct_t instruct_list[NB_INSTRUCTIONS]);

stack_node_t                *instruct_push(ast_node_t *ast_node1, stack_node_t *stack);
stack_node_t                *instruct_pop(ast_node_t *ast_node1, stack_node_t *stack);
stack_node_t                *instruct_add(ast_node_t *ast_node1, stack_node_t *stack);
stack_node_t                *instruct_sub(ast_node_t *ast_node1, stack_node_t *stack);
stack_node_t                *instruct_mul(ast_node_t *ast_node1, stack_node_t *stack);
stack_node_t                *instruct_div(ast_node_t *ast_node1, stack_node_t *stack);
stack_node_t                *instruct_mod(ast_node_t *ast_node1, stack_node_t *stack);
stack_node_t                *instruct_assert(ast_node_t *ast_node1, stack_node_t *stack);
stack_node_t                *instruct_dump(ast_node_t *ast_node1, stack_node_t *stack);
stack_node_t                *instruct_print(ast_node_t *ast_node1, stack_node_t *stack);


#endif                      /* _INSTRUCTIONS_H_ */
