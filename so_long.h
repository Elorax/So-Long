/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 22:51:35 by abiersoh          #+#    #+#             */
/*   Updated: 2021/12/17 01:21:59 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
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

/*typedef struct s_map
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
	int		collected;
	int		nb_moves;
	int		img_width;
	int		img_height;
	void	*mlx;
	void	*win;
	void	**images;
	t_map	map;
}	t_vars;
*/
/*int	handle_no_event(t_vars *vars);
void	**ft_init_images(t_vars *vars);
void	ft_update_map(t_vars *vars);
int		is_adjacent(t_vars *vars, int y, int x);
void	ft_mlx_close(t_vars *vars);
void	get_coords(t_vars *vars, int *x, int *y);
void	ft_cswitch(char *a, char *b);
int		is_accessible(char c, t_vars vars);
void	ft_move(t_vars *vars, int keycode);
int		key_hook(int keycodem t_vars *vars);
int		ft_check_line(t_map *map, int i);
*/