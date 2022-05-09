/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:57:11 by jeancarlen        #+#    #+#             */
/*   Updated: 2022/05/09 12:07:05 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	data->wall_flag = 0;
}

void	print_objects(t_data *data, int x, int y)
{
	if (data->map.map[y][x] == '1')
		print_wall(data, x, y);
	if (data->map.map[y][x] == 'P')
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.player, x * IMG_W, y * IMG_H);
		data->map.play += 1;
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
		data->map.exit += 1;
	find_brocoli(data);
}
