# C Preprocessors

## What is preprocessor?
- A preprocessor is a program that processes its input data to produce output that is used as input as another program. the output is said to be a pre-processed form of the data, which is often used by some subsequent programs like compilers. (_source:_ [Wikipedia/Preprocessor](https://en.wikipedia.org/wiki/Preprocessor))

## What is C preprocessor?
- If you have EVER tried printing `"Hello, World!"`, in C language, you'd know that, no, you can't just start doing `printf(...)`, You'd have needed to `#include<stdio.h>` (includes stdio.h - _standard input/output header file_), it is called a $preprocessor$, which, in our case, is used for file inclusion.
- In C, the processor is the macro preprocessor, which provides file inclusion, macro expansions, conditional compilation, and line control.
- The C Processor is not part of the compiler, but a separate step in the compilation process.
- In simpler terms, it is just a text substitution tool and it instructs the compiler to do required pre-processing before the actual compilation.
- All preprocessor commands begin with '`#`' (a hash symbol).

- The list of preprocessor directives:

| Directive   | Description                                                           | Usage                                              |
| :---------: | :-------------------------------------------------------------------: | :------------------------------------------------: |
| `#define`   | Substitues a preprocessor maco.                                       | `#define _name _definition`                        |
| `#include`  | Inserts a particular header from another file.                        | `#include <filename.h>` or `#include "filename.h"` |
| `#undef`    | Undefines a preprocessor macro.                                       | `#undef _name`                                     |
| `#ifdef`    | Returns true if this macro is defined.                                | `#ifdef _name`                                     |
| `#ifndef`   | Returns true if this macro is not defined                             | `#ifndef _name`                                    |
| `#if`       | Tests if a compile time condition is true.                            | `#if _condition`                                   |
| `#else`     | The alternative of `#if`                                              | `#else`                                            |
| `#elif`     | `#else` and `#if` in one statement                                    | `#elif _condition`                                 |
| `#endif`    | Ends preprocessor conditional.                                        | `#endif`                                           |
| `#error`    | Prints error message on `stderr`                                      | `#error _error_message`                            |
| `#warning`  | Prints warning message                                                | `#warning _warning_message`                        |
| `#pragma`   | Issues special commands to the compiler, using a standardized method. | `#pragma _command(s)`                              |

### Usage Examples:
---
```c
#define PI 3.1415
#define e 2.7181
```
- It defines `PI` as `3.1415` and `e` as `2.7181` at program compilation time.
---

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myHeaderFile.h"
```
- It includes `stdio.h`, `stdlib.h`, `string.h`, and custom-made "`myHeaderFile.h`" in the file they are being used.
---

```c
#define NAME "Phoebe Buffay"
#undef NAME
#define NAME "Regina Phalange"
```
- It defines `NAME` as "Pheobe Buffay", then undefines it and, then defines it again as "Regina Phalange".
---

```c
#define square(x) x*x
#define print(x) printf(#x)
```
> `#` is 'stringize' operator, which converts `x` into a string.
- Like this, we can make them act like functions, too.
> This types of macros are called 'Parameterized macros'.
---

```c
#define numberize(n) token##n
```
> `##` is 'token paster' operator, which will covert `numberize(0)` to `token0`, pre-compilation time.
```c
#include <stdio.h>

#define tokenpaster(n) printf ("token" #n " = %d", token##n)

int main(void) {
   int token45 = 90;
   tokenpaster(45);
   return 0;
}
```
output:
```
token45 = 90
```
---

```c
#ifdef PERSON_H
#define NAME "Ken Adams"
#endif
```
- This will define `name` as "Ken Adams", if it is not already defined.
---

```c
#ifdef DEBUG
    // debug commands, or printf statements to run through it all.
#endif
```
- You can use this as a tool to debug your code, it can be used by adding `-DDEBUG` flag while compiling the code, for example:

```bash
gcc -DDEBUG main.c -o main
```

- and when you don't want to use debug, the normal compilation:
```
gcc main.c -o main
```
---

```c
#ifndef STACK_H
#define STACK_H

// Stack declaration and functionalities

#endif
```
- This defines `STACK_H` (for "`stack.h`"), if it is not already defined.
- It is very helpful while creating your own header files.
---

```c
#if !defined(NAME_H)
    #define NAME_H
    /** ... */
#endif
```
> `defined()` operator is used to check whether the identifier is defined using `#define` or not, it return zero for not defined, and non-zero for defined.
- the code above, defines `NAME_H` if it is not already defined.
---

```c
#ifndef MAXSIZE
    #error "MAXSIZE not defined"
#endif
```
- This will simply throw an error, if `MAXSIZE` is not defined.
---

```c
#ifndef MAXSIZE
    #warning "MAXSIZE not defined"
#endif
```
- This will show a warning, if `MAXSIZE` is not defined.
---

- `#pragma`
    - can be used if `#warning` and/or `#error` macros aren't supported by your compiler.
    - more about `#pragma`:

| Pragma Directive           | Description                                                                                                            |
| :------------------------: | :--------------------------------------------------------------------------------------------------------------------: |
| `#pragma once`             | Ensures that the header file is included only once during compilation (header guards).                                 |
| `#pragma message(...)`     | Emits a custom message during compilation.                                                                             |
| `#pragma warning(...)`     | Generates a compiler warning with a custom message.                                                                    |
| `#pragma error(...)`       | Generates a compiler error with a custom message.                                                                      |
| `#pragma pack(...))`       | To define `pack` size [used with `struct`) (valid args: `size` (1, 2, 4, 8, ...) or to reset default size use `reset`] |

## Predefined Macros
- ANSI C defines a number of macros. Although each one is available for use in programming, the predefined macros should not be directly modified.
	
    - `__DATE__` : The current date as a character literal in "MMM DD YYYY" format.
    - `__TIME__` : The current time as a character literal in "HH:MM:SS" format.
    - `__FILE__` : This contains the current filename as a string literal.
    - `__LINE__` : This contains the current line number as a decimal constant.
    - `__STDC__` : Defined as 1 when the compiler complies with the ANSI standard.



> _learned from_ [Tutorials Point](https://www.tutorialspoint.com/cprogramming/c_preprocessors.htm)
