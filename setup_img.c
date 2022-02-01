/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlen <jcarlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:32:43 by jcarlen           #+#    #+#             */
/*   Updated: 2022/02/01 16:30:00 by jcarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	setup_img(t_data *data)
{
	int		height;
	int		width;
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!img)
		exit(EXIT_FAILURE);
	data->img = *img;
	data->img.ground = mlx_xpm_file_to_image(data->mlx,
			"./sprite_xpm/tile1.xpm", &width, &height);
	data->img.wall = mlx_xpm_file_to_image(data->mlx,
			"./sprite_xpm/wall.xpm", &width, &height);
	data->img.player = mlx_xpm_file_to_image(data->mlx,
			"./sprite_xpm/player_ship.xpm", &width, &height);
	data->img.collectable = mlx_xpm_file_to_image(data->mlx,
			"./sprite_xpm/collectable.xpm", &width, &height);
	data->img.exit_s = mlx_xpm_file_to_image(data->mlx,
			"./sprite_xpm/exit_c.xpm", &width, &height);
	data->img.exit_w = mlx_xpm_file_to_image(data->mlx,
			"./sprite_xpm/exit_o.xpm", &width, &height);
}

void	setup_player(t_data *data)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		exit(EXIT_FAILURE);
	data->steps = 0;
	data->player = *player;
	data->player.delta_x = 0;
	data->player.delta_y = 0;
}
