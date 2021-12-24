/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_animation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 13:52:53 by abiersoh          #+#    #+#             */
/*   Updated: 2021/12/21 07:11:02 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_animate_map(t_vars *vars)
{
	int	i;
	int	j;
	int	poissons;
	int	imin;
	int	imax;
	int	jmin;
	int	jmax;

	ft_calcul_offset_i(vars, &imin, &imax);
	ft_calcul_offset_j(vars, &jmin, &jmax);
	poissons = 0;
	i = imin - 1;
	j = jmin -1;
	vars->frames++;
	if (!(vars->frames % 2))
		if (ft_pat_patrouille(vars) == -1)
			return ;
	while (++i <= imax)
	{
		while (++j <= jmax)
		{
			if (vars->map.map[i][j] == '0')
				ft_put_img(vars, vars->frames % 4, i - imin, j - jmin);
			else if (vars->map.map[i][j] == 'C')
				ft_put_img(vars, 4 + ((vars->frames + ++poissons) % 4), i - imin, j - jmin);
			else if (vars->map.map[i][j] == 'R')
				ft_put_img(vars, 14, i - imin, j - jmin);
			else if (vars->map.map[i][j] == 'L')
				ft_put_img(vars, 15, i - imin, j - jmin);
		}
		j = jmin - 1;
	}
}
