/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 13:38:34 by abiersoh          #+#    #+#             */
/*   Updated: 2021/12/19 15:34:25 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx/mlx.h"
#include "../so_long_bonus.h"

int	exit_hook(t_vars *vars)
{
	ft_mlx_close_croix_rouge_de_ses_morts(vars);
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == ESCAPE_KEY)
		ft_mlx_close_end_level(vars);
	else if (keycode == P_KEY)
		vars->pause = !vars->pause;
	if (vars->pause)
		return (0);
	else if (keycode == R_KEY)
		ft_mlx_restart(vars);
	else if (keycode == W_KEY || keycode == A_KEY || keycode == S_KEY
		|| keycode == D_KEY || keycode == UP_KEY || keycode == DOWN_KEY
		|| keycode == RIGHT_KEY || keycode == LEFT_KEY
		|| keycode == Z_KEY || keycode == Q_KEY)
	{
		int i = ft_move(vars, keycode);
		if (i == 1)
			ft_update_map(vars);
		else if (i == 0)
			ft_mlx_restart(vars);
		else
			ft_mlx_close_end_level(vars);
	}
	else if (keycode == 32)
	{
		ft_attack(vars);
	}
	return (keycode);
}
