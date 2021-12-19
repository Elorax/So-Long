/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 16:07:28 by abiersoh          #+#    #+#             */
/*   Updated: 2021/12/19 14:43:09 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_play(t_vars *vars, char *av, int index)
{
	if (!is_name_valid(av))
		return (-1);
	ft_init_vars(vars);
	vars->map.fd = open(av, O_RDONLY);
	if (vars->map.fd <= 0)
	{
		printf("Erreur lors de l'ouverture du fichier de l'arg %d\n", index);
		return (-1);
	}
	vars->map.height = ft_count_lines(vars->map);
	close(vars->map.fd);
	vars->map.fd = open(av, O_RDONLY);
	if (ft_init_map(&(vars->map)) == -1)
		return (-1);
	printf("Argument %d : Map valide !\n", index);
	close(vars->map.fd);
	vars->map.path = ft_strdup(av);
	ft_begin_game(vars);
	ft_delete_vars(vars);
	return (0);
}

int	main(int ac, char **av)
{
	t_vars	vars;
	int		i;

	i = 0;
	if (ac < 2)
		return (printf("Mauvais nombre d'arguments\n"), -1);
	while (av[++i])
	{
		if (ft_play(&vars, av[i], i) == -1)
		{
		}
		//Gerer les potentiels leaks
	}
}
