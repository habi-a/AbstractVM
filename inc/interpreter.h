#ifndef     _INTERPRETER_H
# define    _INTERPRETER_H_

# include   <ast.h>
# include   <instructions.h>
# include   <types.h>
# include   <stack.h>

t_ast_node  *interpret(t_ast_node *ast, t_stack_node **stack, t_type type_list[NB_TYPES], t_instruct instruct_list[NB_INSTRUCTIONS]);

#endif      /* _INTERPRETER_H_ */
