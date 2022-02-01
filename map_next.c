/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_next.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlen <jcarlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 11:53:50 by fmalizia          #+#    #+#             */
/*   Updated: 2022/02/01 12:34:30 by jcarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			mlx_put_image_to_window(data->mlx, data->win,
				data->img.ground, x, y);
			y += IMG_W;
		}
		x += IMG_H;
	}
	return (0);
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
			print_objects(data, x, y);
			y += 1;
		}
		x += 1;
	}
}

void	print_objects(t_data *data, int x, int y)
{
	if (data->map.map[y][x] == '1')
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.wall, x * IMG_W, y * IMG_H);
	if (data->map.map[y][x] == 'P')
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.player, x * IMG_W, y * IMG_H);
		data->player.p_x = x;
		data->player.p_y = y;
	}
	if (data->map.map[y][x] == 'C')
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.collectable, x * IMG_W, y * IMG_H);
		data->map.collectables += 1;
	}
	if (data->map.map[y][x] == 'E')
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.exit_s, x * IMG_W, y * IMG_H);
}
