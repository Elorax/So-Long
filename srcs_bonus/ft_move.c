/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 15:27:18 by abiersoh          #+#    #+#             */
/*   Updated: 2021/12/18 22:31:55 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"


int	ft_move_up(t_vars *vars, int x, int y)
{
	int	state;

	vars->dir = up;
	state = is_accessible(*vars, x, y, vars->dir);
	vars->nb_moves += (state > 0);
	vars->collected += (vars->map.map[y - 1][x] == 'C');
	if (state == 1)
	{
		if (ft_strchr("ERL", vars->map.map[y - 1][x]))
			return (0);
	}
	else if (state == 2)
		vars->map.map[y - 2][x] = 'X';
	else if (state == 3)
		vars->map.map[y - 2][x] = '#';
	if (state > 0)
	{
		vars->map.map[y][x] = '0';
		vars->map.map[y - 1][x] = 'P';
	}
	printf("Collectibles: %d / %d\n", vars->collected, vars->map.nb_collec);
	printf("Moves: %d\n", vars->nb_moves);
	return(1);
}

int	ft_move_down(t_vars *vars, int x, int y)
{
	int	state;

	vars->dir = down;
	state = is_accessible(*vars, x, y, vars->dir);
	vars->nb_moves += (state > 0);
	vars->collected += (vars->map.map[y + 1][x] == 'C');
	if (state == 1)
	{
		if (ft_strchr("ERL", vars->map.map[y + 1][x]))
			return (0);
	}
	else if (state == 2)
		vars->map.map[y + 2][x] = 'X';
	else if (state == 3)
		vars->map.map[y + 2][x] = '#';
	if (state > 0)
	{
		vars->map.map[y][x] = '0';
		vars->map.map[y + 1][x] = 'P';
	}
	printf("Collectibles: %d / %d\n", vars->collected, vars->map.nb_collec);
	printf("Moves: %d\n", vars->nb_moves);
	return(1);
}
int	ft_move_right(t_vars *vars, int x, int y)
{
	int	state;

	vars->dir = right;
	state = is_accessible(*vars, x, y, vars->dir);
	vars->nb_moves += (state > 0);
	vars->collected += (vars->map.map[y][x + 1] == 'C');
	if (state == 1)
	{
		if (ft_strchr("ERL", vars->map.map[y][x + 1]))
			return (0);
	}
	else if (state == 2)
		vars->map.map[y][x + 2] = 'X';
	else if (state == 3)
		vars->map.map[y][x + 2] = '#';
	if (state > 0)
	{
		vars->map.map[y][x] = '0';
		vars->map.map[y][x + 1] = 'P';
	}
	printf("Collectibles: %d / %d\n", vars->collected, vars->map.nb_collec);
	printf("Moves: %d\n", vars->nb_moves);
	return(1);
}
int	ft_move_left(t_vars *vars, int x, int y)
{
	int	state;

	vars->dir = left;
	state = is_accessible(*vars, x, y, vars->dir);
	vars->nb_moves += (state > 0);
	vars->collected += (vars->map.map[y][x - 1] == 'C');
	if (state == 1)
	{
		if (ft_strchr("ERL", vars->map.map[y][x - 1]))
			return (0);
	}
	else if (state == 2)
		vars->map.map[y][x - 2] = 'X';
	else if (state == 3)
		vars->map.map[y][x - 2] = '#';
	if (state > 0)
	{
		vars->map.map[y][x] = '0';
		vars->map.map[y][x - 1] = 'P';
	}
	printf("Collectibles: %d / %d\n", vars->collected, vars->map.nb_collec);
	printf("Moves: %d\n", vars->nb_moves);
	return(1);
}
/*
int	ft_move_up(t_vars *vars, int x, int y)
{
	vars->dir = up;
	if (is_accessible(vars, x, y, vars->dir))
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
		{
			if (y > 2 && (vars->map.map[y - 2][x] == 'L' || vars->map.map[y - 2][x] == 'R') && vars->map.map[y - 3][x] == '1')
				vars->map.map[y - 2][x] = '#';
			else
				vars->map.map[y - 2][x] = 'X';
		}
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
	if (is_accessible(vars, x, y, vars->dir))
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
		{
			if (y < vars->map.height - 3 && (vars->map.map[y + 2][x] == 'L' || vars->map.map[y + 2][x] == 'R') && vars->map.map[y + 3][x] == '1')
				vars->map.map[y + 2][x] = '#';
			else
				vars->map.map[y + 2][x] = 'X';
		}
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
	if (is_accessible(vars, x, y, vars->dir))
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
		{
			if (x < vars->map.length - 2 && (vars->map.map[y][x + 2] == 'L' || vars->map.map[y][x + 2] == 'R') && vars->map.map[y][x + 3] == '1')
				vars->map.map[y][x + 2] = '#';
			else
				vars->map.map[y][x + 2] = 'X';
		}
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
	if (is_accessible(vars, x, y, vars->dir))
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
		{
			if (x > 2 && (vars->map.map[y][x - 2] == 'L' || vars->map.map[y][x - 2] == 'R') && vars->map.map[y][x - 3] == '1')
				vars->map.map[y][x - 2] = '#';
			else
				vars->map.map[y][x - 2] = 'X';
		}
		vars->map.map[y][x] = '0';
		vars->map.map[y][x - 1] = 'P';
		printf("Collectibles: %d / %d\n", vars->collected, vars->map.nb_collec);
		printf("Moves : %d\n", vars->nb_moves);
	}
	return (1);
}
*/
int	ft_move(t_vars *vars, int keycode)
{
	int	x;
	int	y;

	get_coords(vars, &x, &y);
	mlx_string_put(vars->mlx, vars->win, 20, 50 * vars->map.height, 0x00FF0000, "Coucou");
	return (manage_keycode(vars, keycode, x, y));
}
