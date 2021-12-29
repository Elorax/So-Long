/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 13:38:34 by abiersoh          #+#    #+#             */
/*   Updated: 2021/12/21 07:49:29 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx/mlx.h"
#include "../so_long_bonus.h"

int	exit_hook(t_vars *vars)
{
	ft_mlx_close_croix_rouge_de_ses_morts(vars);
	return (0);
}

void	manage_movement(t_vars *vars, int keycode)
{
	int	i;

	i = ft_move(vars, keycode);
	if (i == 1)
		ft_update_full_map(vars);
	else if (i == 0)
	{
		if (--vars->life >= 0)
			ft_mlx_restart(vars);
		else
			ft_mlx_close_game(vars);
	}
	else
	{
		printf("Moves : %d\n", vars->nb_moves);
		printf("Best moves possible : %s", vars->objectif);
		if (vars->av[vars->level + 1])
			ft_next_level(vars);
		else
			ft_mlx_close_game(vars);
	}
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == ESCAPE_KEY)
		ft_mlx_close_game(vars);
	else if (keycode == P_KEY)
		vars->pause = !vars->pause;
	if (vars->pause)
		return (0);
	else if (keycode == R_KEY)
	{
		if (--vars->life >= 0)
			ft_mlx_restart(vars);
		else
			ft_mlx_close_game(vars);
	}
	else if (keycode == W_KEY || keycode == A_KEY || keycode == S_KEY
		|| keycode == D_KEY || keycode == UP_KEY || keycode == DOWN_KEY
		|| keycode == RIGHT_KEY || keycode == LEFT_KEY
		|| keycode == Z_KEY || keycode == Q_KEY)
		manage_movement(vars, keycode);
	return (keycode);
}
