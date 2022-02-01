/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:19:57 by fmalizia          #+#    #+#             */
/*   Updated: 2022/02/01 16:29:21 by fmalizia         ###   ########.fr       */
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

typedef struct s_img
{
	void	*ground;
	void	*wall;
	void	*player;
	void	*collectable;
	void	*exit_s;
	void	*exit_w;
}				t_img;

typedef struct s_player
{
	int	p_x;
	int	p_y;
	int	delta_x;
	int	delta_y;
}				t_player;

typedef struct s_map
{
	char	**map;
	int		x;
	int		y;
	int		collectables;
}				t_map;

typedef struct s_data {
	void		*mlx;
	void		*win;
	int			size_x;
	int			size_y;
	int			steps;
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
void	ft_putstr_fd(char *s, int fd);

#endif