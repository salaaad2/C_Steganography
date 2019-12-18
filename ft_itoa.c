/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fmoenne- <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/14 15:35:02 by fmoenne-     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/07 04:22:29 by fmoenne-    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "stega.h"

static char	*ft_revert(char *str)
{
	char	*tmp;
	int		i;
	int		j;
	int		size;

	size = strlen(str);
	tmp = malloc(strlen(str) + 1);
	j = 0;
	i = (strlen(str) - 1);
	if (str[0] == '-')
	{
		tmp[0] = '-';
		j++;
	}
	while (j < size)
	{
		tmp[j] = str[i];
		i--;
		j++;
	}
	str = tmp;
	return (str);
}

static char	*algo(long long nbr, long long i, char *new)
{
	if (nbr <= 0)
		i++;
	if (nbr < 0)
	{
		new[i - 1] = '-';
		nbr = -nbr;
	}
	while (nbr != 0)
	{
		new[i] = nbr % 10 + '0';
		i++;
		nbr /= 10;
	}
	new[i] = '\0';
	return (ft_revert(new));
}

static char	*ft_zeroes(long long n)
{
	char *new;

	if (!(new = malloc(sizeof(char) * 2)))
		return (0);
	new[n] = '0';
	new[n + 1] = '\0';
	return (new);
}

char		*ft_itoa(long long n)
{
	char		*new;
	long long	tmp;
	int			size;

	tmp = n;
	size = 0;
	if (n == 0)
		return (ft_zeroes(n));
	if (tmp < 0)
	{
		size++;
		tmp = -tmp;
	}
	while (tmp != 0)
	{
		tmp = tmp / 10;
		size++;
	}
	if (!(new = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	return (algo((long)n, 0, new));
}
