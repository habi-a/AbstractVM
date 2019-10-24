#ifndef                     _INSTRUCTION_H_
# define                    _INSTRUCTION_H_

# include                   <ast.h>
# include                   <stdbool.h>
# include                   <stddef.h>
# include                   <stack.h>

# define                    NB_INSTRUCTIONS     10

typedef t_stack_node *                (*t_ptr_instruction)(t_ast_node *ast_node1, t_stack_node *stack);

typedef struct              s_instruct
{
    const char              *instruct_name;
    t_var_type              return_type;
    t_ptr_instruction       exec_instruction;
}                           t_instruct;


t_instruct                  *get_instruction(t_instruct instruct_list[NB_INSTRUCTIONS], const char *instruct_name);
void        free_list_instructions(t_instruct instruct_list[NB_INSTRUCTIONS]);

t_stack_node *instruct_push(t_ast_node *ast_node1, t_stack_node *stack);
t_stack_node *instruct_pop(t_ast_node *ast_node1, t_stack_node *stack);
t_stack_node *instruct_add(t_ast_node *ast_node1, t_stack_node *stack);
t_stack_node *instruct_sub(t_ast_node *ast_node1, t_stack_node *stack);
t_stack_node *instruct_mul(t_ast_node *ast_node1, t_stack_node *stack);
t_stack_node *instruct_div(t_ast_node *ast_node1, t_stack_node *stack);
t_stack_node *instruct_mod(t_ast_node *ast_node1, t_stack_node *stack);
t_stack_node *instruct_assert(t_ast_node *ast_node1, t_stack_node *stack);
t_stack_node *instruct_dump(t_ast_node *ast_node1, t_stack_node *stack);
t_stack_node *instruct_print(t_ast_node *ast_node1, t_stack_node *stack);


#endif                  /* _INSTRUCTION_H_ */
