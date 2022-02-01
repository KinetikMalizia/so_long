# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcarlen <jcarlen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/20 14:18:51 by jeancarlen        #+#    #+#              #
#    Updated: 2022/02/01 14:06:06 by jcarlen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC	=	so_long.c\
		map.c\
		so_long_utils.c\
		keyhook_loop.c\
		check_if_right.c\
		setup_img.c\
		so_long_utils2.c\
		map_next.c\


OBJS = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra

$(NAME): $(OBJS)
				gcc $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
		gcc -Iminilibx -c $< -o $@

all: $(NAME)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 