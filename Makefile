
SRCS		= so_long.c get_next_line.c get_next_line_utils.c \
				srcs/hooks.c \
				srcs/utils.c \
				srcs/bonus_hooks.c \
				srcs/bonus_animation.c \
				srcs/adj_accessible.c \
				srcs/close_functions.c \
				srcs/check_map.c \
				srcs/ft_init_vars.c \
				srcs/ft_delete_vars.c \
				srcs/ft_update_map.c \
				srcs/ft_begin_game.c \
				srcs/ft_move.c

OBJS		= $(SRCS:.c=.o)

CC		= gcc
RM		= rm -rf

CFLAGS = -Wall -Wextra -g3

NAME=	so_long

PATH_MLX		=./minilibx


%.o: %.c
		$(CC) $(CFLAGS) -I /usr/include -Imlx_linux -O3 -c $< -o $@

LINUX		= -I /usr/include -L /usr/lib -L mlx_linux -I mlx_linux -lXext -l X11 -lm -lz

$(NAME): $(OBJS)
		make -C $(PATH_MLX) all
		$(CC) $(CFLAGS) $(OBJS) minilibx/libmlx_Linux.a $(LINUX) -o $(NAME)

all:		$(NAME)

clean:
		make -C $(PATH_MLX) clean
		rm -rf $(OBJS)

fclean:		clean
		make -C $(PATH_MLX) clean
		rm -rf $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
