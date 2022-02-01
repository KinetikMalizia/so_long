/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlen <jcarlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 12:00:27 by jeancarlen        #+#    #+#             */
/*   Updated: 2022/02/01 14:33:10 by jcarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_putnbr_fd(int nb, int fd);
static void	ft_putchar_fd(char c, int fd);

void	prline(char *str, int steps)
{
	ft_putstr_fd("\r                                    \r", 1);
	ft_putstr_fd(str, 1);
	if (steps != 0)
		ft_putnbr_fd(steps, 1);
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
