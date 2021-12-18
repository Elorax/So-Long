/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 15:27:18 by abiersoh          #+#    #+#             */
/*   Updated: 2021/12/18 20:40:34 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"


int	ft_move_up(t_vars *vars, int x, int y)
{
	vars->dir = up;
	if (y > 1 && is_accessible(vars->map.map[y - 1][x], vars->map.map[y - 2][x],
		*vars))
	{
		vars->collected += (vars->map.map[y - 1][x] == 'C');
		vars->nb_moves++;
		if (vars->map.map[y - 1][x] == 'E')
			return (0);
		if (vars->map.map[y - 1][x] == 'R' || vars->map.map[y - 1][x] == 'L')
		{
			//ft_mlx_close_escape(vars);
			return (0);
		}
		if (vars->map.map[y - 1][x] == 'X')
			vars->map.map[y - 2][x] = 'X';
		vars->map.map[y][x] = '0';
		vars->map.map[y - 1][x] = 'P';
		printf("Collectibles: %d / %d\n", vars->collected, vars->map.nb_collec);
		printf("Moves: %d\n", vars->nb_moves);
	}
	return (1);
}

int	ft_move_down(t_vars *vars, int x, int y)
{
	vars->dir = down;
	if (y < vars->map.height - 2 && is_accessible(vars->map.map[y + 1][x], vars->map.map[y + 2][x], *vars))
	{
		vars->collected += (vars->map.map[y + 1][x] == 'C');
		vars->nb_moves++;
		if (vars->map.map[y + 1][x] == 'E')
			return (0);
		if (vars->map.map[y + 1][x] == 'R' || vars->map.map[y + 1][x] == 'L')
		{
			//ft_mlx_close_escape(vars);
			return (0);
		}
		if (vars->map.map[y + 1][x] == 'X')
			vars->map.map[y + 2][x] = 'X';
		vars->map.map[y][x] = '0';
		vars->map.map[y + 1][x] = 'P';
		printf("Collectibles: %d / %d\n", vars->collected, vars->map.nb_collec);
		printf("Moves: %d\n", vars->nb_moves);
	}
	return (1);
}

int	ft_move_right(t_vars *vars, int x, int y)
{
	vars->dir = right;
	if (y < vars->map.length - 1 && is_accessible(vars->map.map[y][x + 1], vars->map.map[y][x + 2], *vars))
	{
		vars->collected += (vars->map.map[y][x + 1] == 'C');
		vars->nb_moves++;
		if (vars->map.map[y][x + 1] == 'E')
			return (0);
		if (vars->map.map[y][x + 1] == 'R' || vars->map.map[y][x + 1] == 'L')
		{
			//ft_mlx_close_escape(vars);
			return (0);
		}
		if (vars->map.map[y][x + 1] == 'X')
			vars->map.map[y][x + 2] = 'X';
		vars->map.map[y][x] = '0';
		vars->map.map[y][x + 1] = 'P';
		printf("Collectibles: %d / %d\n", vars->collected, vars->map.nb_collec);
		printf("Moves: %d\n", vars->nb_moves);
	}
	return (1);
}

int	ft_move_left(t_vars *vars, int x, int y)
{
	vars->dir = left;
	if (x > 1 && is_accessible(vars->map.map[y][x - 1], vars->map.map[y][x - 2],
		*vars))
	{
		vars->collected += (vars->map.map[y][x - 1] == 'C');
		vars->nb_moves++;
		if (vars->map.map[y][x - 1] == 'E')
			return (0);
		if (vars->map.map[y][x - 1] == 'R' || vars->map.map[y][x - 1] == 'L')
		{
			//ft_mlx_close_escape(vars);
			return (0);
		}
		if (vars->map.map[y][x - 1] == 'X')
			vars->map.map[y][x - 2] = 'X';
		vars->map.map[y][x] = '0';
		vars->map.map[y][x - 1] = 'P';
		printf("Collectibles: %d / %d\n", vars->collected, vars->map.nb_collec);
		printf("Moves : %d\n", vars->nb_moves);
	}
	return (1);
}

int	ft_move(t_vars *vars, int keycode)
{
	int	x;
	int	y;

	get_coords(vars, &x, &y);
	mlx_string_put(vars->mlx, vars->win, 20, 50 * vars->map.height, 0x00FF0000, "Coucou");
	return (manage_keycode(vars, keycode, x, y));
}
