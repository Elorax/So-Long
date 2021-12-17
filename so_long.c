#include "./minilibx/mlx.h"
//#include "so_long.h"

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include <fcntl.h>
#include <time.h>
#define UP_KEY 65362
#define LEFT_KEY 65361
#define RIGHT_KEY 65363
#define DOWN_KEY 65364
#define A_KEY 97
#define W_KEY 119
#define Z_KEY 122
#define Q_KEY 113
#define S_KEY 115
#define D_KEY 100
#define ESCAPE_KEY 65307
#define FPS 5


enum {UP, RIGHT, DOWN, LEFT};

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
	char	**map;
}	t_map;

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
	int		collected;
	int		nb_moves;
	t_map	map;
	int	img_width;
	int	img_height;
	void	**images;
	int	frames;
	int	dir;
	clock_t	begin;
}	t_vars;


void	ft_mlx_close(t_vars *vars);

typedef struct s_img
{
	void	*img;
	int	img_width;
	int	img_height;
	char	*path;
}	t_img;

int	exit_hook(t_vars *vars)
{
	printf("On quitte avec la croix rouge\n");
	key_hook(65307, vars);
	//ft_mlx_close(vars);
	return (0);
}

void	ft_animate_map(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	printf("Animation !\n");
	vars->frames++;
	while(vars->map.map[i])
	{
		while (vars->map.map[i][j])
		{
			if (vars->map.map[i][j] == '0')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->images[(vars->frames % 4)], j * vars->img_width, i*vars->img_height);
			if (vars->map.map[i][j] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->images[4 + (vars->frames % 4)], j * vars->img_width, i*vars->img_height);
			j++;
		}
		i++;
		j = 0;
	}
	printf("Animation terminee !\n");
}
//Fonction bonus
int	handle_no_event(t_vars *vars)
{
//	static clock_t begin = clock();
	clock_t		current = clock();
	if (((current - vars->begin) / (CLOCKS_PER_SEC / FPS)) > vars->frames)
	{
	//	vars->frames++;
		ft_animate_map(vars);
		printf("frame %d\n", vars->frames);	
	}
//	if(!(count % 20000))
//		ft_animate_map(vars);
	return (0);
}

void	**ft_init_images(t_vars *vars);

int	is_adjacent(t_vars *vars, int y, int x)
{
//	printf("On entre dans adjacent\n");
	if (!x || !y || x == vars->map.length - 1 || y == vars->map.height - 1)
		return (0);
	if (vars->map.map[y - 1][x] == 'P')
		return (1);
	if (vars->map.map[y][x] == 'P')
		return (1);
	if (vars->map.map[y + 1][x] == 'P')
		return (1);
	if (vars->map.map[y][x + 1] == 'P')
		return (1);
	if (vars->map.map[y][x - 1] == 'P')
		return (1);
	return (0);
}
/*Fonction bonus*/

void	ft_update_map(t_vars *vars)
{
	int	i;
	int	j;
	//void	*img;
	//int	img_width;
	//int	img_height;
	int	adj;

	adj = 0;
	//img = NULL;
	i = 0;
	j = 0;
	while (vars->map.map[i])
	{
		while (vars->map.map[i][j] != '\n')
		{	
			adj = is_adjacent(vars, i, j);
			if (vars->map.map[i][j] == '0' && adj)
				mlx_put_image_to_window(vars->mlx, vars->win, vars->images[0], j * vars->img_width, i * vars->img_height);
			if (vars->map.map[i][j] == '1' && adj)
				mlx_put_image_to_window(vars->mlx, vars->win, vars->images[13], j * vars->img_width, i * vars->img_height);
			if (vars->map.map[i][j] == 'E' && adj)
				mlx_put_image_to_window(vars->mlx, vars->win, vars->images[12], j * vars->img_width, i * vars->img_height);
			if (vars->map.map[i][j] == 'P')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->images[8 + vars->dir], j * vars->img_width, i * vars->img_height);
			if (vars->map.map[i][j] == 'C' && adj)
				mlx_put_image_to_window(vars->mlx, vars->win, vars->images[4], j * vars->img_width, i * vars->img_height);
			j++;
		}
		i++;
		j = 0;
	}
}

void	ft_mlx_close(t_vars *vars)
{
	if (vars->win != NULL)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		vars->win = NULL;	
	}
//	ft_update_map(vars);
	printf("collectibles : %d / %d\nMoves : %d\n", vars->collected, vars->map.nb_collec, vars->nb_moves);
