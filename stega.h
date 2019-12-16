#ifndef STEGA_H
# define STEGA_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <inttypes.h>

int				ft_isdigit(int c);
int				count_chars(char *ligne);
void			stega(char *hideme);
char			**parse(int nb, char *ligne);
char			*hide(char **repl, char *hideme);
long long		ft_atoi(const char *str);

#endif
