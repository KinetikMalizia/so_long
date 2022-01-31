/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeancarlen <jeancarlen@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:07:45 by jeancarlen        #+#    #+#             */
/*   Updated: 2022/01/28 15:15:19 by jeancarlen       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    exit_error(void);

void    exit_error(void)
{
	prline("Error\nwrong map dimensions");
	exit(EXIT_FAILURE);
}

int	ft_line_length(int fd)
{
	char	buffer[1];
	int		length;
	int		bytes;

	buffer[0] = '\0';
	bytes = 1;
	length = 0;
	while (bytes == 1)
	{
		bytes = read(fd, buffer, 1);
		if (buffer[0] != '\n')
			length++;
		else
			break ;
	}
	return (length);
}

int	ft_count_lines(int fd, int x, int img_w)
{
	char	buffer[1];
	int		linecount;
	int		bytes;
	int		i;

	i = 0;
	buffer[0] = '\0';
	linecount = 1;
	bytes = 1;
	while (bytes == 1)
	{
		bytes = read(fd, buffer, 1);
		if (bytes != 1 && i != (x / img_w))
			exit_error();
		if (i == (x / img_w))
		{
			linecount++;
			i = 0;
		}
		else
			i++;
	}
	return (linecount);
}

void	ft_window_size(t_data *data, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error\nInvalid map_path/map\n");
		exit(EXIT_FAILURE);
	}
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
	{
		prline("Error\nmap has to be .ber");
		exit(EXIT_FAILURE);
	}
	data->size_x = (ft_line_length(fd) * IMG_W);
	data->size_y = (ft_count_lines(fd, data->size_x, IMG_W) * IMG_H);
}
void	init_map(char *path, t_data *data)
{
	int fd;
	
	fd = open(path, O_RDONLY);
	rd_map(fd, data);
	setup_img(data);
	create_back(data);
	setup_player(data);
	put_object(data);
	wall_check(data);
}

void	rd_map(int fd, t_data *data)
{
	char	buffer[2];
	int		i;
	int		bytes;

	buffer[1] = '\0';
	bytes = 1;
	i = 0;
	while (bytes == 1)
	{
		bytes = read(fd, buffer, 1);
		if (bytes != 1)
			break ;
		if (buffer[0] != '\n')
		{
			data->map.map[i] = ft_strjoin_malloc(data->map.map[i], buffer);
		}
		else
			++i;
	}
	data->map.collectables = 0;
}

int	create_back(t_data *data)
{
	int		x;
	int		y;

	x = 0;
	while (x < data->size_x)
	{
		y = 0;
		while (y < data->size_y)
		{
			mlx_put_image_to_window(data->mlx, data->win, data->img.ground, x, y);
			y += IMG_W;
		}
		x += IMG_H;
	}
	return(0);
}

void	put_object(t_data *data)
{
	int		x;
	int		y;

	x = 0;
	while (x < data->size_x / IMG_W)
	{
		y = 0;
		while (y < data->size_y / IMG_H)
		{
			if(data->map.map[y][x] == '1')
				mlx_put_image_to_window(data->mlx, data->win, data->img.wall, x * IMG_W, y * IMG_H);
			if(data->map.map[y][x] == 'P')
			{
				mlx_put_image_to_window(data->mlx, data->win, data->img.player, x * IMG_W, y * IMG_H);
				data->player.p_x = x;
				data->player.p_y = y; //remplacer par la fonction put player
			}
			if(data->map.map[y][x] == 'C')
			{
				mlx_put_image_to_window(data->mlx, data->win, data->img.collectable, x * IMG_W, y * IMG_H);
				data->map.collectables += 1;
			}
			if(data->map.map[y][x] == 'E')
				mlx_put_image_to_window(data->mlx, data->win, data->img.exit_s, x * IMG_W, y * IMG_H);
			y += 1;
		}
		x += 1;	
	}
}
/*droite = x+1 gauche = x-1
	haut = y-1 bas = y+1*/