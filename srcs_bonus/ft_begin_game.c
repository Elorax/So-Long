/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_begin_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 15:17:02 by abiersoh          #+#    #+#             */
/*   Updated: 2021/12/21 08:55:42 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_fill_coraux_bizarres(t_vars *vars)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < 17)
	{
		while (++j < 27)
		{
			ft_put_img(vars, 13, i, j);
		}
		j = -1;
	}
}

void	ft_print_case(t_vars *vars, char c, int i, int j)
{
	if (c == '0')
		ft_put_img(vars, 0, i, j);
	else if (c == 'C')
		ft_put_img(vars, 4, i, j);
	else if (c == 'P')
	{
		ft_put_img(vars, 8, i, j);
		vars->x = j;
		vars->y = i;
	}
	else if (c == 'E')
		ft_put_img(vars, 12, i, j);
	else if (c == '1')
		ft_put_img(vars, 13, i, j);
	else if (c == 'R')
		ft_put_img(vars, 14, i, j);
	else if (c == 'L')
		ft_put_img(vars, 15, i, j);
	else if (c == 'X')
		ft_put_img(vars, 16, i, j);
	else if (c == 'B')
		ft_put_img(vars, 19, i, j);
	else if (c == 'D')
		ft_put_img(vars, 20, i, j);
}

void	ft_display_map(t_vars *vars)
{
	int	i;
	int	j;
	int	imin;
	int	imax;
	int	jmin;
	int	jmax;

	printf("x, y: %d, %d\n", vars->x, vars->y);
	ft_calcul_offset(vars, &imin, &imax, &jmin, &jmax);
	i = imin -1;
	j = jmin -1;
	printf("display : \n");
	printf("imin : %d\n", imin);
	printf("imax : %d\n", imax);
	printf("jmin : %d\n", jmin);
	printf("jmax : %d\n\n", jmax);
	while (++i <= imax)
	{
		while (++j <= jmax)
		{
			ft_print_case(vars, vars->map.map[i][j], i - imin, j - jmin);
		}
		j = jmin-1;
	}
}

void	ft_setup_hooks(t_vars *vars)
{
	mlx_loop_hook(vars->mlx, &handle_no_event, vars);
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_hook(vars->win, 17, 0, exit_hook, vars);
}

void	ft_begin_game(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WLENGTH,
			WHEIGHT, "Thanks for all the fish !");
	vars->images = ft_init_images(vars);
	ft_fill_coraux_bizarres(vars);
	get_coords(vars, &(vars->x), &(vars->y));
	ft_display_map(vars);
	ft_print_data(vars);
	ft_setup_hooks(vars);
	mlx_loop(vars->mlx);
}
