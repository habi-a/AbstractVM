#ifndef                     _INSTRUCTION_H_
# define                    _INSTRUCTION_H_

# include                   <ast.h>
# include                   <stdbool.h>
# include                   <stddef.h>
# include                   <variables.h>

# define                    NB_INSTRUCTIONS     10

typedef void                (*t_ptr_instruction)(t_ast_node *ast_node, t_ast_node *ast_node1);

typedef struct              s_instruct
{
    const char              *instruct_name;
    t_var_type              return_type;
    t_ptr_instruction       exec_instruction;
}                           t_instruct;


t_instruct                  *get_instruction(t_instruct instruct_list[NB_INSTRUCTIONS], const char *instruct_name);
void                        free_list_instructions(t_instruct instruct_list[NB_INSTRUCTIONS]);

void                        instruct_push(t_ast_node *ast_node, t_ast_node *ast_node1);
void                        instruct_pop(t_ast_node *ast_node, t_ast_node *ast_node1);
void                        instruct_add(t_ast_node *ast_node, t_ast_node *ast_node1);
void                        instruct_sub(t_ast_node *ast_node, t_ast_node *ast_node1);
void                        instruct_mul(t_ast_node *ast_node, t_ast_node *ast_node1);
void                        instruct_div(t_ast_node *ast_node, t_ast_node *ast_node1);
void                        instruct_mod(t_ast_node *ast_node, t_ast_node *ast_node1);
void                        instruct_assert(t_ast_node *ast_node, t_ast_node *ast_node1);
void                        instruct_dump(t_ast_node *ast_node, t_ast_node *ast_node1);
void                        instruct_print(t_ast_node *ast_node, t_ast_node *ast_node1);


#endif                  /* _INSTRUCTION_H_ */
