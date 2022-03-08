# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arvnrlen <arvn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/20 14:18:51 by jeancarlen        #+#    #+#              #
#    Updated: 2022/02/03 11:57:0 by arvn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC	=	so_long.c\
		check.c\
		input.c\
		map_init.c\
		setup_memory.c\
		run_prog.c\
		print.c\
		print2.c\
		so_long_utils.c\
		print_text.c\
		extra.c\
		extra2.c\


OBJS = $(SRC:.c=.o)

MLX = ./mlx

CFLAGS = -Wall -Werror -Wextra

$(NAME): $(OBJS)
				@make -C $(MLX)
				gcc $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
		gcc -Iminilibx -c $< -o $@

all: $(NAME)

clean:
		rm -f $(OBJS)

mlxclean:
			@make clean -C $(MLX)

reset: mlxclean fclean

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re mlxclean reset