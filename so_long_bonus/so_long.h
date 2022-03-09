/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvnrlen <arvenn@student.42.fr>          +#+  +:+       +#+          */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:19:57 by fmalizia          #+#    #+#             */
/*   Updated: 2022/02/03 11:14:05 by arvn         ###   ########.fr     	  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

# define IMG_W 64
# define IMG_H 64
# define ESC 53
# define W 6
# define A 12
# define S 1
# define D 2
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define MAX_X 5120
# define MAX_Y 1440

typedef struct s_wall
{
	void	*wall1;
	void	*wall2;
	void	*wall3;
	void	*wall4;
}				t_wall;

typedef struct s_img
{
	t_wall		*wall;
	void		*ground;
	void		*player;
	void		*collectable;
	void		*exit_s;
	void		*exit_w;
	void		*hub_bg;
	void		*enemy;
	void		*expl;
	void		*upgrade;
}				t_img;

typedef struct s_player
{
	int	p_x;
	int	p_y;
	int	delta_x;
	int	delta_y;
	int	direction;
	int	collected;
	int	offset;
	int	upgrade;
	int	enemy;
	int	enemy_p_x;
	int	enemy_p_y;
	int	enemy_delta_x;
	int	enemy_delta_y;
}				t_player;

typedef struct s_map
{
	char	**map;
	int		x;
	int		y;
	int		collectables;
	int		play;
	int		exit;
}				t_map;

typedef struct s_data {
	void		*mlx;
	void		*win;
	int			rng;
	int			size_x;
	int			size_y;
	int			steps;
	int			wall_flag;
	int			z;
	int			delay;
	t_map		map;
	t_img		img;
	t_player	player;
}				t_data;

int		win_exit(int keycode, t_data *vars);
int		ft_line_length(int fd);
int		ft_count_lines(int fd, int x, int img_w);
char	*ft_strnstr(const char *s1, const char *s2, unsigned long n);
char	*ft_strjoin_malloc(char *s1, char *buff);
size_t	ft_strlen(const char *s);
int		keyhook_inputs(int keycode, t_data *vars);
void	ft_window_size(t_data *data, char **argv);
void	*ft_calloc(size_t c, size_t n);
void	ft_bzero(void *b, size_t len);
void	init_map(char *path, t_data *data);
void	rd_map(int fd, t_data *data);
int		create_back(t_data *data);
void	put_object(t_data *data);
void	wall_check(t_data *data);
void	setup_img(t_data *data);
void	setup_player(t_data *data);
int		mvt_check(t_data *data);
int		mvt_check_1(t_data *data, int new_x, int new_y);
void	prline(char *str, int steps);
void	win_game(t_data *data);
void	next_frame(t_data *data);
void	put_player(t_data *data);
void	collect(t_data *data, int new_x, int new_y);
void	print_map(t_data *data);
void	print_objects(t_data *data, int x, int y);
void	print_map_2(t_data *data, int x, int y);
void	setup_wall(t_data *data);
void	turn_player(t_data *data, int type, int w, int h);
void	print_wall(t_data *data, int x, int y);
void	check_player_exit(t_data *data);
void	map_length(t_data *data);
void	exit_error(void);
int		key_hook(t_data *data);
char	*ft_itoa(int n);
size_t	nblen(int nbr);
void	print_hud(t_data *data, char *string);
void	ft_putstr_fd(char *s, int fd);
void	shoot(t_data *data);
void	print_map_3(t_data *data, int x, int y);
void	setup_img_2(t_data *data, int *height, int *width);
int		mvt_check_brocoli(t_data *data);
int		mvt_check_1_brocoli(t_data *data, int enemy_new_x, int enemy_new_y);
void	put_brocoli(t_data *data);
void	move_brocoli(t_data *data);
void	find_brocoli(t_data *data);
void	reset_brocoli(t_data *data);
int		randomize(int n);
void	offset(t_data *data);
void	rng(t_data *data);

#endif

/*

check
	map_length /
	check_player_exit
	ft_window_size
	wall_check
input
	keyhook_inputs

map_init
	ft_count_lines
	ft_line_length
	ft_strlen
	init_map
	rd_map
	****************

setup_memory
	setup_wall
	setup_img
	setup_player

run_prog
	collect
	put_player
	next_frame
	mvt_check
	mvt_check_1

print
	print_wall
	turn_player
	print_map
	print_map_2
	*************
	create_back
	put_object
	print_objects

so_long
	main
	win_exit
	win_game

so_long_utils
	ft_strnstr
	ft_strjoin_malloc
	ft_strlen
	ft_calloc
	ft_bzero

print_text
	prline
	ft_putstr_fd
*/

/*
drip de pizza ?
timer ?
refaire la propreté
enemis
regler les offset du hub
*/
