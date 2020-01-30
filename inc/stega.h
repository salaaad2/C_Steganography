#ifndef STEGA_H
# define STEGA_H

#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <inttypes.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 72
#endif

int				get_next_line(int fd, char **line);
char			*ft_nstr(unsigned int s);
int				ft_strlen(char *str);
char			*ft_strjoin_wfree(char *s1, char *s2);
char			*ft_strdup_wstop(char *str);
char			*ft_substr(char *str, unsigned int start, unsigned int len);
int				ft_checkline(char *str);
char			*ft_itoa(long long n);
int				count_chars(char *ligne);
void			stega(char *hideme);
void			read_dc(char *f_search);
void			fill_it(int fd, int out, int *tab, int size);
void			fill_end(int fd, int out);
char			**parse(int nb, char *ligne);
int				*hide(char **repl, char *hideme, int nb);
static void		get_int_tab(char *line_s, char *line_t);
long long		ft_atoi(const char *str);

#endif
