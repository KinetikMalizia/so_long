/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:50:31 by fmalizia          #+#    #+#             */
/*   Updated: 2022/01/19 15:51:11 by fmalizia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "so_long.h"

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	img;
	int		height;
	int		width;
	int		x = 0;
	int		y = 0;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "window");
	img.img = mlx_new_image(mlx_ptr, 50, 50);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	
	while (x < 1000)
	{
		y = 0;
		while (y < 1000)
		{
			img.img = mlx_xpm_file_to_image(mlx_ptr, "./orng.xpm", &height, &width);
			mlx_put_image_to_window(mlx_ptr, win_ptr, img.img, x, y);
			img.img = mlx_xpm_file_to_image(mlx_ptr, "./test01.xpm", &height, &width);
			mlx_put_image_to_window(mlx_ptr, win_ptr, img.img, x, y);
			y += width;
		}
		x += height;
	}
	mlx_loop(mlx_ptr);
}

void	mlx_px_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
