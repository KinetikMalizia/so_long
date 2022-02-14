# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcarlen <jcarlen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 11:48:43 by jcarlen           #+#    #+#              #
#    Updated: 2022/02/14 11:50:26 by jcarlen          ###   ########.fr        #
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