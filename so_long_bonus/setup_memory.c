/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:47:43 by jeancarlen        #+#    #+#             */
/*   Updated: 2022/03/04 11:07:54 by fmalizia         ###   ########.fr       */
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
	setup_wall(data);
	data->img.ground = mlx_xpm_file_to_image(data->mlx,
			"./sprite_xpm/tile1.xpm", &width, &height);
	data->img.player = mlx_xpm_file_to_image(data->mlx,
			"./sprite_xpm/supervan_R.xpm", &width, &height);
	data->img.collectable = mlx_xpm_file_to_image(data->mlx,
			"./sprite_xpm/collectable.xpm", &width, &height);
	data->img.exit_s = mlx_xpm_file_to_image(data->mlx,
			"./sprite_xpm/exit_c.xpm", &width, &height);
	data->img.exit_w = mlx_xpm_file_to_image(data->mlx,
			"./sprite_xpm/exit_o.xpm", &width, &height);
	data->img.hub_bg = mlx_xpm_file_to_image(data->mlx,
			"./sprite_xpm/hub_bg.xpm", &width, &height);
}

void	setup_wall(t_data *data)
{
	t_wall		*wall;
	int			height;
	int			width;

	wall = malloc(sizeof(t_wall));
	if (!wall)
		exit(EXIT_FAILURE);
	data->img.wall = wall;
	data->img.wall->wall1 = mlx_xpm_file_to_image(data->mlx,
			"./sprite_xpm/wall.xpm", &width, &height);
	data->img.wall->wall2 = mlx_xpm_file_to_image(data->mlx,
			"./sprite_xpm/wall2.xpm", &width, &height);
	data->img.wall->wall3 = mlx_xpm_file_to_image(data->mlx,
			"./sprite_xpm/wall3.xpm", &width, &height);
	data->img.wall->wall4 = mlx_xpm_file_to_image(data->mlx,
			"./sprite_xpm/wall4.xpm", &width, &height);
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
