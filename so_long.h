/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 22:51:35 by abiersoh          #+#    #+#             */
/*   Updated: 2021/12/18 05:42:14 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H

//# include "libft/libft.h"
# include "minilibx/mlx_int.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <time.h>
# include "get_next_line.h"

# define W_KEY 119
# define A_KEY 97
# define Z_KEY 122
# define Q_KEY 113
# define S_KEY 115
# define D_KEY 100
# define ESCAPE_KEY 65307
# define UP_KEY 65362
# define LEFT_KEY 65361
# define RIGHT_KEY 65363
# define DOWN_KEY 65364
# define FPS 5

enum {UP, RIGHT, DOWN, LEFT};

/* Structures */

typedef struct s_map
{
	int		fd;
	int		height;
	int		length;
	int		nb_exit;
	int		nb_player;
	int		nb_collec;
	char	**map;
}	t_map;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int		collected;
	int		nb_moves;
	t_map	map;
	int		img_width;
	int		img_height;
	void	**images;
	int		frames;
	int		dir;
	clock_t	begin;
}	t_vars;


void	ft_mlx_close_croix_rouge_de_ses_morts(t_vars *vars);
void	ft_mlx_close(t_vars *vars);
int		exit_hook(t_vars *vars);
void	ft_animate_map(t_vars *vars);
int		handle_no_event(t_vars *vars);
void	**ft_init_images(t_vars *vars);
int		is_adjacent(t_vars *vars, y, x);
void	ft_update_map(t_vars *vars);
void	ft_mlx_close_escape(t_vars *vars);
void	get_coords(t_vars *vars, int *x, int *y);
void	ft_cswitch(char *a, char *b);
int		is_accessible(char c, t_vars vars);
int		ft_move(t_vars *vars, int keycode);
int		key_hook(int keycodem t_vars *vars);
int		ft_check_line(t_map *map, int i);
int		ft_check_first_line(char *str);
int		ft_init_map(t_map *map);
int		ft_count_lines(t_map map);
void	ft_display_map(t_vars *vars);
void	**ft_init_images(t_vars *vars);
void	ft_init_vars(t_vars *vars);
void	ft_delete_vars(t_vars *vars);
int		is_name_valid(char *av);

#endif
