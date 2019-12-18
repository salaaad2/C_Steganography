#include <stega.h>

void	fill_it(int fd, int out, int *tab, int size)
{
	char *nu_line;
	int	 it = 0;

	while (it != size)
	{
		nu_line = ft_itoa(tab[it]);
		it++;
		write(out, nu_line, strlen(nu_line));
		write(out, "  ", 2);
	}
	fill_end(fd, out);
	close(out);
	close(fd);
}

void	fill_end(int fd, int out)
{
	int ret;
	char *line;
	
	write(out, "\n", 1);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		write(out, line, strlen(line));
		write(out, "\n", 1);
	}
}
