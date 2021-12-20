/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adj_accessible.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 14:01:03 by abiersoh          #+#    #+#             */
/*   Updated: 2021/12/20 16:26:03 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"
#define ACCESSIBLE_CASE "0CRLBd"

int	is_adjacent(t_vars *vars, int y, int x)
{
	if (!x || !y || x == vars->map.length - 1 || y == vars->map.height - 1)
		return (0);
	if (ft_strchr("Ppq", vars->map.map[y][x]))
		return (1);
	if (ft_strchr("Ppq", vars->map.map[y - 1][x]))
		return (1);
	if (ft_strchr("Ppq", vars->map.map[y + 1][x]))
		return (1);
	if (ft_strchr("Ppq", vars->map.map[y][x - 1]))
		return (1);
	if (ft_strchr("Ppq", vars->map.map[y][x + 1]))
		return (1);
	return (0);
}

void	get_coords(t_vars *vars, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (vars->map.map[i])
	{
		while (vars->map.map[i][j])
		{
			if (ft_strchr("Ppq", vars->map.map[i][j]))
			{
				*x = j;
				*y = i;
				return ;
			}
			j++;
		}
		i++;
		j = 0;
	}
	*x = 0;
	*y = 0;
}

int	is_accessible(t_vars vars, int x, int y, int dir)
{
	if (dir == up)
	{
		if (ft_strchr(ACCESSIBLE_CASE, vars.map.map[y - 1][x]))
			return (1);
		if (vars.map.map[y - 1][x] == 'E' && vars.collected == vars.map.nb_collec && vars.killed >= vars.to_kill)
			return (1);
		else if (y > 2 && ft_strchr("Xb", vars.map.map[y - 1][x]) && ft_strchr("0B", vars.map.map[y - 2][x]))
			return (2);
		else if (y > 2 && ft_strchr("Xb", vars.map.map[y - 1][x]) && ft_strchr("RL", vars.map.map[y - 2][x]) && ft_strchr("bDX#1", vars.map.map[y - 3][x]))
			return (3);
	}
	else if (dir == down)
	{
		if (ft_strchr(ACCESSIBLE_CASE, vars.map.map[y + 1][x]))
			return (1);
		if (vars.map.map[y + 1][x] == 'E' && vars.collected == vars.map.nb_collec && vars.killed >= vars.to_kill)
			return (1);
		else if (y < vars.map.height - 2 && ft_strchr("Xb", vars.map.map[y + 1][x]) && ft_strchr("0B", vars.map.map[y + 2][x]))
			return (2);
		else if (y < vars.map.height - 3 && ft_strchr("Xb", vars.map.map[y + 1][x]) && ft_strchr("RL", vars.map.map[y + 2][x]) && ft_strchr("bXD#1", vars.map.map[y + 3][x]))
			return (3);

	}
	else if (dir == right)
	{
		if (ft_strchr(ACCESSIBLE_CASE, vars.map.map[y][x + 1]))
			return (1);
		if (vars.map.map[y][x + 1] == 'E' && vars.collected == vars.map.nb_collec && vars.killed >= vars.to_kill)
			return (1);
		else if (x < vars.map.length - 2 && ft_strchr("Xb", vars.map.map[y][x + 1]) && ft_strchr("0B", vars.map.map[y][x + 2]))
			return (2);
		else if (x < vars.map.length - 3 && ft_strchr("Xb", vars.map.map[y][x + 1]) && ft_strchr("RL", vars.map.map[y][x + 2]) && ft_strchr("bX#1D", vars.map.map[y][x + 3]))
			return (3);
	}
	else if (dir == left)
	{
		if (ft_strchr(ACCESSIBLE_CASE, vars.map.map[y][x - 1]))
			return (1);
		if (vars.map.map[y][x - 1] == 'E' && vars.collected == vars.map.nb_collec && vars.killed >= vars.to_kill)
			return (1);
		else if (x > 2 && ft_strchr("Xb", vars.map.map[y][x - 1]) && ft_strchr("0B", vars.map.map[y][x - 2]))
			return (2);
		else if (x > 2 && ft_strchr("Xb", vars.map.map[y][x - 1]) && ft_strchr("RL", vars.map.map[y][x - 2]) && ft_strchr("bXD#1", vars.map.map[y][x - 3]))
			return (3);
	}
	return (0);
}
/*
int	is_accessible(char c, char c2, t_vars vars)
{
	if (c == '1' || (c == 'E' && vars.collected != vars.map.nb_collec)
		|| (c == 'X' && c2 != '0'))
		return (0);
	return (1);
}*/
