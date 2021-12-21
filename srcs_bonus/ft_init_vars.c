/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_vars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 14:29:00 by abiersoh          #+#    #+#             */
/*   Updated: 2021/12/21 02:44:42 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

char	*ft_get_settings(char *src)
{
	char	*dest;

	dest = ft_so_long_strndup(src, ft_strlen(src) - 4);
	dest = ft_strjoin2(dest, ".set", 1, 0);
	return (dest);
}

void	ft_init_vars(t_vars *vars)
{
	int	fd;

	vars->map.length = 0;
	vars->map.height = 0;
	vars->map.nb_exit = 0;
	vars->map.nb_collec = 0;
	vars->map.nb_player = 0;
	vars->map.fd = 0;
	vars->settings = ft_get_settings(vars->map.path);

	fd = open(vars->settings, O_RDONLY);
	if (fd > 0)
	{
		vars->objectif = get_next_line(fd);
		vars->mobs_to_kill = get_next_line(fd);
		vars->to_kill = ft_atoi(vars->mobs_to_kill);
	}
	vars->killed = 0;
	close(fd);
	vars->collected = 0;
	vars->nb_moves = 0;
	vars->frames = 0;
	vars->dir = up;
	vars->pause = 0;
	vars->begin = clock();
}

void	*read_image(t_vars *vars, char *path)
{
	void	*img;

	img = mlx_xpm_file_to_image(vars->mlx, path,
			&vars->img_width, &vars->img_height);
	return (img);
}

void	ft_init_images_p2(void **images, t_vars *vars)
{
	images[14] = read_image(vars, "img/Poulpyright.xpm");
	images[15] = read_image(vars, "img/Poulpyleft.xpm");
	images[16] = read_image(vars, "img/Moveable.xpm");
	images[17] = read_image(vars, "img/Dead.xpm");
	images[18] = read_image(vars, "img/Moveable_Placed.xpm");
	images[19] = read_image(vars, "img/Brown_Cross.xpm");
	images[20] = read_image(vars, "img/Closed_Door.xpm");
	images[21] = read_image(vars, "img/Open_Door.xpm");
	images[22] = read_image(vars, "img/Personnage_Door1.xpm");
	images[23] = read_image(vars, "img/Personnage_Door2.xpm");
	images[24] = read_image(vars, "img/Personnage_Door3.xpm");
	images[25] = read_image(vars, "img/Personnage_Door4.xpm");
	images[26] = read_image(vars, "img/Void.xpm");
	images[29] = NULL;
}

void	**ft_init_images(t_vars *vars)
{
	void	**images;

	images = malloc(sizeof(*images) * 30);
	if (!images)
		return (NULL);
	images[27] = read_image(vars, "img/MiniPoulpy.xpm");
	images[28] = read_image(vars, "img/MiniFish.xpm");
	images[0] = read_image(vars, "img/Sol1.xpm");
	images[1] = read_image(vars, "img/Sol2.xpm");
	images[2] = read_image(vars, "img/Sol3.xpm");
	images[3] = read_image(vars, "img/Sol4.xpm");
	images[4] = read_image(vars, "img/Collectible1.xpm");
	images[5] = read_image(vars, "img/Collectible2.xpm");
	images[6] = read_image(vars, "img/Collectible3.xpm");
	images[7] = read_image(vars, "img/Collectible4.xpm");
	images[8] = read_image(vars, "img/Personnage1.xpm");
	images[9] = read_image(vars, "img/Personnage2.xpm");
	images[10] = read_image(vars, "img/Personnage3.xpm");
	images[11] = read_image(vars, "img/Personnage4.xpm");
	images[12] = read_image(vars, "img/Exit1.xpm");
	images[13] = read_image(vars, "img/Obstacle1.xpm");
	ft_init_images_p2(images, vars);
	return (images);
}

//lit la map sans la verifier (On l'a deja verifiee avant)

int	ft_read_map(t_map *map)
{
	int	i;

	i = 0;
	map->map = malloc(sizeof(char *) * (map->height + 1));
	if (!(map->map))
		return (-1);
	map->map[i] = get_next_line(map->fd);
	while (map->map[i++])
		map->map[i] = get_next_line(map->fd);
	return (0);
}

//Probably leaks si mauvaise map

int	ft_init_map(t_map *map)
{
	int	i;

	i = 0;
	map->map = malloc(sizeof(char *) * (map->height + 1));
	if (!(map->map))
		return (-1);
	map->map[i] = get_next_line(map->fd);
	while (map->map[i])
	{
		if (ft_check_line(map, i) != 0)
			return (printf("Erreur : Mauvaise map.\n"), -1);
		if (i > 0 && ft_strlen(map->map[i]) != ft_strlen(map->map[i - 1]))
			return (printf("Erreur : Mauvaise map.\n"), -1);
		i++;
		map->map[i] = get_next_line(map->fd);
	}
	if ((i > 1) && (ft_check_first_line(map->map[0])
			|| ft_check_first_line(map->map[i - 1])))
		return (printf("Erreur : Mauvaise map.\n"), -1);
	if (map->nb_player != 1 || map->nb_exit != 1 || map->nb_collec < 1)
		return (printf("Erreur : Mauvaise map.\n"), -1);
	map->height = i;
	map->length = ft_strlen(map->map[0]) - 1;
	return (0);
}
