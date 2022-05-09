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
	t_img		*img_ptr;
	t_player	player;
	t_player	*player_ptr;
}				t_data;

/*check*/
void	check_player_exit(t_data *data);
void	ft_window_size(t_data *data, char **argv);
void	wall_check(t_data *data);
void	map_length(t_data *data);
void	exit_error(void);
/*brocoli*/
void	reset_brocoli(t_data *data);
int		mvt_check_brocoli(t_data *data);
void	put_brocoli(t_data *data);
void	move_brocoli(t_data *data);
void	find_brocoli(t_data *data);
/*extra*/
void	shoot(t_data *data);
int		randomize(int n);
void	offset(t_data *data);
void	rng(t_data *data);
void	random_input(t_data *data, int keycode);
/*input*/
int		keyhook_inputs(int keycode, t_data *vars);
int		key_hook(t_data *data);
size_t	nblen(int nbr);
char	*ft_itoa(int n);
/*map_init*/
int		ft_count_lines(int fd, int x, int img_w);
int		ft_line_length(int fd);
void	init_map(char *path, t_data *data);
void	rd_map(int fd, t_data *data);
/*print_text*/
void	prline(char *str, int steps);
void	print_hud(t_data *data, char *string);
void	ft_putstr_fd(char *s, int fd);
/*print*/
void	print_wall(t_data *data, int x, int y);
void	turn_player(t_data *data, int type, int w, int h);
void	print_map(t_data *data);
void	print_map_2(t_data *data, int x, int y);
void	print_map_3(t_data *data, int x, int y);
/*print2*/
int		create_back(t_data *data);
void	put_object(t_data *data);
void	print_objects(t_data *data, int x, int y);
/*run_prog*/
void	collect(t_data *data, int new_x, int new_y);
int		mvt_check(t_data *data);
int		mvt_check_1(t_data *data, int new_x, int new_y);
void	put_player(t_data *data);
void	next_frame(t_data *data);
/*setup_memory*/
void	setup_img(t_data *data);
void	setup_img_2(t_data *data, int *height, int *width);
void	setup_wall(t_data *data);
void	setup_player(t_data *data);
/*so_long_utils*/
char	*ft_strjoin_malloc(char *s1, char *buff);
char	*ft_strnstr(const char *s1, const char *s2, unsigned long n);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t c, size_t n);
void	ft_bzero(void *b, size_t len);
/*so_long*/
int		win_exit(int keycode, t_data *vars);
int		cross_exit(int keycode, t_data *data);
void	win_game(t_data *data);
void	free_all(t_data *data);
/*----*/

#endif
