/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeancarlen <jeancarlen@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:42:12 by jeancarlen        #+#    #+#             */
/*   Updated: 2022/03/03 10:54:18 by jeancarlen       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_length(t_data *data)
{
	if (data->size_y > MAX_Y || data->size_x > MAX_X)
	prline("/!\\ map is too big! /!\\ \n", 0);
}

void	check_player_exit(t_data *data)
{
	if (data->map.play != 1)
	{
		prline("Error\nMap must contain only 1 player!", -1);
		exit(EXIT_FAILURE);
	}
	if (data->map.collectables == 0)
	{
		prline("Error\nno collectables on map!", -1);
		exit(EXIT_FAILURE);
	}
	if (data->map.exit == 0)
	{
		prline("Error\nMap must have an exit\n", -1);
		exit(EXIT_FAILURE);
	}
}

void	ft_window_size(t_data *data, char **argv)
{
	int		fd;
	char	*word;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		prline("Error\nInvalid map_path/map\n", 0);
		exit(EXIT_FAILURE);
	}
	word = ft_strnstr(argv[1], ".ber", ft_strlen(argv[1]));
	if (word == NULL || word[4] != '\0')
	{
		prline("Error\nmap has to be .ber", 0);
		exit(EXIT_FAILURE);
	}
	data->size_x = (ft_line_length(fd) * IMG_W);
	data->size_y = (ft_count_lines(fd, data->size_x, IMG_W) * IMG_H);
}

void	wall_check(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < data->size_x / IMG_W)
	{
		y = 0;
		while (y < data->size_y / IMG_H)
		{
			if ((y == 0 || x == 0) && data->map.map[y][x] != '1')
			{
				prline("manque de wall", -1);
				exit(EXIT_FAILURE);
			}
			if ((x == (data->size_x / IMG_H - 1)
					|| y == (data->size_y / IMG_W - 1))
				&& data->map.map[y][x] != '1')
			{
				prline("manque de wall", -1);
				exit(EXIT_FAILURE);
			}
			y++;
		}
		x++;
	}
}

void	exit_error(void)
{
	prline("Error\nwrong map dimensions", 0);
	exit(EXIT_FAILURE);
}
