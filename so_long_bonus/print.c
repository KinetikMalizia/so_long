/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlen <jcarlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:56:46 by jeancarlen        #+#    #+#             */
/*   Updated: 2022/05/06 14:50:09 by jcarlen          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_wall(t_data *data, int x, int y)
{
	if (data->wall_flag == 0)
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.wall->wall1, x * IMG_W, y * IMG_H);
		data->wall_flag += 1;
	}
	else if (data->wall_flag == 1)
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.wall->wall2, x * IMG_W, y * IMG_H);
		data->wall_flag += 1;
	}
	else if (data->wall_flag == 2)
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.wall->wall3, x * IMG_W, y * IMG_H);
		data->wall_flag += 1;
	}
	else if (data->wall_flag == 3)
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.wall->wall4, x * IMG_W, y * IMG_H);
		data->wall_flag = 0;
	}
}

void	turn_player(t_data *data, int type, int w, int h)
{
	if (type == 1)
		data->player.delta_y = -1;
	if (type == 2)
		data->player.delta_y = +1;
	if (type == 3)
	{
		data->img.player = mlx_xpm_file_to_image(data->mlx,
				"./sprite_xpm/supervan_L.xpm", &w, &h);
		data->player.delta_x = -1;
		data->player.direction = -1;
	}
	if (type == 4)
	{
		data->img.player = mlx_xpm_file_to_image(data->mlx,
				"./sprite_xpm/supervan_R.xpm", &w, &h);
		data->player.delta_x = +1;
		data->player.direction = +1;
	}
	reset_brocoli(data);
}

void	print_map(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < data->size_x / IMG_W)
	{
		y = 0;
		while (y < data->size_y / IMG_H)
		{
			print_map_2(data, x, y);
			y += 1;
		}
		x += 1;
	}
	data->wall_flag = 0;
}

void	print_map_2(t_data *data, int x, int y)
{
	if (data->map.map[y][x] == '1')
		print_wall(data, x, y);
	else
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.ground, x * IMG_W, y * IMG_H);
	if (data->map.map[y][x] == 'P')
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.player, x * IMG_W, y * IMG_H + data->player.offset);
	print_map_3(data, x, y);
}

void	print_map_3(t_data *data, int x, int y)
{
	if (data->map.map[y][x] == 'C')
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.collectable, x * IMG_W, y * IMG_H);
	if (data->map.map[y][x] == 'U')
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.upgrade, x * IMG_W, y * IMG_H);
	if (data->map.map[y][x] == 'X' || data->map.map[y][x] == 'M' )
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.enemy, x * IMG_W + (data->player.offset / 2),
			y * IMG_H + data->player.offset);
	if (data->map.map[y][x] == 'E')
	{
		if (data->map.collectables > 0)
			mlx_put_image_to_window(data->mlx, data->win,
				data->img.exit_s, x * IMG_W, y * IMG_H);
		else
			mlx_put_image_to_window(data->mlx, data->win,
				data->img.exit_w, x * IMG_W, y * IMG_H);
	}
}
