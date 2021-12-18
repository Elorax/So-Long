/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pat_patrouille.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 17:04:16 by abiersoh          #+#    #+#             */
/*   Updated: 2021/12/18 17:55:24 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	ft_pat_patrouille(t_vars *vars)
{
	int		i;
	int		j;
	char	c;
	//int		no_move;

	i = 0;
	j = 0;
	//no_move = 0;
	while (vars->map.map[i])
	{
		while (vars->map.map[i][j])
		{
			if (vars->map.map[i][j] == 'R')
			{
				c = vars->map.map[i][j + 1];
					printf("%d, %d : %c\n", j, i, vars->map.map[i][j]);
				if (c == '0')
				{
					vars->map.map[i][j] = '0';
					vars->map.map[i][j + 1] = 'R';
					ft_put_img(vars, 14, i, j + 1);
					ft_put_img(vars, 0, i, j);
					j++;
				}
				else if (c == 'P')
				{
					ft_mlx_close_escape(vars);
					return (-1);
				}
				else
				{
					//printf("%c\n", vars->map[i][j]);
					vars->map.map[i][j] = 'L';
					//printf("%c\n", vars->map[i][j]);
					ft_put_img(vars, 15, i, j);
				}
			}
			else if (vars->map.map[i][j] == 'L')
			{
				c = vars->map.map[i][j - 1];
					printf("%d, %d : %c\n", j, i, vars->map.map[i][j]);
				if (c == '0')
				{
					vars->map.map[i][j] = '0';
					vars->map.map[i][j - 1] = 'L';
					ft_put_img(vars, 15, i, j - 1);
					ft_put_img(vars, 0, i, j);
				}
				else if (c == 'P')
				{
					ft_mlx_close_escape(vars);
					return (-1);
				}
				else
				{
					//printf("%c\n", vars->map[i][j]);
					vars->map.map[i][j] = 'R';
					//printf("%c\n", vars->map[i][j]);
					ft_put_img(vars, 14, i, j);
				}
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}
