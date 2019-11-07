# AbstractVM
#
## Required
- **Build-essential**
- **Make**

## What is AbstractVM ?

AbstractVM is a stack machine that evaluates simple arithmetic expressions. These expressions are supplied to the machine by programs written in a language similar to the assembler.

## Les Instructions

| Instruction          |  Description                                                                                             |
| -------------------- | -------------------------------------------------------------------------------------------------------- |
| push "Value"         | Push the value "Value"                                                                                   |
| pop                  | Pop a value from the top of the stack                                                                    |
| add                  | Pop two values a and b, calculate the sum b + a, and push the result into the stack                      |
| sub                  | Pop two values a and b, calculate the difference b - a, and push the result into the stack               |
| mul                  | Pop two values a and b, calculate the product b * a, and push the result into the stack                  |
| div                  | Pop two values a and b, calculate the quotient b / a, and push the result into the stack                 |
| mod                  | Pop two values a and b, calculate the modulo b % a, and push the result into the stack                   |
| assert "Value"       | Check if the top value of the stack is equal to "Value"                                                  |
| dump                 | Pritnt all the content of the stack                                                                      |
| print                | Check if the top value of the stack is of type int8, et print the code ASCII corresponding on the stdout |
| exit                 | Exit the program                                                                                         |

## Build and Run

- ***$> export LD_LIBRARY_PATH=.***
- ***$> make***
- ***$> ./abstractvm \<file.avm\>***

