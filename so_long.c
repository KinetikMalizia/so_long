/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeancarlen <jeancarlen@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:19:38 by jeancarlen        #+#    #+#             */
/*   Updated: 2022/01/20 16:23:06 by jeancarlen       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct s_data {
    void    *img;
    char    *addr;
    int        bits_per_pixel;
    int        line_length;
    int        endian;
}                t_data;

typedef struct    s_vars {
    void    *mlx;
    void    *win;
}                t_vars;

int    win_exit(int keycode, t_vars *vars);

int    close(int keycode, t_vars *vars)
{
    printf("key is %d\n", keycode);
    if (keycode == 53)
        win_exit(keycode, vars);
    return (0);
}

int    win_exit(int keycode, t_vars *vars)
{
    mlx_destroy_window(vars->mlx, vars->win);
    printf("suka\n");
    exit(0);
}

void    my_mlx_pixel_put(t_data *data, int x, int y, int color);

int    key_hook(int keycode, t_vars *vars)
{
    mlx_hook(vars->win, 2, 1L << 0, close, vars);
    mlx_hook(vars->win, 17, 0L << 0, win_exit, vars);    
    return (0);
}

int    main(void)
{
    t_data    img;
    t_vars    vars;
	char	*relative_path = "./pizza.xpm";
	int		img_width;
	int		img_height;


    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 500, 500, "Hello world!");
    img.img = mlx_new_image(vars.mlx, 1000, 1000);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                &img.endian);
    img.img = mlx_xpm_file_to_image(vars.mlx, relative_path, &img_width, &img_height);                            
    mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0); //9=v c'est de la merde
    mlx_key_hook(vars.win, key_hook, &vars);
    mlx_loop(vars.mlx);
}