//	exit(EXIT_SUCCESS);
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
	if (c == '1' || (c == 'E' && vars.collected != vars.map.nb_collec))
		return (0);
	return (1);
}

int	ft_move(t_vars *vars, int keycode)
{
	int	x;
	int	y;
	get_coords(vars, &x, &y);
	if ((keycode == W_KEY || keycode == UP_KEY || keycode == Z_KEY) && is_accessible(vars->map.map[y - 1][x], *vars))
	{
		vars->collected += (vars->map.map[y - 1][x] == 'C');
		vars->nb_moves++;
		vars->dir = UP;
		if (vars->map.map[y - 1][x] == 'E')
			return (0);
		vars->map.map[y][x] = '0';	
		vars->map.map[y - 1][x] = 'P';	
		printf("collectibles : %d / %d\nMoves : %d\n", vars->collected, vars->map.nb_collec, vars->nb_moves);
	}
	else if ((keycode == S_KEY || keycode == DOWN_KEY) && is_accessible(vars->map.map[y + 1][x], *vars))
	{
		vars->collected += (vars->map.map[y + 1][x] == 'C');
		vars->nb_moves++;
		vars->dir = DOWN;
		if (vars->map.map[y + 1][x] == 'E')
			return (0);
		vars->map.map[y][x] = '0';	
		vars->map.map[y + 1][x] = 'P';	
		printf("collectibles : %d / %d\nMoves : %d\n", vars->collected, vars->map.nb_collec, vars->nb_moves);
	}
	else if ((keycode == D_KEY || keycode == RIGHT_KEY) && is_accessible(vars->map.map[y][x + 1], *vars))
	{
		vars->collected += (vars->map.map[y][x + 1] == 'C');
		vars->nb_moves++;
		vars->dir = RIGHT;
		if (vars->map.map[y][x + 1] == 'E')
			return (0);
		vars->map.map[y][x] = '0';	
		vars->map.map[y][x + 1] = 'P';	
		printf("collectibles : %d / %d\nMoves : %d\n", vars->collected, vars->map.nb_collec, vars->nb_moves);
	}
	else if ((keycode == A_KEY || keycode == Q_KEY || keycode == LEFT_KEY) && is_accessible(vars->map.map[y][x - 1], *vars))
	{
		vars->collected += (vars->map.map[y][x - 1] == 'C');
		vars->nb_moves++;
		vars->dir = LEFT;
		if (vars->map.map[y][x - 1] == 'E')
			return (0);
		vars->map.map[y][x] = '0';
		vars->map.map[y][x - 1] = 'P';
		printf("collectibles : %d / %d\nMoves : %d\n", vars->collected, vars->map.nb_collec, vars->nb_moves);
	}
	return (1);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		ft_mlx_close(vars);
	if (keycode == W_KEY || keycode == A_KEY || keycode == S_KEY || keycode == D_KEY || keycode == UP_KEY || keycode == DOWN_KEY || keycode == RIGHT_KEY || keycode == LEFT_KEY || keycode == Z_KEY || keycode == Q_KEY)
	{
		if (ft_move(vars, keycode))	
			ft_update_map(vars);
		else
			ft_mlx_close(vars);
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
	map->map = malloc(sizeof(char *) * (map->height + 1));
	if (!(map->map))
		return (-1);//Gerer
	map->map[i] = get_next_line(map->fd);
	while (map->map[i])
	{
		if (ft_check_line(map, i) != 0)
			return(printf("Erreur : Mauvaise map.\n"), -1);
		if (i > 0 && ft_strlen(map->map[i]) != ft_strlen(map->map[i - 1]))
			return(printf("Erreur : Mauvaise map.\n"), -1);
		i++;
		map->map[i] = get_next_line(map->fd);
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
		free(str);
		str = get_next_line(map.fd);
		i++;
	}
	return (i);
}


void	ft_display_map(t_vars *vars)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 50 * vars->map.length, 50 * vars->map.height, "Thanks for all the fish !");
	vars->images = ft_init_images(vars);
	while (vars->map.map[i])
	{
		while (vars->map.map[i][j] != '\n')
		{
			if (vars->map.map[i][j] == '0')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->images[0], j * vars->img_width, i * vars->img_height);
			if (vars->map.map[i][j] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->images[13], j * vars->img_width, i * vars->img_height);
			if (vars->map.map[i][j] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->images[12], j * vars->img_width, i * vars->img_height);
			if (vars->map.map[i][j] == 'P')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->images[8], j * vars->img_width, i * vars->img_height);
			if (vars->map.map[i][j] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->images[4], j * vars->img_width, i * vars->img_height);
			j++;
		}
		i++;
		j = 0;
	}
	mlx_loop_hook(vars->mlx, &handle_no_event, vars);
	mlx_hook(vars->win, 17, 0, exit_hook, vars);
	mlx_key_hook(vars->win, key_hook, vars);
}

