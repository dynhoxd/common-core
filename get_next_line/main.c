#include "get_next_line.h"
#include <fcntl.h>
#include "stdio.h"

int	main(void)
{
	int	fd = open("exemp.txt", O_RDONLY | O_CREAT);
	char *line;
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	return 0;
}
