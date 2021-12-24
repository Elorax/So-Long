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
			ft_put_img_classic(vars, 0, i, j);
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

	ft_calcul_offset_i(vars, &imin, &imax);
	ft_calcul_offset_j(vars, &jmin, &jmax);
	i = imin -1;
	j = jmin -1;
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

void	ft_begin_level(t_vars *vars)
{
	if (!vars->av[vars->level])
		ft_mlx_close_game(vars);
	ft_init_vars(vars);
	vars->map.fd = open(vars->av[vars->level], O_RDONLY);
	if (vars->map.fd <= 0)
	{
		printf("Erreur lors de l'ouverture du fichier de l'arg %d\n", vars->level);
		return ;//Gerer ce cas.
	}
	vars->map.height = ft_count_lines(vars->map);
	close(vars->map.fd);
	vars->map.fd = open(vars->av[vars->level], O_RDONLY);
	if (ft_init_map(&(vars->map)) == -1)
		return ;//Gerer le cas.
	close(vars->map.fd);
	ft_fill_coraux_bizarres(vars);
	get_coords(vars, &(vars->x), &(vars->y));
	ft_calcul_decalage(vars, &(vars->offset_x), &(vars->offset_y));
	ft_display_map(vars);
	ft_print_data(vars);
}

void	ft_begin_game(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WLENGTH,
			WHEIGHT, "Thanks for all the fish !");
	vars->images = ft_init_images(vars);
	ft_fill_coraux_bizarres(vars);
	get_coords(vars, &(vars->x), &(vars->y));
	ft_calcul_decalage(vars, &(vars->offset_x), &(vars->offset_y));
	ft_display_map(vars);
	ft_print_data(vars);
	ft_setup_hooks(vars);
	mlx_loop(vars->mlx);
}
