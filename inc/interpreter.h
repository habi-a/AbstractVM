#ifndef     _INTERPRETER_H
# define    _INTERPRETER_H_

# include   <ast.h>
# include   <function.h>
# include   <instruction.h>
# include   <variables.h>

t_ast_node  *interpret(t_ast_node *ast, t_var_list *var_list, t_func_list *func_list, t_instruct_list *instruct_list);

#endif      /* _INTERPRETER_H_ */
