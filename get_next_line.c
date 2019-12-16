/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fmoenne- <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/25 17:46:19 by fmoenne-     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/13 20:45:22 by fmoenne-    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_checkline(char *str)
{
	int it;

	it = 0;
	while (str && str[it])
	{
		if (str[it] == '\n')
			return (1);
		it++;
	}
	return (0);
}

int		ft_getstop(char *str)
{
	int stop;

	stop = 0;
	while (str[stop] != '\n' && str[stop])
		stop++;
	return (stop);
}

int		ft_errcheck(int fd, char **line, char **result)
{
	if (*result == NULL)
		*result = ft_nstr(0);
	if (fd < 0 || !line)
	{
		free(*result);
		return (-1);
	}
	return (1);
}

int		ft_fill_line(int fd, char **result)
{
	char	*retline;
	char	*tmp;
	int		ret;

	if (!(retline = (char*)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (0);
	ret = 1;
	while (!(ft_checkline(*result)) &&
			(ret = read(fd, retline, BUFFER_SIZE)) > 0)
	{
		retline[ret] = '\0';
		tmp = *result;
		*result = ft_strjoin_wfree(tmp, retline);
		free(tmp);
	}
	if (ret == -1)
	{
		free(*result);
		free(retline);
		return (-1);
	}
	free(retline);
	return (ret);
}

int		get_next_line(int fd, char **line)
{
	char		*tmp;
	static char	*result;
	long		i;
	int			ret;

	if (ft_errcheck(fd, line, &result) != 1)
		return (-1);
	ret = ft_fill_line(fd, &result);
	if (ret < 0)
		return (-1);
	i = ft_getstop(result);
	(*line = ft_substr(result, 0, i));
	tmp = result;
	if (tmp[0] != '\0' && tmp)
		result = ft_strdup_wstop(tmp + i + (tmp[i] == '\n'));
	if (ret == 0 && ((result == NULL ||
					result[0] == '\0') || !ft_checkline(tmp)))
	{
		i = tmp[i];
		free(tmp);
		tmp = NULL;
		return (i == '\n');
	}
	free(tmp);
	return (1);
}
