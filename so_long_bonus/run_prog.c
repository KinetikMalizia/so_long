/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_prog.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:48:42 by jeancarlen        #+#    #+#             */
/*   Updated: 2022/03/04 16:30:03 by fmalizia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collect(t_data *data, int new_x, int new_y)
{
	data->map.map[new_y][new_x] = '0';
	data->map.collectables -= 1;
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

int	mvt_check_1(t_data *data, int new_x, int new_y)
{
	if (data->map.map[new_y][new_x] == '1')
	{
		print_hud(data, "can't go through walls!");
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
			print_hud(data, "Save all the pizzas!");
			return (0);
		}
	}
	return (0);
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

void	next_frame(t_data *data)
{
	if (mvt_check(data))
	{
		put_player(data);
		data->steps += 1;
		print_hud(data, NULL);
	}
	data->player.delta_x = 0;
	data->player.delta_y = 0;
	print_map(data);
}
