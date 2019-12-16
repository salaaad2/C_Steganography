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

char *hide(char **repl, char *hideme)
{

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
		//printf("%s \n", repl[kze]);
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
	hide(parse(size, ligne), hideme);
}
