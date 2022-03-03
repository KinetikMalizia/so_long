/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeancarlen <jeancarlen@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 12:00:27 by jeancarlen        #+#    #+#             */
/*   Updated: 2022/03/03 11:45:375 by jeancarlen       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_putnbr_fd(int nb, int fd);
static void	ft_putchar_fd(char c, int fd);

void	prline(char *str, int steps)
{
	ft_putstr_fd("\r                                    \r", 1);
	ft_putstr_fd(str, 1);
	if (steps == -1)
		ft_putstr_fd("\n", 1);
	if (steps > 0)
		ft_putnbr_fd(steps, 1);
}

void	print_hud(t_data *data, char *string)
{
	char	*steps;
	mlx_put_image_to_window(data->mlx, data->win, data->img.hub_bg, 0, data->size_y);
	mlx_string_put(data->mlx, data->win, (data->size_x / 2) - 20, data->size_y + 20, 0xfffafa, "steps:");
	steps = ft_itoa(data->steps);
	mlx_string_put(data->mlx, data->win, (data->size_x / 2) + 25, data->size_y + 20, 0xfffafa, steps);
	free(steps);
	if (string)
		mlx_string_put(data->mlx, data->win, data->size_x / 2 - 20, data->size_y + 40, 0xff0000, string);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write(fd, (const void *)s, 1);
		++s;
	}
}

static void	ft_putnbr_fd(int nb, int fd)
{
	unsigned int	n;
	int				base;

	base = 10;
	if (nb < 0)
	{
		n = -nb;
		ft_putchar_fd('-', fd);
	}
	else
		n = nb;
	if (n / base)
		ft_putnbr_fd(n / base, fd);
	ft_putchar_fd((n % base) + '0', fd);
}

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, (const void *)&c, 1);
}
