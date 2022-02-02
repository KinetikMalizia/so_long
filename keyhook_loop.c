/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:16:18 by jeancarlen        #+#    #+#             */
/*   Updated: 2022/02/02 15:58:58 by fmalizia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keyhook_inputs(int keycode, t_data *data)
{
	int	w;
	int	h;

	if (keycode == ESC)
		win_exit(keycode, data);
	if (keycode == UP || keycode == W)
		turn_player(data, 1, w, h);
	if (keycode == DOWN || keycode == S)
		turn_player(data, 2, w, h);
	if (keycode == LEFT || keycode == A)
		turn_player(data, 3, w, h);
	if (keycode == RIGHT || keycode == D)
		turn_player(data, 4, w, h);
	next_frame(data);
	return (0);
}

void	next_frame(t_data *data)
{
	if (mvt_check(data))
	{
		put_player(data);
		data->steps += 1;
		prline("steps: ", data->steps);
	}
	data->player.delta_x = 0;
	data->player.delta_y = 0;
	print_map(data);
}

void	put_player(t_data *data)
{
	int	new_x;
	int	new_y;

	new_y = data->player.p_y + data->player.delta_y;
	new_x = data->player.p_x + data->player.delta_x;
	data->map.map[data->player.p_y][data->player.p_x] = '0';
	data->map.map[new_y][new_x] = 'P';
	data->player.p_x = new_x;
	data->player.p_y = new_y;
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
			data->img.player, x * IMG_W, y * IMG_H);
	if (data->map.map[y][x] == 'C')
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.collectable, x * IMG_W, y * IMG_H);
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
