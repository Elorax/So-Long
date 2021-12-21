/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_animation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 13:52:53 by abiersoh          #+#    #+#             */
/*   Updated: 2021/12/21 03:28:19 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_animate_map(t_vars *vars)
{
	int	i;
	int	j;
	int	poissons;

	poissons = 0;
	i = 0;
	j = 0;
	vars->frames++;
	if (!(vars->frames % 2))
		if (ft_pat_patrouille(vars) == -1)
			return ;
	while (vars->map.map[i])
	{
		while (vars->map.map[i][j])
		{
			if (vars->map.map[i][j] == '0')
				ft_put_img(vars, vars->frames % 4, i, j);
			if (vars->map.map[i][j] == 'C')
				ft_put_img(vars, 4 + ((vars->frames + ++poissons) % 4), i, j);
			j++;
		}
		i++;
		j = 0;
	}
}
