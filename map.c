/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlen <jcarlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:07:45 by jeancarlen        #+#    #+#             */
/*   Updated: 2022/02/01 14:32:26 by jcarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_error(void);

void	exit_error(void)
{
	prline("Error\nwrong map dimensions", 0);
	exit(EXIT_FAILURE);
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

void	ft_window_size(t_data *data, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error\nInvalid map_path/map\n");
		exit(EXIT_FAILURE);
	}
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
	{
		prline("Error\nmap has to be .ber", 0);
		exit(EXIT_FAILURE);
	}
	data->size_x = (ft_line_length(fd) * IMG_W);
	data->size_y = (ft_count_lines(fd, data->size_x, IMG_W) * IMG_H);
}

void	init_map(char *path, t_data *data)
{
	int	fd;

	fd = open(path, O_RDONLY);
	rd_map(fd, data);
	setup_img(data);
	create_back(data);
	setup_player(data);
	put_object(data);
	wall_check(data);
}
