*This project has been created as part of the 42 curriculum by jabernar.*

# ft_printf

## Description:

This is my second project of the 42 School curriculum. Its goal is to recode the `printf()` function from libc, learning how variadic functions work (`va_list`, `va_start`, `va_arg`, `va_end`), how to convert numbers between bases (decimal and hexadecimal), and how to organize the code in a static C library to reuse in later projects.

The prototype of the function is:

```c
int ft_printf(const char *, ...);
```

Like the original, it returns the number of characters printed. The buffer management of the original `printf()` is not implemented.

Only the **mandatory part** was done. The bonus part (flags `-0.`, field minimum width, `#`, `+` and space) was not implemented.

## Instructions:

### 1. Adding this lib to your project:

- `git submodule add git@vogsphere.42porto.com:vogsphere/intra-uuid-1fe7dd8e-7a9b-4b87-9c0e-56cb7d88c722-7800309-jabernar ft_printf` to create a submodule (recommended).

or

- `git@vogsphere.42porto.com:vogsphere/intra-uuid-1fe7dd8e-7a9b-4b87-9c0e-56cb7d88c722-7800309-jabernar` to clone the repository.

### 2. Creating/compiling or updating the local library:

- Use the following commands on the terminal.

- `make` - to create or update the static library `libftprintf.a`.

- `make clean` - to delete all the .o files used to create the library.

- `make fclean` - to delete all the .o files and the library.

- `make re` - to delete all .o files and the library, and recreate them.

### 3. Including the lib to your files:

On the files you're in need to use this lib, you must `#include "ft_printf/ft_printf.h"`

### 4. Compiling your code

Use the following flags to link everything together:  
`-Lft_printf -lftprintf -Ift_printf`

where:  
"-I" instruct the system where to find the header file  
"-L" instruct the system where to find the libftprintf.a  
"-l" instruct the system which lib to link (exclude the "lib" prefix and the ".a" extension).

Example:

```bash
cc -Wall -Wextra -Werror main.c -Lft_printf -lftprintf -Ift_printf -o program
```

## Conversions handled:

| Conversion | Description                                                  | Argument type  |
| ---------- | ------------------------------------------------------------ | -------------- |
| `%c`       | Prints a single character.                                   | `int`          |
| `%s`       | Prints a string (as defined by the common C convention).     | `char *`       |
| `%p`       | Prints the `void *` pointer argument in hexadecimal format.  | `void *`       |
| `%d`       | Prints a decimal (base 10) number.                           | `int`          |
| `%i`       | Prints an integer in base 10.                                | `int`          |
| `%u`       | Prints an unsigned decimal (base 10) number.                 | `unsigned int` |
| `%x`       | Prints a number in hexadecimal (base 16) lowercase format.   | `unsigned int` |
| `%X`       | Prints a number in hexadecimal (base 16) uppercase format.   | `unsigned int` |
| `%%`       | Prints a percent sign.                                       | none           |

## Resources:

- GNU C language manual
- CodeVault (Youtube channel)
- Prof. MURAKAMI - MATEMÁTICA RAPIDOLA (Youtube channel)
- AI (Claude and Gemini)

The main use of AIs was for questioning why/how things work (base/computer logics) and running the projects faster.