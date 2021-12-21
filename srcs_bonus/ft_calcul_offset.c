/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calcul_offset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 06:40:54 by abiersoh          #+#    #+#             */
/*   Updated: 2021/12/21 08:54:54 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	ft_calcul_offset(t_vars *vars, int *imin, int *imax, int *jmin, int *jmax)
{
	if (vars->x < 14)
	{
		*jmin = 0;
		*jmax = min(26, vars->map.length - 1);
	}
	else if (vars->x > vars->map.length - 14)
	{
		*jmin = max(0, vars->map.length - 27);
		*jmax = vars->map.length - 1;
	}
	else
	{
		*jmin = max(0, vars->x - 13);
		*jmax = min(vars->map.length - 1, vars->x + 13);
	}
	if (vars->y < 9)
	{
		*imin = 0;
		*imax = min(16, vars->map.height - 1);
	}
	else if (vars->y > vars->map.height - 9)
	{
		*imin = max(0, vars->map.height - 17);
		*imax = vars->map.height - 1;
	}
	else
	{
		*imin = max(0, vars->y - 8);
		*imax = min(vars->map.height - 1, vars->y + 8);
	}
}
