/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:07:31 by jeancarlen        #+#    #+#             */
/*   Updated: 2022/03/07 16:53:09 by fmalizia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoin_malloc(char *s1, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(s1) + ft_strlen(buff)] = '\0';
	free(s1);
	return (str);
}

char	*ft_strnstr(const char *s1, const char *s2, unsigned long n)
{
	unsigned long	i;
	unsigned long	j;

	i = 0;
	j = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (i < n && s1[i] != '\0')
	{
		j = 0;
		while (i + j < n && s1[i + j] == s2[j] && s2[j] != '\0')
			j++;
		if (s2[j] == '\0')
			return ((char *)s1 + i);
		i++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	int			i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t c, size_t n)
{
	void	*ptr;

	ptr = malloc(c * n);
	if (ptr == 0)
		return (ptr);
	ft_bzero(ptr, c * n);
	return (ptr);
}

void	ft_bzero(void *b, size_t len)
{
	size_t			i;
	unsigned char	*p;

	p = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		p[i] = 0;
		i++;
	}
	b = p;
}
