/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 17:11:03 by abiersoh          #+#    #+#             */
/*   Updated: 2021/12/21 09:12:49 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "minilibx/mlx.h"
# include "minilibx/mlx_int.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <time.h>
# include "gnl/get_next_line.h"

# define ACCESSIBLE_CASE "0CRLBd"
# define R_KEY 114
# define W_KEY 119
# define A_KEY 97
# define Z_KEY 122
# define P_KEY 112
# define Q_KEY 113
# define S_KEY 115
# define D_KEY 100
# define ESCAPE_KEY 65307
# define UP_KEY 65362
# define LEFT_KEY 65361
# define RIGHT_KEY 65363
# define DOWN_KEY 65364
# define FPS 5
# define WLENGTH 1600
# define WHEIGHT 850

enum {up, right, down, left};

/* Structures */

typedef struct s_map
{
	int		fd;
	int		height;
	int		length;
	int		nb_exit;
	int		nb_player;
	int		nb_collec;
	char	*path;
	char	**map;//free et reload
}	t_map;

typedef struct s_vars
{
	void	*mlx;//clear only
	void	*win;//clear only
	char	*settings;
	char	*objectif;
	char	*mobs_to_kill;
	int		killed;
	int		level;
	int		to_kill;
	int		collected;//0
	int		nb_moves;//0
	int		img_width;
	int		img_height;
	int		frames;//0
	int		dir;//0
	int		pause;
	int		x;
	int		y;
	int		offset_x;
	int		offset_y;
	clock_t	begin;//clock()
	void	**images;
	t_map	map;

}	t_vars;

void	ft_mlx_close_croix_rouge_de_ses_morts(t_vars *vars);
void	ft_mlx_close(t_vars *vars);
void	ft_mlx_close_game(t_vars *vars);
int		exit_hook(t_vars *vars);
void	ft_animate_map(t_vars *vars);
int		handle_no_event(t_vars *vars);
void	**ft_init_images(t_vars *vars);
void	ft_init_images_p2(void **images, t_vars *vars);
int		is_adjacent(t_vars *vars, int y, int x);
void	ft_update_map(t_vars *vars);
void	ft_update_full_map(t_vars *vars);
void	ft_mlx_close_end_level(t_vars *vars);
void	get_coords(t_vars *vars, int *x, int *y);
void	ft_cswitch(char *a, char *b);
int		is_accessible(t_vars vars, int x, int y, int dir);
int		is_accessible_up(t_vars vars, int x, int y);
int		is_accessible_down(t_vars vars, int x, int y);
int		is_accessible_right(t_vars vars, int x, int y);
int		is_accessible_left(t_vars vars, int x, int y);
int		ft_move(t_vars *vars, int keycode);
int		ft_check_up(t_vars *vars, int x, int y);
int		ft_check_down(t_vars *vars, int x, int y);
int		ft_check_right(t_vars *vars, int x, int y);
int		ft_check_left(t_vars *vars, int x, int y);
void	ft_move_up(t_vars *vars, int x, int y);
void	ft_move_down(t_vars *vars, int x, int y);
void	ft_move_right(t_vars *vars, int x, int y);
void	ft_move_left(t_vars *vars, int x, int y);
int		manage_keycode(t_vars *vars, int keycode, int x, int y);
int		key_hook(int keycode, t_vars *vars);
int		ft_check_line(t_map *map, int i);
int		ft_check_first_line(char *str);
int		ft_init_map(t_map *map);
int		ft_count_lines(t_map map);
int		ft_pat_patrouille(t_vars *vars);
int		ft_pat_right(t_vars *vars, int i, int *j);
int		ft_pat_left(t_vars *vars, int i, int j);
void	ft_put_img(t_vars *vars, int index, int i, int j);
void	ft_put_img_classic(t_vars *vars, int index, int i, int j);
void	ft_display_map(t_vars *vars);
void	ft_setup_hooks(t_vars *vars);
void	ft_begin_game(t_vars *vars);
void	**ft_init_images(t_vars *vars);
void	ft_init_vars(t_vars *vars);
void	ft_delete_vars(t_vars *vars);
void	check_doors(t_vars *vars);
void	open_doors(t_vars *vars);
void	close_doors(t_vars *vars);
int		ft_attack(t_vars *vars);
int		ft_attack_up(t_vars *vars, int x, int y);
int		ft_attack_down(t_vars *vars, int x, int y);
int		ft_attack_right(t_vars *vars, int x, int y);
int		ft_attack_left(t_vars *vars, int x, int y);
int		is_name_valid(char *av);
int		ft_play(t_vars *vars, char *av, int index);
void	*read_image(t_vars *vars, char *path);
int		ft_strlen(const char *str);
char	*ft_strchr(char *str, char c);
char	*ft_strdup(char *s);
char	*ft_so_long_strndup(char *s, int n);
int		ft_read_map(t_map *map);
void	ft_mlx_restart(t_vars *vars);
int		ft_atoi(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strjoin2(char *s1, char *s2, int a, int b);
char	*ft_itoa(int n);
void	ft_print_data(t_vars *vars);
void	ft_print_data_ennemy(t_vars *vars);
void	ft_print_case(t_vars *vars, char c, int i, int j);
void	ft_fill_coraux_bizarres(t_vars *vars);
void	ft_calcul_offset(t_vars *vars, int *imin, int *imax, int *jmin, int *jmax);
void	ft_calcul_decalage(t_vars *vars, int *offset_x, int *offset_y);
int		min(int a, int b);
int		max(int a, int b);
#endif
