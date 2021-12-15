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
#define A_KEY 97
#define W_KEY 119
#define Z_KEY 122
#define Q_KEY 113
#define S_KEY 115
#define D_KEY 100
#define ESCAPE_KEY 65307

static int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char	*ft_strdup(const char *src)
{
	int	i;
	char	*dest;

	dest = malloc(sizeof(char) * ft_strlen(src));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
	
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
	char	**src_images;
}	t_map;

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
	int		collected;
	int		nb_moves;
	t_map	map;
}	t_vars;

typedef struct s_img
{
	void	*img;
	int	img_width;
	int	img_height;
	char	*path;
}	t_img;

void	ft_update_map(t_vars *vars)
{
	int	i;
	int	j;
	void	*img;
	int	img_width;
	int	img_height;

	img = NULL;
	i = 0;
	j = 0;
	while (vars->map.map[i])
	{
		while (vars->map.map[i][j] != '\n')
		{
			if (vars->map.map[i][j] == '0')
				img = mlx_xpm_file_to_image(vars->mlx, "Sol1.xpm", &img_width, &img_height);
			if (vars->map.map[i][j] == '1')
				img = mlx_xpm_file_to_image(vars->mlx, "Obstacle1.xpm", &img_width, &img_height);
			if (vars->map.map[i][j] == 'E')
				img = mlx_xpm_file_to_image(vars->mlx, "Exit1.xpm", &img_width, &img_height);
			if (vars->map.map[i][j] == 'P')
				img = mlx_xpm_file_to_image(vars->mlx, "Personnage1.xpm", &img_width, &img_height);
			if (vars->map.map[i][j] == 'C')
				img = mlx_xpm_file_to_image(vars->mlx, "Collectible1.xpm", &img_width, &img_height);
			mlx_put_image_to_window(vars->mlx, vars->win, img, j * img_width, i * img_height);
			j++;
		}
		i++;
		j = 0;
	}
}

void	ft_mlx_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	ft_update_map(vars);
	printf("collectibles : %d / %d\nMoves : %d\n", vars->collected, vars->map.nb_collec, vars->nb_moves);
	exit(EXIT_SUCCESS);
}

void	get_coords(t_vars *vars, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (vars->map.map[i])
	{
		while (vars->map.map[i][j])
		{
			if (vars->map.map[i][j] == 'P')
			{
				*x = j;
				*y = i;
				return ;
			}
			j++;
		}
		i++;
		j = 0;
	}
	*x = 0;
	*y = 0;
	printf("Perso non trouve\n");
}

void	ft_cswitch(char *a, char *b)
{
	char	tmp;

	tmp = *a;
	printf("switching %c & %c\n", *a, *b);
	*a = *b;
	*b = tmp;
}

int	is_accessible(char c, t_vars vars)
{
	if (c == '1' || (c == 'E' && vars.collected != vars.map.nb_collec))	//update avec counter de collectibles
		return (0);
	return (1);
}

void	ft_move(t_vars *vars, int keycode)
{
	int	x;
	int	y;
	get_coords(vars, &x, &y);
	if (keycode == W_KEY && is_accessible(vars->map.map[y - 1][x], *vars))	//update avec exit et collectibles.
	{
		vars->collected += (vars->map.map[y - 1][x] == 'C');
		vars->nb_moves++;
		if (vars->map.map[y - 1][x] == 'E')
			ft_mlx_close(vars);
		vars->map.map[y][x] = '0';	
		vars->map.map[y - 1][x] = 'P';	
	}
	else if (keycode == S_KEY && is_accessible(vars->map.map[y + 1][x], *vars))	//update avec exit et collectibles.
	{
		vars->collected += (vars->map.map[y + 1][x] == 'C');
		vars->nb_moves++;
		if (vars->map.map[y + 1][x] == 'E')
			ft_mlx_close(vars);
		vars->map.map[y][x] = '0';	
		vars->map.map[y + 1][x] = 'P';	
	}
	else if (keycode == D_KEY && is_accessible(vars->map.map[y][x + 1], *vars))	//update avec exit et collectibles.
	{
		vars->collected += (vars->map.map[y][x + 1] == 'C');
		vars->nb_moves++;
		if (vars->map.map[y][x + 1] == 'E')
			ft_mlx_close(vars);
		vars->map.map[y][x] = '0';	
		vars->map.map[y][x + 1] = 'P';	
	}
	else if (keycode == A_KEY && is_accessible(vars->map.map[y][x - 1], *vars))	//update avec exit et collectibles.
	{
		vars->collected += (vars->map.map[y][x - 1] == 'C');
		vars->nb_moves++;
		if (vars->map.map[y][x - 1] == 'E')
			ft_mlx_close(vars);
		vars->map.map[y][x] = '0';
		vars->map.map[y][x - 1] = 'P';
	}
	printf("collectibles : %d / %d\nMoves : %d\n", vars->collected, vars->map.nb_collec, vars->nb_moves);
}

