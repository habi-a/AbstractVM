# AbstractVM
## Required
- **Build-essential**
- **Make**

## What is AbstractVM ?

AbstractVM is a stack machine that evaluates simple arithmetic expressions. These expressions are supplied to the machine by programs written in a language similar to the assembler.

## Instructions

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
| print                | Check if the top value of the stack is of int8 type, and print the corresponding ASCII code              |
| exit                 | Exit the program                                                                                         |

## Types
- int8
- int16
- int32
- float
- double

## Example AVM File
File test.avm:
```
; exemple.avm
push int32(42)
push int32(33)
add
push float(44.55)
mul
push double(42.42)
push int32(42)
pop
assert double(42.42)
pop
dump
exit
```

## Build and Run
<code>
$> export LD_LIBRARY_PATH=.
</code>
<code>
$> make
</code>
<code>
$> ./abstractvm \<file.avm\>
</code>
