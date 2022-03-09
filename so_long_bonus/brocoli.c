/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 09:48:42 by fmalizia          #+#    #+#             */
/*   Updated: 2022/03/09 15:05:31 by fmalizia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	reset_brocoli(t_data *data)
{
	data->map.y = 0;
	while (data->map.y < data->size_y / IMG_W)
	{
		data->map.x = 0;
		while (data->map.x < data->size_x / IMG_H)
		{
			if (data->map.map[data->map.y][data->map.x] == 'M')
			{
				data->map.map[data->map.y][data->map.x] = 'X';
			}
			data->map.x += 1;
		}
		data->map.y += 1;
	}
	data->map.x = 0;
	data->map.y = 0;
}

int	mvt_check_brocoli(t_data *data)
{
	int	enemy_new_x;
	int	enemy_new_y;

	enemy_new_y = data->player.enemy_p_y + data->player.enemy_delta_y;
	enemy_new_x = data->player.enemy_p_x + data->player.enemy_delta_x;
	if (data->map.map[enemy_new_y][enemy_new_x] == '0')
		return (1);
	if (data->map.map[enemy_new_y][enemy_new_x] == 'P')
		win_exit(0, data);
	data->player.enemy_delta_x = 0;
	data->player.enemy_delta_y = 0;
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

	mov = randomize(data->rng);
	if (mov == 0)
		data->player.enemy_delta_y = -1;
	if (mov == 2)
		data->player.enemy_delta_y = +1;
	if (mov == 1)
		data->player.enemy_delta_x = -1;
	if (mov == 3)
		data->player.enemy_delta_x = +1;
	if (mvt_check_brocoli(data))
		put_brocoli(data);
	data->player.enemy_delta_x = 0;
	data->player.enemy_delta_y = 0;
}
