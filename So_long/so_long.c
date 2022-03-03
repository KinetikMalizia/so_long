/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvnrlen <arvenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:19:38 by jeancarlen        #+#    #+#             */
/*   Updated: 2022/02/03 11:17:17 by arvn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	win_exit(int keycode, t_data *data)
{
	printf("\nsuka\nyou move to trash\n");
	exit(0);
}

void	win_game(t_data *data)
{
	data->steps += 1;
	prline("CONGRATULATIONS!\nTotal steps: ", data->steps);
	printf("\n***************************\n");
	exit(EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_data	data;

	ft_window_size(&data, av);
	printf("***************************\n");
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
	map_length(&data);
	mlx_loop_hook(data.mlx, key_hook, &data);
	mlx_loop(data.mlx);
}
