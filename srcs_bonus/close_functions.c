/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 14:10:20 by abiersoh          #+#    #+#             */
/*   Updated: 2021/12/21 07:15:50 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_mlx_close_end_level(t_vars *vars)
{
	if (vars->win)
	{
		mlx_clear_window(vars->mlx, vars->win);
		mlx_destroy_window(vars->mlx, vars->win);
		vars->win = NULL;
	}
	printf("Collectibles : %d / %d\n", vars->collected, vars->map.nb_collec);
	printf("Moves : %d\n", vars->nb_moves);
	printf("Record de moves : %s", vars->objectif);
}

void	ft_mlx_close_game(t_vars *vars)
{
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
	while (++i < WHEIGHT)
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
	ft_update_full_map(vars);
	vars->begin = clock();
	ft_print_data(vars);
}
