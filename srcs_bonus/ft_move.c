/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 01:52:41 by abiersoh          #+#    #+#             */
/*   Updated: 2021/12/21 03:31:09 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_print_data(t_vars *vars)
{
	char	*str;

	ft_put_img(vars, 26, vars->map.height, 0);
	ft_put_img(vars, 26, vars->map.height, 1);
	ft_put_img(vars, 26, vars->map.height, 2);
	str = ft_itoa(vars->nb_moves);
	str = ft_strjoin2("Moves : ", str, 0, 1);
	mlx_string_put(vars->mlx, vars->win, 20, 50 * vars->map.height + 20,
		0x00FFFFFF, str);
	free(str);
	str = ft_strjoin2("Niveau ", ft_itoa(vars->level), 0, 1);
	mlx_string_put(vars->mlx, vars->win, 20, 50 * vars->map.height + 45,
		0x00FFFFFF, str);
	free(str);
	str = ft_strjoin2(ft_itoa(vars->collected), "/", 1, 0);
	str = ft_strjoin2(str, ft_itoa(vars->map.nb_collec), 1, 1);
	mlx_string_put(vars->mlx, vars->win, 90, 50 * vars->map.height + 20,
		0x00FFFFFF, str);
	free(str);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->images[28], 115,
		50 * vars->map.height + 5);
	ft_print_data_ennemy(vars);
}

void	ft_print_data_ennemy(t_vars *vars)
{
	char	*str;

	if (vars->to_kill > 0)
	{
		str = ft_itoa(vars->to_kill - vars->killed);
		if (*str == '-')
			mlx_string_put(vars->mlx, vars->win, 103,
				50 * vars->map.height + 45, 0x00FFFFFF, "0");
		else
			mlx_string_put(vars->mlx, vars->win, 103,
				50 * vars->map.height + 45, 0x00FFFFFF, str);
		free(str);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->images[27], 115,
			50 * vars->map.height + 25);
	}
}

int	ft_move(t_vars *vars, int keycode)
{
	int		x;
	int		y;
	int		ret;

	get_coords(vars, &x, &y);
	ret = manage_keycode(vars, keycode, x, y);
	ft_print_data(vars);
	return (ret);
}
