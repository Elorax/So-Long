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

void	ft_calcul_decalage(t_vars *vars, int *offset_x, int *offset_y)
{
	*offset_x = max(0, ((WLENGTH - 300) / TILE_SIZE) - vars->map.length);
	*offset_y = max(0, (WHEIGHT / TILE_SIZE) - vars->map.height);
	*offset_x /= 2;//Middle
	*offset_y /= 2;//Middle	
}


void	ft_calcul_offset_i(t_vars *vars, int *imin, int *imax)
{
	//if y < 5
	//alors imin = 0 et imax = le plus petit entre 8 et hauteur - 1.
	if (vars->y < ((WHEIGHT / TILE_SIZE) + 1)/ 2)
	{
		*imin = 0;
		*imax = min((WHEIGHT / TILE_SIZE) - 1, vars->map.height - 1);
	}
	//if y > hauteur - 5
	//alors imin = le plus grand entre 0 et hauteur - 9
	//ex : hauteur = 20. y = 18. imin = 11, imax = 19.
	else if (vars->y > vars->map.height - (((WHEIGHT / TILE_SIZE) + 1) / 2))
	{
//		printf("ca merde");
		*imin = max(0, vars->map.height - ((WHEIGHT / TILE_SIZE)));
		*imax = vars->map.height - 1;
	}
	//Sinon donc y >= 5 et y <= hauteur - 5
	//imin vaut le maximum entre y - 5 et 0
	//imax vaut le minimum entre hauteur - 1 et y + 4
	else
	{
		*imin = max(0, vars->y - (((WHEIGHT / TILE_SIZE))/ 2));
		*imax = min(vars->map.height - 1, vars->y + ((WHEIGHT / TILE_SIZE) / 2));
	}
}

void	ft_calcul_offset_j(t_vars *vars, int *jmin, int *jmax)
{
	if (vars->x < (((WLENGTH - 300) / TILE_SIZE) + 1) / 2)
	{
		*jmin = 0;
		*jmax = min(((WLENGTH - 300) / TILE_SIZE - 1), vars->map.length - 1);
	}
	else if (vars->x > vars->map.length - ((((WLENGTH - 300) / TILE_SIZE) + 1) / 2))
	{
		*jmin = max(0, vars->map.length - ((WLENGTH - 300) / TILE_SIZE));
		*jmax = vars->map.length - 1;
	}
	else
	{
		*jmin = max(0, vars->x - (((WLENGTH - 300) / TILE_SIZE) / 2));
		*jmax = min(vars->map.length - 1, vars->x + (((WLENGTH - 300) / TILE_SIZE) / 2));
	}
}
