#include "get_next_line.h"

int main(void)
{
	char	*line;
	int fd = open("test.txt", O_CREAT | O_RDWR | O_TRUNC , 0644);
	dprintf(fd, "hello\nTaha\nnahid\nbruuuuuuuuuuh\n");
	lseek(fd, 0, SEEK_SET);
	for (int i = 0; i < 4; i++)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
}