int	key_hook(int keycode, t_vars *vars)
{
	
	if (keycode == 65307)
		ft_mlx_close(vars);
	if (keycode == W_KEY || keycode == A_KEY || keycode == S_KEY || keycode == D_KEY)
	{
		ft_move(vars, keycode);
		ft_update_map(vars);
	}
	return(keycode);
}

static	char	*ft_strchr(char *str, char c)
{
	while (*str)
		if (*str++ == c)
			return (str - 1);
	return (NULL);
}


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


void	ft_display_map(t_vars *vars)
{
	int	i;
	int	j;
	void	*img;
	int	img_width;
	int	img_height;
//	t_vars	vars;

	img = NULL;
	i = 0;
	j = 0;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 50 * vars->map.length, 50 * vars->map.height, "Thanks for all the fish !");
	while (vars->map.map[i])
	{
		while (vars->map.map[i][j] != '\n')
		{
			if (vars->map.map[i][j] == '0')
				img = mlx_xpm_file_to_image(vars->mlx, "Sol1.xpm", &img_width, &img_height);
			if (vars->map.map[i][j] == '1')
				img = mlx_xpm_file_to_image(vars->mlx, "Obstacle1.xpm", &img_width, &img_height);
			if (vars->map.map[i][j] == 'E')
				img = mlx_xpm_file_to_image(vars->mlx, "Exit1.xpm", &img_width, &img_height);
			if (vars->map.map[i][j] == 'P')
				img = mlx_xpm_file_to_image(vars->mlx, "Personnage1.xpm", &img_width, &img_height);
			if (vars->map.map[i][j] == 'C')
				img = mlx_xpm_file_to_image(vars->mlx, "Collectible1.xpm", &img_width, &img_height);
			mlx_put_image_to_window(vars->mlx, vars->win, img, j * img_width, i * img_height);
			j++;
		}
		i++;
		j = 0;
	}
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_loop(vars->mlx);
}

char	**ft_init_images(void)
{
	char	**dest;

	dest = malloc(sizeof(char *) * 6);
	if (!dest)
		return (NULL);
	dest[0] = ft_strdup("Sol1.xpm");
	dest[1] = ft_strdup("Obstacle1.xpm");
	dest[2] = ft_strdup("Collectible1.xpm");
	dest[3] = ft_strdup("Personnage1.xpm");
	dest[4] = ft_strdup("Exit1.xpm");
	dest[5] = NULL;
	return(dest);
}

void	ft_init_vars(t_vars *vars)
{

	vars->map.length = 0;
	vars->map.height = 0;
	vars->map.nb_exit = 0;
	vars->map.nb_collec = 0;
	vars->map.nb_player = 0;
	vars->map.fd = 0;
	vars->map.src_images = ft_init_images();
	vars->collected = 0;
	vars->nb_moves = 0;
}
int main(int ac, char **av)
{
	t_vars	vars;

	ft_init_vars(&vars);
	if (ac != 2)
		return(printf("Mauvais nombre d'arguments\n"), -1);
	vars.map.fd = open(av[1], O_RDONLY);
	if (vars.map.fd <= 0)
		return(printf("Erreur lors de l'ouverture du fichier"), -1);
	vars.map.height = ft_count_lines(vars.map);
	close(vars.map.fd);
	vars.map.fd = open(av[1], O_RDONLY);
	if (ft_init_map(&vars.map) == -1)
		return(-1);
	printf("Map valide !\n");
	ft_display_map(&vars);
}
