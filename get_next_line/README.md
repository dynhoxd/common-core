*This project has been created as part of the 42 curriculum by jabernar.*

# <center>get_next_line</center>

## Description:

The goal of this project is getting a line a from one (regular) or multiples (bonus) file, passing their 
file descriptors (use the funciton 'read' <fcntl.h> to get them) or from the stdin.
A line is delimited by the use of a line breaker '\n' or the end of the file/stdin text.
All memory allocated on the heap is freed, most by the end of the function,
some at the end of the file and at the of the program.

PS.: on most of programs/files, the line breaker character is not visible, we normally
know of its presence due to the format of the text.

The main difference between the mandatory and the bonus part is: in the bonus an array of strings is used
to maintain the information (static variable) save during the execution of the program, instead of a
simples string.

### Functions on the project:

- `char	*get_next_line(int fd)` - the main function.

- `int		read_and_join(char **rest, int fd)` - creates the 'rest' (static variable)
which holds the caracter read, as a string.

- `char	*ft_get_line(char *rest)` - creates a varible, memory allocated, that contains
the current line.

- `void	new_rest(char **rest)` - if necessary, creates an updated version of the rest,
containing the caracters that weren't set to the current line.

- `size_t	ft_strlen(const char *s)` - counts the string length.

- `char	*ft_strchr(char *s, int c)` - this version, looks for the line breaker position.

- `char	*ft_strjoin(char *s1, char *s2)` - join 2 strings into one.

- `char	*ft_substr(const char *s, unsigned int start, size_t len)` - gets a string
which is a substring of another(*s).

## Instructions:

The funciton **get_next_line** requires the file descriptor as argument (int fd), but
this code is designed to deal with a diffent BUFFER_SIZE specified on the compilation
command (for that, use the flag '-D BUFFER_SIZE=<number>'), if not this way specified,
it'll be set as 1024 (bytes). The buffer size is delimiter of how many characters will
be read at a time. On success, a string(char *) will be returned.

Exemple: `cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c`
```
#include <fcntl.h>
#include "stdio.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("exemp.txt", O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	return (0);
}
```

## Resources:

- GNU C language manual
- 42 Collegues
- AI (Claude and Gemini)

The main use of AIs was for questioning why/how things work (base/computer logics).