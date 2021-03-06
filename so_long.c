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
#include "stdio.h"

int	randomize(int n)
{
	int	num;

	num = (n * 15) % 17;
	num = (num * 45) % 51;
	num = (num * 86) % 93;
	num = (num * 17) % 4;
	return (num);
}

int	win_exit(int keycode, t_data *data)
{
	(void)keycode;
	ft_putstr_fd("\nsuka\nyou move to trash\n", 1);
	free_all(data);
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

int	cross_exit(int keycode, t_data *data)
{
	(void)keycode;
	(void)data;
	ft_putstr_fd("\nyou give up and die =(\n", 1);
	exit(0);
}

void	win_game(t_data *data)
{
	data->steps += 1;
	ft_putstr_fd("\n***************************\n", 1);
	prline("CONGRATULATIONS!\nTotal steps: ", data->steps);
	ft_putstr_fd("\n***************************\n", 1);
	free_all(data);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	exit(EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_data	data;

	(void)ac;
	data.rng = 0;
	data.z = 0;
	data.delay = 1500;
	ft_window_size(&data, av);
	data.map.map = ft_calloc(data.size_y + 1, sizeof(char *));
	data.mlx = mlx_init();
	if (!data.mlx)
	{
		ft_putstr_fd("Error\nprogramm init failed\n", 1);
		exit(EXIT_FAILURE);
	}
	data.win = mlx_new_window(data.mlx, data.size_x,
			data.size_y + 50, "MEGAXTRMDEATHMACHINE");
	init_map(av[1], &data);
	map_length(&data);
	mlx_loop_hook(data.mlx, key_hook, &data);
	mlx_loop(data.mlx);
}
