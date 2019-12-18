#include <stega.h>

int		main(int ac, char **av)
{
	if (ac != 2)
		return (-1);
	stega(av[1]);
}
