/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlen <jcarlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:44:27 by jeancarlen        #+#    #+#             */
/*   Updated: 2022/02/04 11:51:13 by jcarlen          ###   ########.fr       */
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

int	key_hook(t_data *data)
{
	mlx_hook(data->win, 2, 1L << 1, keyhook_inputs, data);
	mlx_hook(data->win, 17, 1L << 0, win_exit, data);
	return (0);
}
