/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:45:07 by jeancarlen        #+#    #+#             */
/*   Updated: 2022/03/07 11:21:18 by fmalizia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count_lines(int fd, int x, int img_w)
{
	char	buffer[1];
	int		linecount;
	int		bytes;
	int		i;

	i = 0;
	buffer[0] = '\0';
	linecount = 1;
	bytes = 1;
	while (bytes == 1)
	{
		bytes = read(fd, buffer, 1);
		if (!(bytes == 0 && buffer[0] == '\n'))
			if (bytes != 1 && i != (x / img_w))
				exit_error();
		if (i == (x / img_w))
		{
			linecount++;
			i = 0;
		}
		else
			i++;
	}
	return (linecount);
}

int	ft_line_length(int fd)
{
	char	buffer[1];
	int		length;
	int		bytes;

	buffer[0] = '\0';
	bytes = 1;
	length = 0;
	while (bytes == 1)
	{
		bytes = read(fd, buffer, 1);
		if (buffer[0] != '\n')
			length++;
		else
			break ;
	}
	return (length);
}

void	init_map(char *path, t_data *data)
{
	int	fd;

	fd = open(path, O_RDONLY);
	rd_map(fd, data);
	setup_img(data);
	create_back(data);
	setup_player(data);
	wall_check(data);
	put_object(data);
	check_player_exit(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.hub_bg,
		data->size_x / 2 - 175, data->size_y);
	mlx_string_put(data->mlx, data->win,
		(data->size_x / 2) - 35, data->size_y + 30,
		0xfffafa, "Press any key to start!");
}

void	rd_map(int fd, t_data *data)
{
	char	buffer[2];
	int		i;
	int		bytes;

	buffer[1] = '\0';
	bytes = 1;
	i = 0;
	while (bytes == 1)
	{
		bytes = read(fd, buffer, 1);
		if (bytes != 1)
			break ;
		if (buffer[0] != '\n')
		{
			data->map.map[i] = ft_strjoin_malloc(data->map.map[i], buffer);
		}
		else
			++i;
	}
	data->map.collectables = 0;
	data->wall_flag = 0;
	data->map.play = 0;
	data->map.exit = 0;
}
