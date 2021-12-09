#include "./minilibx/mlx.h"

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include <fcntl.h>
#define UP_ARROW_KEY 65362
#define LEFT_ARROW_KEY 65361
#define RIGHT_ARROW_KEY 65363
#define DOWN_ARROW_KEY 65364
#define A_KEY 7
#define W_KEY 119
#define Z_KEY 122
#define Q_KEY 113
#define S_KEY 115
#define D_KEY 100
#define ESCAPE_KEY 65307


 typedef struct	s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_img
{
	void	*img;
	int	img_width;
	int	img_height;
	char	*path;
}	t_img;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}	t_data;


void	ft_mlx_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(EXIT_SUCCESS);
}


int	key_hook(int keycode, t_vars *vars)
{
	
	if (keycode == 65307)
		ft_mlx_close(vars);
	else if (keycode == UP_ARROW_KEY)
	return(printf("Hello from key_hook %d!\n", keycode));
}


static	char	*ft_strchr(char *str, char c)
{
	while (*str)
		if (*str++ == c)
			return (str - 1);
	return (NULL);
}

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

typedef struct s_map
{
	int	fd;
	int	height;
	int	length;
	int	nb_exit;
	int	nb_player;
	int	nb_collec;
	char	*map[21];
}	t_map;

int	ft_check_line(t_map *map, int i)
{
	char	*str;

	str = map->map[i];
	if (*str != '1')
		return (-1);
	while (*str)
	{
		if (!ft_strchr("01PEC\n", *str))
			return (-1);
		else
		{
			if (*str == 'E')
				map->nb_exit++;
			else if (*str == 'C')
				map->nb_collec++;
			else if (*str == 'P')
				map->nb_player++;
			str++;
		}
	}
	if (*(str - 2) != '1')
		return (-1);
	return (0);
}

int	ft_check_first_line(char *str)
{
	while (*str && *str != '\n')
		if ((*str++ != '1'))
			return (-1);
	return (0);
}


int	ft_init_map(t_map *map)
{
	int	i;

	i = 0;
	while ((map->map[i] = get_next_line(map->fd)))
	{
		if (ft_check_line(map, i) != 0)
			return(printf("Erreur : Mauvaise map.\n"), -1);
		if (i > 0 && ft_strlen(map->map[i]) != ft_strlen(map->map[i - 1]))
			return(printf("Erreur : Mauvaise map.\n"), -1);
		i++;
	}
	if ((i > 1) && (ft_check_first_line(map->map[0]) || ft_check_first_line(map->map[i - 1])))
		return(printf("Erreur : Mauvaise map.\n"), -1);
	if (map->nb_player != 1 || map->nb_exit != 1 || map->nb_collec < 1)
		return(printf("Erreur : Mauvaise map.\n"), -1);
	map->height = i;
	map->length = ft_strlen(map->map[0]) - 1;
	i = 0;
	return (0);
}

int	ft_count_lines(t_map map)
{
	char	*str;
	int	i;

	str = get_next_line(map.fd);
	i = 0;
	while (str != NULL)
	{
		str = get_next_line(map.fd);
		i++;
	}
	return (i);
}

void	ft_display_map(t_map map)
{
	int	i;
	int	j;
	void	*img;
	int	img_width;
	int	img_height;
	t_vars	vars;

	i = 0;
	j = 0;
	int	k = 0;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 50 * map.length, 50 * map.height, "Thanks for all the fish !");
	while (k < 10000)
	{	
		while (map.map[i])
		{
			while (map.map[i][j] != '\n')
			{
				if (map.map[i][j] == '0')
				{
					if (k % 4 == 0)
						img = mlx_xpm_file_to_image(vars.mlx, "Sol1.xpm", &img_width, &img_height);
					if (k % 4 == 1)
						img = mlx_xpm_file_to_image(vars.mlx, "Sol2.xpm", &img_width, &img_height);
					if (k % 4 == 2)
						img = mlx_xpm_file_to_image(vars.mlx, "Sol3.xpm", &img_width, &img_height);
					if (k % 4 == 3)
						img = mlx_xpm_file_to_image(vars.mlx, "Sol4.xpm", &img_width, &img_height);
				}
				if (map.map[i][j] == '1')
					img = mlx_xpm_file_to_image(vars.mlx, "Obstacle1.xpm", &img_width, &img_height);
				if (map.map[i][j] == 'E')
					img = mlx_xpm_file_to_image(vars.mlx, "Exit1.xpm", &img_width, &img_height);
				if (map.map[i][j] == 'P')
					img = mlx_xpm_file_to_image(vars.mlx, "Personnage1.xpm", &img_width, &img_height);
				if (map.map[i][j] == 'C')
					img = mlx_xpm_file_to_image(vars.mlx, "Collectible1.xpm", &img_width, &img_height);
				mlx_put_image_to_window(vars.mlx, vars.win, img, j * img_width, i * img_height);
				j++;
			}
			i++;
			j = 0;
		}
		i = 0;
		k++;
		usleep(250000);
	}
	mlx_loop(vars.mlx);
}

int main(int ac, char **av)
{
//	t_vars	vars;
//	t_img	img;
//	t_data	data;
	t_map	map;


	map.length = 0;
	map.height = 0;
	map.nb_exit = 0;
	map.nb_collec = 0;
	map.nb_player = 0;
	map.fd = 0;
	
	if (ac != 2)
		return(printf("Mauvais nombre d'arguments\n"), -1);
	map.fd = open(av[1], O_RDONLY);
	if (map.fd <= 0)
		return(printf("Erreur lors de l'ouverture du fichier"), -1);
	map.height = ft_count_lines(map);
	close(map.fd);
	map.fd = open(av[1], O_RDONLY);
	if (ft_init_map(&map) == -1)
		return(-1);
	printf("Map valide !\n");
	int	i = 0;
	while (map.map[i])
	{
		printf("%s", map.map[i++]);
	}
	printf("hauteur, largeur : %d, %d\n", map.height, map.length);
	printf("Exit : %d, Player : %d, collec : %d\n", map.nb_exit, map.nb_player, map.nb_collec);
	ft_display_map(map);

}





	/*vars.mlx = mlx_init();
	vars.win = mlx_new_window(mlx, 640, 480, "Penis");
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	if (img != NULL)
	{
		while (i * img_width < 640)
		{
			while (j * img_height < 480)
			{
				mlx_put_image_to_window(mlx, win, img, i * img_width, j * img_height);
				j++;
				usleep(100000);
			}
			i++;
			j = 0;
		}
	}
	mlx_loop(mlx);
}*/



/*int main(void)
{
	t_vars	vars;
	t_data img;

	vars.mlx = mlx_init();
	img.img = mlx_new_image(vars.mlx, 640, 480);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello World!");
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
}*/


/*int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 600, "Hello world!");
	img.img = mlx_new_image(mlx, 800, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	ft_put_square(&img, 5, 5, 50, 0x00FF0000);
	ft_put_rainbow(&img, 100, 100, 100);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);

}*/


/*
int	main(void)
{
	t_data	img;
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	img.img = mlx_new_image(mlx, WPIX, HPIX);

	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img_endian);
	
	//mlx_win = mlx_new_window(mlx, WPIX, HPIX, "Hello world!");
	//mlx_loop(mlx);

	
}*/
