#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
	int fd = open("test.txt", O_RDONLY);
	char *line;
	char *line1;
	char *line2;

	line = get_next_line(fd);
	printf("%s", line);
	line1 = get_next_line(fd);
	printf("%s", line);
	line2 = get_next_line(fd);
	printf("%s", line);
	system("leaks a.out");
	close(fd);
	return (0);
}
