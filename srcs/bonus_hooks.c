/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 13:50:46 by abiersoh          #+#    #+#             */
/*   Updated: 2021/12/18 13:57:48 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	handle_no_event(t_vars *vars)
{
	clock_t	current = clock();
	if (((current - vars->begin) / (CLOCKS_PER_SEC / FPS)) > vars->frames)
		ft_animate_map(vars);
	return (0);
}
