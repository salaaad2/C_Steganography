#ifndef STEGA_H
# define STEGA_H

#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <inttypes.h>
#include "get_next_line.h"

char			*ft_itoa(long long n);
int				count_chars(char *ligne);
void			stega(char *hideme);
void			fill_it(int fd, int out, int *tab, int size);
void			fill_end(int fd, int out);
char			**parse(int nb, char *ligne);
int				*hide(char **repl, char *hideme, int nb);
long long		ft_atoi(const char *str);

#endif
