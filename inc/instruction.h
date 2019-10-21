#ifndef                     _INSTRUCTION_H_
# define                    _INSTRUCTION_H_

# include                   <ast.h>
# include                   <stdbool.h>
# include                   <stddef.h>
# include                   <variables.h>

typedef void                (*t_ptr_instruction)(t_ast_node *ast_node, t_ast_node *ast_node1);

typedef struct              s_instruct_node
{
    const char              *instruct_name;
    t_var_type              return_type;
    t_ptr_instruction       exec_function;
    struct s_instruct_node  *next;
}                           t_instruct_node;

typedef struct              s_instruct_list
{
    size_t                  size;
    t_instruct_node         *first;
    t_instruct_node         *last;

}                           t_instruct_list;

void				        init_list_instructions(t_instruct_list *list);
t_instruct_node             *get_instruction(t_instruct_list *list, const char *instruct_name);
void                        push_back_instruction(t_instruct_list *list, const char *instruct_name, t_ptr_instruction instruction_to_exec);
void                        fill_instructions(t_instruct_list *list);
void                        free_list_instructions(t_instruct_list *list);

void                        my_push(t_ast_node *ast_node, t_ast_node *ast_node1);


#endif                  /* _INSTRUCTION_H_ */
