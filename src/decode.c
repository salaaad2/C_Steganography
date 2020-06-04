#include "../inc/stega.h"

void	read_dc(char *f_source, char *f_target)
{
	int i;
	FILE  *fp, *f2; 
	size_t len, len2;
	char *line_s;
	char *line_t;

	i = -1;
	len = 0;
	len2 = 0;
	fp = fopen(f_source, "r");
	f2 = fopen(f_target, "r");
	while (i < 4)
	{
		getline(&line_s, &len, fp);
		getline(&line_t, &len2, f2);
		i++;
	}
	puts("\nREAD OK");
	get_int_tab(line_s, line_t);
}


void	get_int_tab(char *line_s, char *line_t)
{
	int i;
	char car_t;
	char car_s;
	int *ret;

	ret = malloc(sizeof(int) * 28);
	i = 0;
	car_t = 0;
	car_s = 1;
	while (car_t != car_s && line_s[i])
	{
		car_t = atoi(line_t + i);
		car_s = atoi(line_s + i);
		if (isascii(car_s - car_t))
			printf("%c", car_s - car_t);
		i += 3;
	}
	write(1, "\n", 1);
}
