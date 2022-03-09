/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeancarlen <jeancarlen@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 09:48:42 by fmalizia          #+#    #+#             */
/*   Updated: 2022/03/09 11:41:49 by jeancarlen       ###   ########.fr       */
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
