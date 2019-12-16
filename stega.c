#include "stega.h"
#include "get_next_line.h"

int		count_chars(char *ligne)
{
	int i;
	int j;
	int charcount;

	i = -1;
	charcount = 0;
	while (ligne[++i])
		if (ligne[i] == ' ' && ligne[i + 1] == ' ')
			charcount++;
	return (charcount);
}

int *hide(char **repl, char *hideme, int size)
{
	int i, j;
	int *ret;

	ret = malloc(sizeof(int) * size);
	i = 0;
	j = 0;
	while (j < size && hideme[i])
	{
		ret[i] = (hideme[i] + ft_atoi(repl[j]));
		printf("%d %s\n", ret[i], repl[j]);
		i++;
		j++;
	}
	while (j < size)
	{
		ret[i] = ft_atoi(repl[j]);
		printf("%d\n", ret[i]);
		i++;
		j++;
	}
	return (ret);
}

char	**parse(int nb, char *ligne)
{
	char **repl;
	int i, j, kze;

	i = -1;
	j = 0;
	kze = 0;
	repl = malloc(sizeof(char*) * nb);
	while (++i <= nb)
		repl[i] = malloc(4);
	i = -1;
	while (kze <= nb)
	{
		while (ft_isdigit(ligne[++i]))
			repl[kze][j++]=ligne[i];
		kze++;
		j = 0;
		i++;
	}
	return (repl);
}

void		stega(char *hideme)
{
	int fd;
	int i;
	int max;
	int size;
	char *ligne;

	i = -1;
	fd = open("barbara.ascii.pgm", 0);
	while (++i < 4)
		get_next_line(fd, &ligne);
	max = ft_atoi(ligne);
	get_next_line(fd, &ligne);
	printf("max :: %d ligne :: %s\n", max, ligne);
	size = count_chars(ligne);
	printf("%d\n", size);
	hide(parse(size, ligne), hideme , size);
}
