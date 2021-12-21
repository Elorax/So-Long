/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_horizontal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 15:27:18 by abiersoh          #+#    #+#             */
/*   Updated: 2021/12/21 02:47:07 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	ft_check_right(t_vars *vars,int x, int y)
{
	int	state;

	vars->dir = right;
	state = is_accessible(*vars, x, y, vars->dir);
	vars->nb_moves += (state > 0);
	vars->collected += (vars->map.map[y][x + 1] == 'C');
	if (state == 1)
	{
		if (ft_strchr("RL", vars->map.map[y][x + 1]))
			return (0);
		if (vars->map.map[y][x + 1] == 'E')
			return (-1);
	}
	else if (state == 2)
	{
		vars->map.map[y][x + 2] = 'X' + 10 * (vars->map.map[y][x + 2] == 'B');
		check_doors(vars);
	}
	else if (state == 3)
		vars->map.map[y][x + 2] = (vars->killed++, '#');
	if (state > 0)
		ft_move_right(vars, x, y);
	return (1);
}

void	ft_move_right(t_vars *vars, int x, int y)
{
	int	doors;

	doors = 0;
	if (vars->map.map[y][x] == 'P')
		vars->map.map[y][x] = '0';
	if (vars->map.map[y][x] == 'p')
	{
		vars->map.map[y][x] = 'B';
		doors = 1;
	}
	if (vars->map.map[y][x] == 'q')
		vars->map.map[y][x] = (doors++, 'd');
	if (ft_strchr("0XC", vars->map.map[y][x + 1]))
		vars->map.map[y][x + 1] = 'P';
	if (ft_strchr("Bb", vars->map.map[y][x + 1]))
	{
		vars->map.map[y][x + 1] = 'p';
		doors = 1;
	}
	if (vars->map.map[y][x + 1] == 'd')
		vars->map.map[y][x + 1] = (doors++, 'q');
	if (doors)
		check_doors(vars);
}

int	ft_check_left(t_vars *vars, int x, int y)
{
	int	state;

	vars->dir = left;
	state = is_accessible(*vars, x, y, vars->dir);
	vars->nb_moves += (state > 0);
	vars->collected += (vars->map.map[y][x - 1] == 'C');
	if (state == 1)
	{
		if (ft_strchr("RL", vars->map.map[y][x - 1]))
			return (0);
		if (vars->map.map[y][x - 1] == 'E')
			return (-1);
	}
	else if (state == 2)
	{
		vars->map.map[y][x - 2] = 'X' + 10 * (vars->map.map[y][x - 2] == 'B');
		check_doors(vars);
	}
	else if (state == 3)
		vars->map.map[y][x - 2] = (vars->killed++, '#');
	if (state > 0)
		ft_move_left(vars, x, y);
	return (1);
}

void	ft_move_left(t_vars *vars, int x, int y)
{
	int	doors;

	doors = 0;
	if (vars->map.map[y][x] == 'P')
		vars->map.map[y][x] = '0';
	if (vars->map.map[y][x] == 'p')
	{
		vars->map.map[y][x] = 'B';
		doors = 1;
	}
	if (vars->map.map[y][x] == 'q')
		vars->map.map[y][x] = (doors++, 'd');
	if (ft_strchr("0XC", vars->map.map[y][x - 1]))
		vars->map.map[y][x - 1] = 'P';
	if (ft_strchr("Bb", vars->map.map[y][x - 1]))
	{
		vars->map.map[y][x - 1] = 'p';
		doors = 1;
	}
	if (vars->map.map[y][x - 1] == 'd')
		vars->map.map[y][x - 1] = (doors++, 'q');
	if (doors)
		check_doors(vars);
}