/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 15:08:02 by abiersoh          #+#    #+#             */
/*   Updated: 2021/12/19 15:11:47 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_put_img(t_vars *vars, int index, int i, int j)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->images[index],
		j * vars->img_width, i * vars->img_height);
}

void	ft_update_full_map(t_vars *vars)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (vars->map.map[++i])
	{
		while (vars->map.map[i][++j] != '\n')
		{
			if (vars->map.map[i][j] == '0')
				ft_put_img(vars, vars->frames % 4, i, j);
			if (vars->map.map[i][j] == '1')
				ft_put_img(vars, 13, i, j);
			if (vars->map.map[i][j] == 'E')
				ft_put_img(vars, 12, i, j);
			if (vars->map.map[i][j] == 'P')
				ft_put_img(vars, 8 + vars->dir, i, j);
			if (vars->map.map[i][j] == 'C')
				ft_put_img(vars, 4 + vars->frames % 4, i, j);
			if (vars->map.map[i][j] == 'X')
				ft_put_img(vars, 16, i, j);
			if (vars->map.map[i][j] == '#')
				ft_put_img(vars, 17, i, j);
			if (vars->map.map[i][j] == 'R')
				ft_put_img(vars, 14, i, j);
			if (vars->map.map[i][j] == 'L')
				ft_put_img(vars, 15, i, j);
		}
		j = -1;
	}
}


void	ft_update_map(t_vars *vars)
{
	int	i;
	int	j;
	int	adj;

	adj = 0;
	i = -1;
	j = -1;
	while (vars->map.map[++i])
	{
		while (vars->map.map[i][++j] != '\n')
		{
			adj = is_adjacent(vars, i, j);
			if (vars->map.map[i][j] == '0' && adj)
				ft_put_img(vars, vars->frames % 4, i, j);
			if (vars->map.map[i][j] == '1' && adj)
				ft_put_img(vars, 13, i, j);
			if (vars->map.map[i][j] == 'E' && adj)
				ft_put_img(vars, 12, i, j);
			if (vars->map.map[i][j] == 'P' && adj)
				ft_put_img(vars, 8 + vars->dir, i, j);
			if (vars->map.map[i][j] == 'C' && adj)
				ft_put_img(vars, 4 + vars->frames % 4, i, j);
			if (vars->map.map[i][j] == 'X' && adj)
				ft_put_img(vars, 16, i, j);
			if (vars->map.map[i][j] == '#' && adj)
				ft_put_img(vars, 17, i, j);
		}
		j = -1;
	}
}
