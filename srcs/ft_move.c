/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 15:27:18 by abiersoh          #+#    #+#             */
/*   Updated: 2021/12/18 15:46:27 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	manage_keycode(t_vars *vars, int keycode, int x, int y)
{
	if (keycode == W_KEY || keycode == UP_KEY || keycode == Z_KEY)
		return (ft_move_up(vars, x, y));
	else if ((keycode == S_KEY || keycode == DOWN_KEY))
		return (ft_move_down(vars, x, y));
	else if ((keycode == D_KEY || keycode == RIGHT_KEY))
		return (ft_move_right(vars, x, y));
	else if ((keycode == A_KEY || keycode == Q_KEY || keycode == LEFT_KEY))
		return (ft_move_left(vars, x, y));
	return (1);
}

int	ft_move_up(t_vars *vars, int x, int y)
{
	vars->dir = UP;
	if (is_accessible(vars->map.map[y - 1][x], *vars))
	{
		vars->collected += (vars->map.map[y - 1][x] == 'C');
		vars->nb_moves++;
		if (vars->map.map[y - 1][x] == 'E')
			return (0);
		vars->map.map[y][x] = '0';
		vars->map.map[y - 1][x] = 'P';
		printf("Collectibles: %d / %d\n", vars->collected, vars->map.nb_collec);
		printf("Moves: %d\n", vars->nb_moves);
	}
	return (1);
}

int	ft_move_down(t_vars *vars, int x, int y)
{
	vars->dir = DOWN;
	if (is_accessible(vars->map.map[y + 1][x], *vars))
	{
		vars->collected += (vars->map.map[y + 1][x] == 'C');
		vars->nb_moves++;
		if (vars->map.map[y + 1][x] == 'E')
			return (0);
		vars->map.map[y][x] = '0';
		vars->map.map[y + 1][x] = 'P';
		printf("Collectibles: %d / %d\n", vars->collected, vars->map.nb_collec);
		printf("Moves: %d\n", vars->nb_moves);
	}
	return (1);
}

int	ft_move_right(t_vars *vars, int x, int y)
{
	vars->dir = RIGHT;
	if (is_accessible(vars->map.map[y][x + 1], *vars))
	{
		vars->collected += (vars->map.map[y][x + 1] == 'C');
		vars->nb_moves++;
		if (vars->map.map[y][x + 1] == 'E')
			return (0);
		vars->map.map[y][x] = '0';
		vars->map.map[y][x + 1] = 'P';
		printf("Collectibles: %d / %d\n", vars->collected, vars->map.nb_collec);
		printf("Moves: %d\n", vars->nb_moves);
	}
	return (1);
}

int	ft_move_left(t_vars *vars, int x, int y)
{
	vars->dir = LEFT;
	if (is_accessible(vars->map.map[y][x - 1], *vars))
	{
		vars->collected += (vars->map.map[y][x - 1] == 'C');
		vars->nb_moves++;
		if (vars->map.map[y][x - 1] == 'E')
			return (0);
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
	return(manage_keycode(vars, keycode, x, y));
}
