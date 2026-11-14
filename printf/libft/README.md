*This project has been created as part of the 42 curriculum by jabernar.*

# Libft

## Description:

This is my first project of the 42 School curriculum. Its goals are the
understanding of some functions, C syntaxs, memory management, headers and Makefile, and their logics, while implementing a static
C library to reuse in later projects.


## Instrutions:

### 1. Adding this lib to your project:

- `git submodule add git@vogsphere.42porto.com:vogsphere/intra-uuid-890e0874-afb0-43b2-b3f3-417cc4ec673e-7785059-jabernar libft` to create a submodule (recommended).

or

- `git clone git@vogsphere.42porto.com:vogsphere/intra-uuid-890e0874-afb0-43b2-b3f3-417cc4ec673e-7785059-jabernar libft` to clone the repository.

### 2. Creating/compiling or updating the local library:

- Use the following commands on the terminal.

- `make` - to create or update the static library.

- `make bonus` - To create or update the library adding the **linked list** (bonus) functions. (this cmd alone is enough to use all the funcs)

- `make clean` -  to delete all the .o files used to create the library.

- `make fclean` - to delete all the .o files and the library.

- `make re` - to delete all .o files and the library, and recreate them.

### 3. Including the lib to your files:

On the files you're in need to use this lib, you must `#include "libft/libft.h"`

### 4. Compiling your code

Use the following flags to link everything together:  
`-Llibft -lft -Ilibft`  

where:  
"-I" instruct the system where to find the header file  
"-L" instruct the system where to find the libft.a  
"-l" instruct the system which lib to link (excude the lib of its name).


## Functions on this library:

The library is split into three parts.

**Part 1 - Libc functions** (same behavior as the originals, with an `ft_` prefix):

| Category | Functions |
|---|---|
| Character checks | `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint` |
| Character conversion | `ft_toupper`, `ft_tolower` |
| Strings | `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strdup` |
| Memory | `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc` |
| Conversion | `ft_atoi` |

**Part 2 - Additional functions** (not in libc, or in a different form):

| Function | Description |
|---|---|
| `ft_substr` | Returns a new string extracted from `s`, starting at index `start`, with at most `len` characters. |
| `ft_strjoin` | Returns a new string resulting from the concatenation of `s1` and `s2`. |
| `ft_strtrim` | Returns a copy of `s1` without the characters in `set` at the beginning and at the end. |
| `ft_split` | Splits a string by a delimiter character and returns a NULL-terminated array of new strings. |
| `ft_itoa` | Converts an integer to a newly allocated string (handles `INT_MIN`). |
| `ft_strmapi` | Applies `f(index, char)` to each character and returns a new string with the results. |
| `ft_striteri` | Applies `f(index, &char)` to each character, modifying the string in place. |
| `ft_putchar_fd` | Writes a character to the given file descriptor. |
| `ft_putstr_fd` | Writes a string to the given file descriptor. |
| `ft_putendl_fd` | Writes a string followed by a newline to the given file descriptor. |
| `ft_putnbr_fd` | Writes an integer to the given file descriptor. |

**Bonus part - Linked lists**, using the following structure:

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}
```
| Function | Description |
|---|---|
| `ft_lstnew` | Creates a new node with the given content. |
| `ft_lstadd_front` | Adds a node at the beginning of the list. |
| `ft_lstsize` | Counts the nodes of the list. |
| `ft_lstlast` | Returns the last node of the list. |
| `ft_lstadd_back` | Adds a node at the end of the list. |
| `ft_lstdelone` | Frees one node's content (with del) and the node itself. |
| `ft_lstclear` | Deletes and frees a node and all its successors, then sets the list pointer to NULL. |
| `ft_lstiter` | Applies a function to the content of each node. |
| `ft_lstmap` | Creates a new list by applying a function to each node's content; cleans up if an allocation fails. |


## Resources:

- Project subject .pdf
- C language manual (man)
- Web searches (most used websites: coddykit.com and reddit.com)
- AI (Claude and Gemini)

The main use of AIs was for questing why/how things work (base/computer logics) and running the projects faster.