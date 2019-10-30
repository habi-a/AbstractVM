#ifndef     _INTERPRETER_H
# define    _INTERPRETER_H_

# include   <ast.h>
# include   <instructions.h>
# include   <types.h>
# include   <stack.h>

ast_node_t  *interpret(ast_node_t *ast, stack_node_t **stack, type_t type_list[NB_TYPES], instruct_t instruct_list[NB_INSTRUCTIONS]);

#endif      /* _INTERPRETER_H_ */
