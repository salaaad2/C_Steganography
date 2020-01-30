#include "../inc/stega.h"

int		main(int ac, char **av)
{
	if (ac != 2)
		return (-1);
	read_dc(av[1]);
}
