/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pat_patrouille.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 17:04:16 by abiersoh          #+#    #+#             */
/*   Updated: 2021/12/21 06:27:52 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	ft_pat_right(t_vars *vars, int i, int *j)
{
	char	c;

	c = vars->map.map[i][*j + 1];
	if (c == '0')
	{
		vars->map.map[i][*j] = '0';
		vars->map.map[i][*j + 1] = 'R';
//		ft_put_img(vars, 14, i, *j + 1);
//		ft_put_img(vars, 0, i, *j);
		(*j)++;
	}
	else if (c == 'P')
	{
		ft_mlx_restart(vars);
		return (-1);
	}
	else
	{
		vars->map.map[i][*j] = 'L';
//		ft_put_img(vars, 15, i, *j);
	}
	return (0);
}

int	ft_pat_left(t_vars *vars, int i, int j)
{
	char	c;

	c = vars->map.map[i][j - 1];
	if (c == '0')
	{
		vars->map.map[i][j] = '0';
		vars->map.map[i][j - 1] = 'L';
//		ft_put_img(vars, 15, i, j - 1);
//		ft_put_img(vars, 0, i, j);
	}
	else if (c == 'P')
	{
		ft_mlx_restart(vars);
		return (-1);
	}
	else
	{
		vars->map.map[i][j] = 'R';
//		ft_put_img(vars, 14, i, j);
	}
	return (0);
}

int	ft_pat_patrouille(t_vars *vars)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (vars->map.map[i])
	{
		while (vars->map.map[i][j])
		{
			if (vars->map.map[i][j] == 'R')
			{
				if (ft_pat_right(vars, i, &j) == -1)
					return (-1);
			}
			else if (vars->map.map[i][j] == 'L')
				if (ft_pat_left(vars, i, j) == -1)
					return (-1);
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}
