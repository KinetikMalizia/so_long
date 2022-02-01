/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_right.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:45:41 by jeancarlen        #+#    #+#             */
/*   Updated: 2022/02/01 14:36:57 by fmalizia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	wall_check(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < data->size_x / IMG_W)
	{
		y = 0;
		while (y < data->size_y / IMG_H)
		{
			if ((y == 0 || x == 0) && data->map.map[y][x] != '1')
			{
				prline("manque de wall", 0);
				exit(EXIT_FAILURE);
			}
			if ((x == (data->size_x / IMG_H - 1)
					|| y == (data->size_y / IMG_W - 1))
				&& data->map.map[y][x] != '1')
			{
				prline("manque de wall", 0);
				exit(EXIT_FAILURE);
			}
			y++;
		}
		x++;
	}
}

int	mvt_check(t_data *data)
{
	int	new_x;
	int	new_y;

	new_y = data->player.p_y + data->player.delta_y;
	new_x = data->player.p_x + data->player.delta_x;
	if (mvt_check_1(data, new_x, new_y))
		return (1);
	return (0);
}

void	win_game(t_data *data)
{
	data->steps += 1;
	prline("CONGRATULATIONS!\nTotal steps: ", data->steps);
	exit(EXIT_SUCCESS);
}

void	collect(t_data *data, int new_x, int new_y)
{
	data->map.map[new_y][new_x] = '0';
	data->map.collectables -= 1;
}

int	mvt_check_1(t_data *data, int new_x, int new_y)
{
	if (data->map.map[new_y][new_x] == '1')
	{
		prline("can't go through walls!", 0);
		return (0);
	}
	else if (data->map.map[new_y][new_x] == '0')
		return (1);
	else if (data->map.map[new_y][new_x] == 'C')
	{
		collect(data, new_x, new_y);
		return (1);
	}
	else if (data->map.map[new_y][new_x] == 'E')
	{
		if (data->map.collectables == 0)
			win_game(data);
		else
		{
			prline("you didn't eat all the pizzas!", 0);
			return (0);
		}
	}
	return (0);
}
