/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeancarlen <jeancarlen@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:19:38 by jeancarlen        #+#    #+#             */
/*   Updated: 2022/01/28 14:58:34 by jeancarlen       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int    action(int keycode, t_data *vars)
{    
    
    printf("++ %d\n", keycode);
    if (keycode == 53)
        win_exit(keycode, vars);
    else if (keycode == 126)
        printf("tu as press la fleche du haut bravo\n");
 //       test(keycode, vars);
    return (0);
}

/*int    test(int keycode, t_data *data)
{

    char	*relative_path = "./sprite_xpm/pizza.xpm";
    char	*blue_path = "./sprite_xpm//BLUE.xpm";
    int		img_width;
	int		img_height;
    
    printf("__%d\n", keycode);
	data->img = mlx_new_image(data->mlx, 500, 500);
    if (data->flag == 0)
    {
        data->img = mlx_xpm_file_to_image(data->mlx, relative_path, &img_width, &img_height);
        data->flag = 1;
    }
    else if (data->flag == 1)
    {
        data->img = mlx_xpm_file_to_image(data->mlx, blue_path, &img_width, &img_height);
        data->flag = 0; 
    }
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
    mlx_destroy_image(data->mlx, data->img);
    return (0);
} */   

int    win_exit(int keycode, t_data *data)
{
    mlx_destroy_window(data->mlx, data->win);
    printf("suka\n");
    exit(0);
}

int    key_hook(int keycode, t_data *data)
{
    mlx_hook(data->win, 2, 1L << 0, keyhook_inputs, data);
    mlx_hook(data->win, 17, 0L << 0, win_exit, data);
    return (0);
}

int    main(int ac, char **av)//int ac, char **av
{
    t_data    data;

    ft_window_size(&data, av);
    data.map.map = ft_calloc(data.size_y + 1, sizeof(char *));
    data.mlx = mlx_init();
    if (!data.mlx)
	{
		perror("Error\nprogramm init failed\n");
		exit(EXIT_FAILURE);
	}
    data.win = mlx_new_window(data.mlx, data.size_x, data.size_y, "MEGAEXTRMDEATHMACHINE");
    init_map(av[1], &data);
    mlx_key_hook(data.win, key_hook, &data);
    mlx_loop(data.mlx);
}
