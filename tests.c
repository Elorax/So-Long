#include "./minilibx/include/mlx.h"

#define HPIX 600
#define WPIX 800
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;

}

void	ft_put_square(t_data *data, int x, int y, int size, int color)
{
	int	i = 0;
	int	j = 0;
	while (i < size)
	{
		while (j < size)
		{
			ft_mlx_pixel_put(data, x + i, y + j, color);
			j++;
		}
		i++;
		j = 0;
	}
}

int	key_hook(int keycode, t_vars *vars)
{
	
	if (keycode == 65307)
		ft_mlx_close(vars);
	static int	i = 0;
	if (keycode == UP_ARROW_KEY)
	{
		t_data img;
	
		img.img = mlx_new_image(vars->mlx, 640, 480);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
		int j = 0;
		i++;
		while (j < i)
		{
			ft_put_square(&img, 50 * j, 50 * j, 50, 0x00FF0000 + 0xFF00 * (j % 100 == 50));
			j++;
		}
		mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
	}
	return(printf("Hello from key_hook %d!\n", keycode));
}





int main(void)
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*relative_path = "./bite.xpm";
	int	img_width;
	int	img_height;
	
	int	i;
	int	j;

	i = 0;
	j = 0;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 640, 480, "Penis");
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
}



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
