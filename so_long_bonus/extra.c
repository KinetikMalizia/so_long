/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeancarlen <jeancarlen@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:55:55 by fmalizia          #+#    #+#             */
/*   Updated: 2022/03/08 22:07:34 by jeancarlen       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	shoot(t_data *data)
{
	int	s;

	s = data->player.p_x + data->player.direction;
	while (s <= data->size_x / IMG_W && s >= 0 && data->player.collected > 0)
	{
		if (data->map.map[data->player.p_y][s] == 'X')
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

int	mvt_check_brocoli(t_data *data)
{
	int	enemy_new_x;
	int	enemy_new_y;

	enemy_new_y = data->player.enemy_p_y + data->player.enemy_delta_y;
	enemy_new_x = data->player.enemy_p_x + data->player.enemy_delta_x;
	if (mvt_check_1_brocoli(data, enemy_new_x, enemy_new_y))
		return (1);
	data->player.enemy_delta_x = 0;
	data->player.enemy_delta_y = 0;
	return (0);
}

int	mvt_check_1_brocoli(t_data *data, int enemy_new_x, int enemy_new_y)
{
	if (data->map.map[enemy_new_y][enemy_new_x] == '0')
		return (1);
	if (data->map.map[enemy_new_y][enemy_new_x] == 'P')
		win_exit(0, data);
	return (0);
}

void	put_brocoli(t_data *data)
{
	int	enemy_new_x;
	int	enemy_new_y;

	enemy_new_y = data->player.enemy_p_y + data->player.enemy_delta_y;
	enemy_new_x = data->player.enemy_p_x + data->player.enemy_delta_x;
	data->map.map[data->player.enemy_p_y][data->player.enemy_p_x] = '0';
	data->map.map[enemy_new_y][enemy_new_x] = 'M';
	data->player.enemy_p_x = 0;
	data->player.enemy_p_y = 0;
}

void	move_brocoli(t_data *data)
{
	int	mov;

	mov = 0;
	while (!mov)
	{
		if (data->rng >= 0 && data->rng <= 25)
			data->player.enemy_delta_y = -1;
		else if (data->rng >= 0 && data->rng <= 50)
			data->player.enemy_delta_y = +1;
		else if (data->rng >= 0 && data->rng <= 75)
			data->player.enemy_delta_x = -1;
		else if (data->rng >= 0 && data->rng <= 99)
			data->player.enemy_delta_x = +1;
		mov = mvt_check_brocoli(data);
		data->rng += 1;
	}
	put_brocoli(data);
	data->player.enemy_delta_x = 0;
	data->player.enemy_delta_y = 0;
}
