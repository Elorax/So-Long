
SRCS		= so_long.c get_next_line.c get_next_line_utils.c

OBJS		= $(SRCS:.c=.o)

CC		= gcc
RM		= rm -rf

CFLAGS = -Wall -Wextra

NAME=	so_long

PATH_MLX		=./minilibx


%.o: %.c
		$(CC) $(CFLAGS) -I /usr/include -Imlx_linux -O3 -c $< -o $@

LINUX		= -I /usr/include -L /usr/lib -L mlx_linux -I mlx_linux -lXext -l X11 -lm -lz

$(NAME): $(OBJS)
		make -C $(PATH_MLX) all
		$(CC) $(OBJS) minilibx/libmlx_Linux.a $(LINUX) -o $(NAME)

all:		$(NAME)

clean:
		make -C $(PATH_MLX) clean
		rm -rf $(OBJS)

fclean:		clean
		make -C $(PATH_MLX) clean
		rm -rf $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
