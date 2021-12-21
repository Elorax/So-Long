/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 14:10:20 by abiersoh          #+#    #+#             */
/*   Updated: 2021/12/21 02:41:05 by abiersoh         ###   ########.fr       */
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
	if(vars->win != NULL)
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
//	printf("Collectibles : %d / %d\n", vars->collected, vars->map.nb_collec);
//	printf("Moves : %d\n", vars->nb_moves);
	ft_delete_vars(vars);
	exit(EXIT_SUCCESS);
}

void	ft_mlx_restart(t_vars *vars)
{
	int	i;

	i = -1;
	while (vars->map.map[++i])
		free(vars->map.map[i]);
	free(vars->map.map);
	vars->collected = 0;
	vars->nb_moves = 0;
	vars->frames = 0;
	vars->killed = 0;
	vars->dir = up;
	vars->map.fd = open(vars->map.path, O_RDONLY);
	ft_read_map(&vars->map);
	ft_update_full_map(vars);
	vars->begin = clock();
}