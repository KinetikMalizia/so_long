# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/18 10:24:30 by fmalizia          #+#    #+#              #
#    Updated: 2022/01/19 11:49:02 by fmalizia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = so_long.c

OBJS = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra

$(NAME):	$(OBJS)
			gcc $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
		gcc -Iminilibx -c $< -o $@

all: $(NAME)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: flcean all

.PHONY: all clean fcelan re 
