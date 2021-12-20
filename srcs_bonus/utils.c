/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 13:45:09 by abiersoh          #+#    #+#             */
/*   Updated: 2021/12/20 23:42:16 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"


char	*ft_itoa(int n)
{
	int				i;
	char			*dest;
	unsigned int	cpy;

	i = ((cpy = (n * (1 - (2 * (n < 0))))), (n < 0));
	while (cpy > 9)
		cpy = (i++, cpy / 10);
	dest = malloc(i + 2);
	if (!dest)
		return (NULL);
	dest[i + 1] = 0;
	dest[0] = ((cpy = (n * (1 - (2 *(n < 0))))), '-' + 3 * (n == 0));
	while (cpy > 0)
		cpy = ((dest[i--] = (cpy % 10) + '0'), cpy /10);
	return (dest);
}

int	ft_atoi(char *s)
{
	int	ret;

	ret = 0;
	if (!s)
		return (0);
	while (*s && *s <= '9' && *s >= '0')
	{
		ret = (ret * 10) + (*s - '0');
		s++;
	}
	return (ret);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *str, char c)
{
	while (*str)
		if (*str++ == c)
			return (str - 1);
	return (NULL);
}

void	ft_cswitch(char *a, char *b)
{
	char	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	char	*cpy;
	char	*cpys1;

	cpys1 = s1;
	dest = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!dest)
		return (free(s1), NULL);
	cpy = dest;
	while (*s1)
	{
		*dest++ = *s1++;
	}
	while (*s2)
	{
		*dest++ = *s2++;
	}
	*dest = 0;
	free(cpys1);
	return (cpy);
}

char	*ft_strjoin2(char *s1, char *s2, int a, int b)
{
	char	*dest;
	char	*cpy;
	int		i;

	i = 0;
	dest = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!dest)
		return (NULL);
	cpy = dest;
	while (s1[i])
		*dest++ = s1[i++];
	i = 0;
	while (s2[i])
		*dest++ = s2[i++];
	*dest = 0;
	if (a)
		free(s1);
	if (b)
		free(s2);
	return (cpy);
}

char	*ft_strdup(char *s)
{
	char	*dest;
	int		i;

	i = -1;
	dest = malloc(ft_strlen(s) + 1);
	if (!dest)
		return (NULL);
	while (s[++i])
	{
		dest[i] = s[i];
	}
	dest[i] = 0;
	return (dest);
}

char	*ft_so_long_strndup(char *s, int n)
{
	char	*dest;
	int	i;

	i = -1;
	dest = malloc(n + 1);
	if (!dest)
		return (NULL);
	while (s[++i] && i < n)
	{
		dest[i] = s[i];
	}
	dest[i] = 0;
	return (dest);
}
