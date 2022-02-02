/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:26:47 by fmalizia          #+#    #+#             */
/*   Updated: 2022/02/02 15:58:19 by fmalizia         ###   ########.fr       */
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

void	check_player_exit(t_data *data)
{
	if (data->map.play != 1)
	{
		prline("Error\nMap must contain only 1 player!", 0);
		exit(EXIT_FAILURE);
	}
	if (data->map.collectables == 0)
	{
		prline("Error\nno collectables on map!", 0);
		exit(EXIT_FAILURE);
	}
	if (data->map.exit == 0)
	{
		prline("Error\nMap must have an exit\n", 0);
		exit(EXIT_FAILURE);
	}
}
