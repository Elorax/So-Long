/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 01:52:41 by abiersoh          #+#    #+#             */
/*   Updated: 2021/12/29 10:49:35 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_print_data(t_vars *vars)
{
	char	*str;
	int		i;

	i = -1;
	while (++i < 4)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->images[26],
			1300, 50 * i);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->images[26],
			1350, 50 * i);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->images[26],
			1400, 50 * i);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->images[26],
			1450, 50 * i);
	}
	str = ft_itoa(vars->nb_moves);
	str = ft_strjoin2("Moves : ", str, 0, 1);
	mlx_string_put(vars->mlx, vars->win, 1400, 50,
		0x00FFFFFF, str);
	str = (free(str), ft_strjoin2("Niveau ", ft_itoa(vars->level), 0, 1));
	mlx_string_put(vars->mlx, vars->win, 1400, 200,
		0x00FFFFFF, str);
	(free(str), ft_print_data_ennemy(vars));
}

void	ft_print_life(t_vars *vars)
{
	int	i;

	i = -1;
	while (++i < 5)
	{
		if (i < vars->life)
			mlx_put_image_to_window(vars->mlx, vars->win,
				vars->images[30], 1320 + i * 50, 300);
		else
			mlx_put_image_to_window(vars->mlx, vars->win,
				vars->images[31], 1320 + i * 50, 300);
	}
}

void	ft_print_data_ennemy(t_vars *vars)
{
	char	*str;

	str = ft_strjoin2(ft_itoa(vars->collected), "/", 1, 0);
	str = ft_strjoin2(str, ft_itoa(vars->map.nb_collec), 1, 1);
	mlx_string_put(vars->mlx, vars->win, 1400, 100,
		0x00FFFFFF, str);
	free(str);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->images[28], 1430,
		100);
	if (vars->to_kill > 0)
	{
		str = ft_strjoin2(ft_itoa(vars->killed), "/", 1, 0);
		str = ft_strjoin2(str, ft_itoa(vars->to_kill), 1, 1);
		mlx_string_put(vars->mlx, vars->win, 1400,
			150, 0x00FFFFFF, str);
		free(str);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->images[27], 1430,
			150);
	}
}

int	ft_move(t_vars *vars, int keycode)
{
	int		ret;

	ret = manage_keycode(vars, keycode, vars->x, vars->y);
	ft_print_data(vars);
	return (ret);
}
