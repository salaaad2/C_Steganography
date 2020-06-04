#include "../inc/stega.h"

int		main(int ac, char **av)
{
	if (ac != 2 && ac != 3)
		printf("wrong number of arguments.....\nUsage : \n./csteg ~message~\n./csteg ~source~ ~target~");
	if (ac == 3)
	{
		printf("source : %s\ntarget : %s", av[1], av[2]);
		read_dc(av[1], av[2]);
		return (1);
	}
	else if (ac == 2)
		stega(av[1]);
	return (0);
}
