#include "../inc/stega.h"

void	read_dc(char *f_search)
{
	int i;
	FILE  *fp, *f2; 
	size_t len, len2;
	char *line_s;
	char *line_t;

	i = 0;
	len = 0;
	len2 = 0;
	fp = fopen(f_search, "r");
	f2 = fopen("img/barbara.ascii.pgm", "r");
	while (i < 5)
	{
		getline(&line_s, &len, fp);
		getline(&line_t, &len2, f2);
		printf("target line :: %ssource line :: %s", line_t, line_s);
		i++;
	}
	get_int_tab(line_s, line_t);
}


static void	get_int_tab(char *line_s, char *line_t)
{
	int i;
	char car_t;
	char car_s;
	int *ret;

	ret = malloc(sizeof(int) * 28);
	i = 0;
	while (car_t != car_s && line_s[i])
	{
		car_t = atoi(line_t + i);
		car_s = atoi(line_s + i);
		printf("%c\n", car_s - car_t);
		i += 3;
	}
}
