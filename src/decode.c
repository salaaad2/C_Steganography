#include <stega.h>

void	decode(char *f_search)
{
	int fd, f2;
	char *line_s;
	//char *line_d;

	fd = open(f_search, 0);
	f2 = open("img/barbara.ascii.pgm",  0);
	while (!strcmp(line_s, "AsD"))
	{
		get_next_line(fd, &line_s);
	}
	printf("%s\n", line_s);
}
