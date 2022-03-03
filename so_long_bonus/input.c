/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:44:27 by jeancarlen        #+#    #+#             */
/*   Updated: 2022/03/03 15:28:553 by marvin           ###   ########.fr       */
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
	return (0);
}

int	key_hook(t_data *data)
{
	data->z += 1;
	if (data->z == 3000)
		data->player.offset = 15;
	if (data->z == 6000)
		data->player.offset = -15;
	if (data->z == 9000)
	{
		data->player.offset = 0;
		data->z = 0;
	}
	if (data->z % 200 == 0)
		next_frame(data);
	mlx_hook(data->win, 2, 1L << 1, keyhook_inputs, data);
	mlx_hook(data->win, 17, 1L << 0, win_exit, data);
	return (0);
}

size_t	nblen(int nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	if (nbr < len)
		len += 1;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t	i;
	size_t	n_size;
	char	*str;

	i = 0;
	n_size = nblen(n);
	str = (char *)malloc(sizeof(char) * (n_size + 1));
	if (str == 0)
		return (0);
	str[n_size] = 0;
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
		i += 1;
	}
	while (i < n_size--)
	{
		str[n_size] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}