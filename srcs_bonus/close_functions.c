/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 14:10:20 by abiersoh          #+#    #+#             */
/*   Updated: 2021/12/30 18:56:29 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_mlx_close_game(t_vars *vars)
{
	ft_mega_fondu(vars);
	if (vars->win != NULL)
	{
		mlx_clear_window(vars->mlx, vars->win);
		mlx_destroy_window(vars->mlx, vars->win);
		vars->win = NULL;
	}
	ft_delete_vars(vars);
	exit(EXIT_SUCCESS);
}

void	ft_mlx_close_croix_rouge_de_ses_morts(t_vars *vars)
{
	t_xvar	*ptr;

	if (vars->win != NULL)
	{
		mlx_clear_window(vars->mlx, vars->win);
		mlx_destroy_window(vars->mlx, vars->win);
		vars->win = NULL;
		ptr = (t_xvar *)(vars->mlx);
		ptr->end_loop = 1;
	}
	ft_delete_vars(vars);
	exit(EXIT_SUCCESS);
}

void	ft_fondu(t_vars *vars)
{
	int	i;
	int	j;

	i = -1;
	while (++i <= WHEIGHT + 10)
	{
		j = -1;
		while (++j < WLENGTH - 300)
		{
			mlx_pixel_put(vars->mlx, vars->win, j, i, 0);
		}
		usleep(1000);
	}
	usleep(300000);
}

void	ft_put_pixel_horizontal(t_vars *vars, int y)
{
	int	j;

	j = -1;
	while (++j < WLENGTH - 300)
		mlx_pixel_put(vars->mlx, vars->win, j, y, 0);
}
void	ft_put_pixel_vertical(t_vars *vars, int x)
{
	int	i;

	i = -1;
	while (++i < WHEIGHT)
		mlx_pixel_put(vars->mlx, vars->win, x, i, 0);
}

void	ft_mega_fondu(t_vars *vars)
{
	int	i;
	int	j;

	i = -1;
	while (++i <= WHEIGHT + 10)
	{
		j = 1300;
		while (++j < WLENGTH)
		{
			mlx_pixel_put(vars->mlx, vars->win, j, i, 0);
		}
		usleep(500);
	}
	usleep(400000);
	j = -1;
	while (++j < 650)
	{
		ft_put_pixel_horizontal(vars, (j * 900) / 1300);
		ft_put_pixel_vertical(vars, 1300 - j);
		ft_put_pixel_horizontal(vars, 900 - (j * 900) / 1300);
		ft_put_pixel_vertical(vars, j);
		usleep(1000);
	}
	usleep(100000);
}

void	ft_next_level(t_vars *vars)
{
	int	i;

	ft_fondu(vars);
	while (vars->av[++(vars->level)] && !is_name_valid(vars->av[(vars->level)]))
	{
	}
	if (!vars->av[vars->level])
		ft_mlx_close_game(vars);
	i = -1;
	while (vars->map.map[++i])
		free(vars->map.map[i]);
	free(vars->map.map);
	vars->collected = 0;
	vars->nb_moves = 0;
	vars->frames = 0;
	vars->killed = 0;
	vars->dir = up;
	free(vars->settings);
	free(vars->objectif);
	free(vars->mobs_to_kill);
	vars->begin = clock();
	ft_begin_level(vars);
}

void	ft_mlx_restart(t_vars *vars)
{
	int	i;

	i = -1;
	ft_fondu(vars);
	ft_print_life(vars);
	while (vars->map.map[++i])
		free(vars->map.map[i]);
	free(vars->map.map);
	vars->collected = 0;
	vars->nb_moves = 0;
	vars->frames = 0;
	vars->killed = 0;
	vars->dir = up;
	vars->map.fd = open(vars->av[vars->level], O_RDONLY);
	ft_read_map(&vars->map);
	get_coords(vars, &vars->x, &vars->y);
	ft_fill_coraux_bizarres(vars);
	ft_update_full_map(vars);
	vars->begin = clock();
	ft_print_data(vars);
}
