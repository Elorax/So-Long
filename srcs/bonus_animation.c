/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_animation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 13:52:53 by abiersoh          #+#    #+#             */
/*   Updated: 2021/12/18 16:19:13 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_animate_map(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	vars->frames++;
	while (vars->map.map[i])
	{
		while (vars->map.map[i][j])
		{
			if (vars->map.map[i][j] == '0')
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->images[(vars->frames % 4)],
					j * vars->img_width, i * vars->img_height);
			if (vars->map.map[i][j] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->images[4 + (vars->frames % 4)],
					j * vars->img_width, i * vars->img_height);
			j++;
		}
		i++;
		j = 0;
	}
}
