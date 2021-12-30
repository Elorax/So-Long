/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pat_patrouille.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 17:04:16 by abiersoh          #+#    #+#             */
/*   Updated: 2021/12/30 23:33:24 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"


int	ft_swap_dir(t_vars *vars)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
		while (vars->map.map[++i])
		{
			while (vars->map.map[i][++j])
			{
				if (vars->map.map[i][j] == 'R')
					vars->map.map[i][j] = 'V';
				else if (vars->map.map[i][j] == 'V')
					vars->map.map[i][j] = 'L';
				else if (vars->map.map[i][j] == 'L')
					vars->map.map[i][j] = 'U';
				else if (vars->map.map[i][j] == 'U')
					vars->map.map[i][j] = 'R';
				else if (vars->map.map[i][j] == 'r')
					vars->map.map[i][j] = 'v';
				else if (vars->map.map[i][j] == 'v')
					vars->map.map[i][j] = 'l';
				else if (vars->map.map[i][j] == 'l')
					vars->map.map[i][j] = 'u';
				else if (vars->map.map[i][j] == 'u')
					vars->map.map[i][j] = 'r';
			}
			j = -1;
		}
	return (1);
}

int	ft_pat_right(t_vars *vars, int i, int *j)
{
	char	c;

	c = vars->map.map[i][*j + 1];
	if (c == '0')
	{
		vars->map.map[i][*j] = '0' + 35 * (vars->map.map[i][*j] == 'r');
		vars->map.map[i][*j + 1] = 'R';
		(*j)++;
	}
	else if (c == 'S')
	{
		vars->map.map[i][*j] = '0' + 35 * (vars->map.map[i][*j] == 'r');
		vars->map.map[i][*j + 1] = 'r';
		vars->switch_dir_mobs++;
		(*j)++;
	}
	else if (ft_strchr("Ps", c) != NULL && !vars->koko)
	{
		if (vars->life-- >= 0)
			ft_mlx_restart(vars);
		else
			ft_mlx_close_game(vars);
		return (-1);
	}
	else
		vars->map.map[i][*j] = 'L' + 32 * (ft_strchr("rlvu", vars->map.map[i][*j]) != NULL);
	return (0);
}

int	ft_pat_left(t_vars *vars, int i, int j)
{
	char	c;

	c = vars->map.map[i][j - 1];
	if (c == '0')
	{
		vars->map.map[i][j] = '0' + 35 * (vars->map.map[i][j] == 'l');
		vars->map.map[i][j - 1] = 'L';
	}
	else if (c == 'S')
	{
		vars->map.map[i][j] = '0' + 35 * (vars->map.map[i][j] == 'l');
		vars->map.map[i][j - 1] = 'l';
		vars->switch_dir_mobs++;
	}
	else if (ft_strchr("Ps", c) != NULL && !vars->koko)
	{
		if (vars->life-- >= 0)
			ft_mlx_restart(vars);
		else
			ft_mlx_close_game(vars);
		return (-1);
	}
	else
		vars->map.map[i][j] = 'R' + 32 * (ft_strchr("rlvu", vars->map.map[i][j]) != NULL);
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
			if (ft_strchr("Rr", vars->map.map[i][j]))
			{
				if (ft_pat_right(vars, i, &j) == -1)
					return (-1);
			}
			else if (ft_strchr("Ll", vars->map.map[i][j]))
				if (ft_pat_left(vars, i, j) == -1)
					return (-1);
			j++;
		}
		i++;
		j = 0;
	}
	return(ft_pat_patrouille_vertical(vars));
}
