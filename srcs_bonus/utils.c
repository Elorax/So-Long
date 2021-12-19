/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 13:45:09 by abiersoh          #+#    #+#             */
/*   Updated: 2021/12/19 14:46:41 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

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
