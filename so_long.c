/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:19:38 by jeancarlen        #+#    #+#             */
/*   Updated: 2022/02/02 15:58:22 by fmalizia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	win_exit(int keycode, t_data *data)
{
	printf("\nsuka\nyou move to trash\n");
	exit(0);
}

int	key_hook(t_data *data)
{
	mlx_hook(data->win, 2, 1L << 1, keyhook_inputs, data);
	mlx_hook(data->win, 17, 1L << 0, win_exit, data);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	ft_window_size(&data, av);
	prline("Press any key to start!", 0);
	data.map.map = ft_calloc(data.size_y + 1, sizeof(char *));
	data.mlx = mlx_init();
	if (!data.mlx)
	{
		perror("Error\nprogramm init failed\n");
		exit(EXIT_FAILURE);
	}
	data.win = mlx_new_window(data.mlx, data.size_x,
			data.size_y, "MEGAXTRMDEATHMACHINE");
	init_map(av[1], &data);
	mlx_loop_hook(data.mlx, key_hook, &data);
	mlx_loop(data.mlx);
}
