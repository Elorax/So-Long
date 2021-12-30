/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pat_patrouille_vertical.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 20:57:23 by abiersoh          #+#    #+#             */
/*   Updated: 2021/12/30 23:32:52 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	ft_pat_up(t_vars *vars, int j, int i)
{
	char	c;

	c = vars->map.map[j - 1][i];
	if (c == '0')
	{
		vars->map.map[j][i] = '0' + 35 * (vars->map.map[j][i] == 'u');
		vars->map.map[j - 1][i] = 'U';
	}
	else if (c == 'S')
	{
		vars->map.map[j][i] = '0' + 35 * (vars->map.map[j][i] == 'u');
		vars->map.map[j - 1][i] = 'u';
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
		vars->map.map[j][i] = 'V' + 32 * (ft_strchr("rlvu", vars->map.map[j][i]) != NULL);
	return (0);
}

int	ft_pat_down(t_vars *vars, int *j, int i)
{
	char	c;

	c = vars->map.map[*j + 1][i];
	if (c == '0')
	{
		vars->map.map[*j][i] = '0' + 35 * (vars->map.map[*j][i] == 'v');
		vars->map.map[*j + 1][i] = 'V';
		(*j)++;
	}
	else if (c == 'S')
	{
		vars->map.map[*j][i] = '0' + 35 * (vars->map.map[*j][i] == 'v');
		vars->map.map[*j + 1][i] = 'v';
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
		vars->map.map[*j][i] = 'U' + 32 * (ft_strchr("rlvu", vars->map.map[*j][i]) != NULL);
	return (0);
}

int	ft_pat_patrouille_vertical(t_vars *vars)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < vars->map.length)
	{
		while (j < vars->map.height)
		{
			if (ft_strchr("Uu", vars->map.map[j][i]))
			{
				if (ft_pat_up(vars, j, i) == -1)
					return (-1);
			}
			else if (ft_strchr("Vv", vars->map.map[j][i]))
				if (ft_pat_down(vars, &j, i) == -1)
					return (-1);
			j++;
		}
		i++;
		j = 0;
	}
	ft_update_full_map(vars);
	vars->switch_dir_mobs && ft_swap_dir(vars);
	vars->switch_dir_mobs = 0;
	return (0);
}
