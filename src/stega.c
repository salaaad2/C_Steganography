#include <stega.h>

int		count_chars(char *ligne)
{
	int i;
	int charcount;

	i = -1;
	charcount = 0;
	while (ligne[++i])
		if (ligne[i] == ' ' && ligne[i + 1] == ' ')
			charcount++;
	return (charcount + 1);
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
		ret[i] = (hideme[i] + atoi(repl[j]));
		i++;
		j++;
	}
	while (j < size)
	{
		ret[i] = atoi(repl[j]);
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
		while (isdigit(ligne[++i]))
			repl[kze][j++]=ligne[i];
		kze++;
		j = 0;
		i++;
	}
	return (repl);
}

void		stega(char *hideme)
{
	int fd, out, i;
	int *j;
	int size;
	char *ligne;

	i = -1;
	fd =  open("img/barbara.ascii.pgm", O_RDONLY);
	out = open("img/asd.ascii.pgm",  O_RDWR);
	while (++i < 4)
	{
		get_next_line(fd, &ligne);
		write(out, ligne, strlen(ligne));
		write(out, "\n", 1);
	}
	get_next_line(fd, &ligne);
	size = count_chars(ligne);
	j = hide(parse(size, ligne), hideme , size);
	fill_it(fd, out, j, size);
}
