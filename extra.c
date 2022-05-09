/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeancarlen <jeancarlen@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:55:55 by fmalizia          #+#    #+#             */
/*   Updated: 2022/05/09 22:50:39 by jeancarlen       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	shoot(t_data *data)
{
	int	s;

	s = data->player.p_x + data->player.direction;
	while (s <= data->size_x / IMG_W && s >= 0 && data->player.collected > 0)
	{
		if (data->map.map[data->player.p_y][s] == 'X' ||
			data->map.map[data->player.p_y][s] == 'M')
		{
			print_hud(data, "get wrecked!");
			mlx_put_image_to_window(data->mlx, data->win,
				data->img.expl, s * IMG_W, data->player.p_y * IMG_H);
			data->map.map[data->player.p_y][s] = '0';
			data->player.collected -= 1;
			print_hud(data, 0);
			return ;
		}
		if (data->map.map[data->player.p_y][s] != '0')
		{
			data->player.collected -= 1;
			print_hud(data, 0);
			return ;
		}
		s += data->player.direction;
	}
}

int	randomize(int n)
{
	int	num;

	num = (n * 15) % 17;
	num = (num * 45) % 51;
	num = (num * 86) % 93;
	num = (num * 17) % 4;
	return (num);
}

void	offset(t_data *data)
{
	int	h;
	int	w;

	if (data->z == data->delay * 1 || data->z == data->delay * 3)
		data->player.offset = 2;
	if (data->z == data->delay * 2)
		data->player.offset = 5;
	if (data->z == data->delay * 4)
	{
		data->img.enemy = mlx_xpm_file_to_image(data->mlx,
				"./sprite_xpm/b_electro.xpm", &w, &h);
		data->player.offset = 0;
	}
	if (data->z == data->delay * 5 || data->z == data->delay * 7)
	{
		data->img.enemy = mlx_xpm_file_to_image(data->mlx,
				"./sprite_xpm/b_electro1.xpm", &w, &h);
		data->player.offset = -2;
	}
	if (data->z == data->delay * 6)
		data->player.offset = -5;
	if (data->z == data->delay * 8)
	{
		data->img.enemy = mlx_xpm_file_to_image(data->mlx,
				"./sprite_xpm/brocolenemy.xpm", &w, &h);
		data->player.offset = 0;
		data->z = 0;
	}
}

void	rng(t_data *data)
{
	if (data->z % 1000 == 0)
		data->rng += 3;
	if (data->z == 700 && data->rng > 3)
		data->rng -= 2;
	if (data->z == 500)
		data->rng += 5;
	if (data->rng > 50)
		data->rng = 0;
}

void	random_input(t_data *data, int keycode)
{
	if (keycode == UP || keycode == W)
		data->rng += 10;
	if (keycode == DOWN || keycode == S)
		data->rng *= 2;
	if (keycode == LEFT || keycode == A)
		data->rng += 2;
	if (keycode == RIGHT || keycode == D)
		data->rng /= 2;
}