void	**ft_init_images(t_vars *vars)
{
	void	**images;

	images = malloc(sizeof(*images) * 15);
	if (!images)
		return (NULL);
	images[0] = mlx_xpm_file_to_image(vars->mlx, "Sol1.xpm", &vars->img_width, &vars->img_height);
	images[1] = mlx_xpm_file_to_image(vars->mlx, "Sol2.xpm", &vars->img_width, &vars->img_height);
	images[2] = mlx_xpm_file_to_image(vars->mlx, "Sol3.xpm", &vars->img_width, &vars->img_height);
	images[3] = mlx_xpm_file_to_image(vars->mlx, "Sol4.xpm", &vars->img_width, &vars->img_height);

	images[4] = mlx_xpm_file_to_image(vars->mlx, "Collectible1.xpm", &vars->img_width, &vars->img_height);
	images[5] = mlx_xpm_file_to_image(vars->mlx, "Collectible2.xpm", &vars->img_width, &vars->img_height);
	images[6] = mlx_xpm_file_to_image(vars->mlx, "Collectible3.xpm", &vars->img_width, &vars->img_height);
	images[7] = mlx_xpm_file_to_image(vars->mlx, "Collectible4.xpm", &vars->img_width, &vars->img_height);
	
	images[8] = mlx_xpm_file_to_image(vars->mlx, "Personnage1.xpm", &vars->img_width, &vars->img_height);
	images[9] = mlx_xpm_file_to_image(vars->mlx, "Personnage2.xpm", &vars->img_width, &vars->img_height);
	images[10] = mlx_xpm_file_to_image(vars->mlx, "Personnage3.xpm", &vars->img_width, &vars->img_height);
	images[11] = mlx_xpm_file_to_image(vars->mlx, "Personnage4.xpm", &vars->img_width, &vars->img_height);

	images[12] = mlx_xpm_file_to_image(vars->mlx, "Exit1.xpm", &vars->img_width, &vars->img_height);
	images[13] = mlx_xpm_file_to_image(vars->mlx, "Obstacle1.xpm", &vars->img_width, &vars->img_height);
	images[14] = NULL;
	printf("Coucou\n");
	return(images);
}

void	ft_init_vars(t_vars *vars)
{
	vars->map.length = 0;
	vars->map.height = 0;
	vars->map.nb_exit = 0;
	vars->map.nb_collec = 0;
	vars->map.nb_player = 0;
	vars->map.fd = 0;
	//vars->images = ft_init_images(vars);
	vars->collected = 0;
	vars->nb_moves = 0;
	vars->frames = 0;
	vars->dir = UP;
	vars->begin = clock();
}

void	ft_delete_vars(t_vars *vars)
{
	int	i;

	i = -1;
	while (vars->map.map[++i])
		free(vars->map.map[i]);
	free(vars->map.map);
	i = -1;
	while (vars->images[++i])
	{
		mlx_destroy_image(vars->mlx, vars->images[i]);
	}
	free(vars->images);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
}

int main(int ac, char **av)
{
	t_vars	vars;
	int	i = 1;
	if (ac < 2)
		return(printf("Mauvais nombre d'arguments\n"), -1);
	while (av[i])
	{
		ft_init_vars(&vars);
		vars.map.fd = open(av[i], O_RDONLY);
		if (vars.map.fd <= 0)
			return(printf("Erreur lors de l'ouverture du fichier"), -1);
		vars.map.height = ft_count_lines(vars.map);
		close(vars.map.fd);
		vars.map.fd = open(av[i], O_RDONLY);
		if (ft_init_map(&vars.map) == -1)
			return(-1);
		printf("Map valide !\n");
		close(vars.map.fd);
		ft_display_map(&vars);
		mlx_loop(vars.mlx);
		printf("test ! \n");
		i++;
		ft_delete_vars(&vars);
	}
	printf("tout s'est bien passe\n");
}
