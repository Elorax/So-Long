/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 16:07:28 by abiersoh          #+#    #+#             */
/*   Updated: 2021/12/21 00:33:47 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_play(t_vars *vars)
{
	vars->level = 0;
	while (!is_name_valid(vars->av[++(vars->level)]))
		{}//Afficher erreur de nom de map.
	vars->map.path = ft_strdup(vars->av[vars->level]);//inutile c'est vars->av[niveau]
	ft_init_vars(vars);
	vars->map.fd = open(vars->av[vars->level], O_RDONLY);
	if (vars->map.fd <= 0)
	{
		printf("Erreur lors de l'ouverture du fichier de l'arg %d\n", vars->level);
	}
	vars->map.height = ft_count_lines(vars->map);
	close(vars->map.fd);
	vars->map.fd = open(vars->av[vars->level], O_RDONLY);
	if (ft_init_map(&(vars->map)) == -1)
		{}//Mauvaise map, gerer erreur.
	close(vars->map.fd);
	ft_begin_game(vars);
	ft_delete_vars(vars);
	return (0);
}

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac < 2)
		return (printf("Mauvais nombre d'arguments\n"), -1);
	vars.av = av;
	if (ft_play(&vars))
	{
	}
	//gerer potentiel leaks
}
