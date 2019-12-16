/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fmoenne- <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/23 16:26:54 by fmoenne-     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/05 15:23:22 by fmoenne-    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

int		get_next_line(int fd, char **line);
char	*ft_nstr(unsigned int s);
int		ft_strlen(char *str);
char	*ft_strjoin_wfree(char *s1, char *s2);
char	*ft_strdup_wstop(char *str);
char	*ft_substr(char *str, unsigned int start, unsigned int len);
int		ft_checkline(char *str);

#endif
