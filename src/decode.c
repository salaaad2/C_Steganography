#include <stega.h>

void	decode(char *f_search)
{
	int i;
FILE  *fd, *f2; 
	size_t len, len2;
	char *line_s;
	char *line_d;

	i = 0;
	fd = fopen(f_search, "r");
	f2 = fopen("img/barbara.ascii.pgm", "r");
	while (i < 5)
	{
		getline(&line_s, &len, fd);
		printf("%dasd :  line :: %s\n",i, line_s);
		i++;
	}
	printf("4th line :: %s\n", line_s);
	
}
