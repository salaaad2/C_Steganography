/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line_utils.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fmoenne- <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/25 17:51:13 by fmoenne-     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/13 20:25:02 by fmoenne-    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_nstr(unsigned int s)
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (!(str = malloc(sizeof(char) * (s + 1))))
		return (NULL);
	while (i < s)
	{
		str[i] = '\0';
		i++;
	}
	str[i] = '\0';
	return (str);
}

int		ft_strlen(char *str)
{
	int it;

	it = 0;
	while (str && str[it])
		it++;
	return (it);
}

char	*ft_strjoin_wfree(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;
	int		size;

	if (!s1 || !s2)
		return (NULL);
	size = (ft_strlen(s1) + ft_strlen(s2));
	if (!(str = ft_nstr(size)))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strdup_wstop(char *src)
{
	char	*ab;
	int		i;
	int		l;

	i = 0;
	l = 0;

	if (!src || src[0] == '\0')
		return (NULL);
	while (src[l])
		l++;
	if (!(ab = (char*)malloc(sizeof(char) * (l + 1))))
		return (NULL);
	while (src[i])
	{
		ab[i] = src[i];
		i++;
	}
	ab[i] = '\0';
	return (ab);
}

char	*ft_substr(char *str, unsigned int start, unsigned int len)
{
	char			*s;
	unsigned int	i;

	i = 0;
	if (!str)
	{
		free(str);
		return (NULL);
	}
	if (!(s = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (str[i] && i < len)
	{
		s[i] = str[start + i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
