/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 15:08:02 by abiersoh          #+#    #+#             */
/*   Updated: 2021/12/21 08:32:19 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_put_img_classic(t_vars *vars, int index, int i, int j)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->images[index],
		j * vars->img_width, i * vars->img_height);
}
void	ft_put_img(t_vars *vars, int index, int i, int j)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->images[index],
		(j + vars->offset_x) * vars->img_width, (i + vars->offset_y) * vars->img_height);
}

void	ft_update_full_map(t_vars *vars)
{
	int	i;
	int	j;
	int poissons;
	int	imin;
	int	imax;
	int	jmin;
	int	jmax;

	//printf("x, y : %d, %d\n", vars->x, vars->y);
	ft_calcul_offset_i(vars, &imin, &imax);
	ft_calcul_offset_j(vars, &jmin, &jmax);
	poissons = 0;
	i = imin - 1;
	j = jmin - 1;
	while (++i <= imax)
	{
		while (++j <= jmax)
		{
			if (vars->map.map[i][j] == '0')
				ft_put_img(vars, vars->frames % 4, i - imin, j - jmin);
			if (vars->map.map[i][j] == 'C')
				ft_put_img(vars, 4 + (vars->frames + ++poissons) % 4, i - imin, j - jmin);
			if (ft_strchr("Pp", vars->map.map[i][j]))
				ft_put_img(vars, 8 + vars->dir, i - imin, j - jmin);
			if (vars->map.map[i][j] == 'E')
				ft_put_img(vars, 12, i - imin, j- jmin);
			if (vars->map.map[i][j] == '1')
				ft_put_img(vars, 13, i - imin, j - jmin);
			if (vars->map.map[i][j] == 'R')
				ft_put_img(vars, 14, i - imin, j - jmin);
			if (vars->map.map[i][j] == 'L')
				ft_put_img(vars, 15, i - imin, j - jmin);
			if (vars->map.map[i][j] == 'X')
				ft_put_img(vars, 16, i - imin, j - jmin);
			if (vars->map.map[i][j] == '#')
				ft_put_img(vars, 17, i - imin, j - jmin);
			if (vars->map.map[i][j] == 'x')
				ft_put_img(vars, 29, i - imin, j - jmin);
			if (vars->map.map[i][j] == 'b')
				ft_put_img(vars, 18, i - imin, j - jmin);
			if (vars->map.map[i][j] == 'B')
				ft_put_img(vars, 19, i - imin, j - jmin);
			if (vars->map.map[i][j] == 'D')
				ft_put_img(vars, 20, i - imin, j - jmin);
			if (vars->map.map[i][j] == 'd')
				ft_put_img(vars, 21, i - imin, j - jmin);
			if (vars->map.map[i][j] == 'q')
				ft_put_img(vars, 22 + vars->dir, i - imin, j - jmin);
		}
		j = jmin - 1;
	}
}
