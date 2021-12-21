/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_attack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 18:21:33 by abiersoh          #+#    #+#             */
/*   Updated: 2021/12/21 03:29:57 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	ft_attack_up(t_vars *vars, int x, int y)
{
	if (vars->map.map[y - 1][x] == 'R' || vars->map.map[y - 1][x] == 'L')
	{
		vars->map.map[y - 1][x] = '0';
		ft_put_img(vars, vars->frames % 4, y - 1, x);
		return (1);
	}
	return (0);
}

int	ft_attack_right(t_vars *vars, int x, int y)
{
	if (vars->map.map[y][x + 1] == 'R' || vars->map.map[y][x + 1] == 'L')
	{
		vars->map.map[y][x + 1] = '0';
		ft_put_img(vars, vars->frames % 4, y, x + 1);
		return (1);
	}
	return (0);
}

int	ft_attack_left(t_vars *vars, int x, int y)
{
	if (vars->map.map[y][x - 1] == 'R' || vars->map.map[y][x - 1] == 'L')
	{
		vars->map.map[y][x - 1] = '0';
		ft_put_img(vars, vars->frames % 4, y, x - 1);
		return (1);
	}
	return (0);
}

int	ft_attack_down(t_vars *vars, int x, int y)
{
	if (vars->map.map[y + 1][x] == 'R' || vars->map.map[y + 1][x] == 'L')
	{
		vars->map.map[y + 1][x] = '0';
		ft_put_img(vars, vars->frames % 4, y + 1, x);
		return (1);
	}
	return (0);
}

int	ft_attack(t_vars *vars)
{
	int	x;
	int	y;

	return (0);
	get_coords(vars, &x, &y);
	if (vars->dir == up)
		return (ft_attack_up(vars, x, y));
	else if (vars->dir == right)
		return (ft_attack_right(vars, x, y));
	else if (vars->dir == left)
		return (ft_attack_left(vars, x, y));
	else if (vars->dir == down)
		return (ft_attack_down(vars, x, y));
	else
		return (-1);
}
