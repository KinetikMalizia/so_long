/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 09:48:42 by fmalizia          #+#    #+#             */
/*   Updated: 2022/03/08 10:59:27 by fmalizia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_enemy	*newenemy(int px, int py)
{
	t_enemy	*ptr;

	ptr = malloc(sizeof(t_enemy));
	if (!ptr)
		return (NULL);
	ptr->e_px = px;
	ptr->e_py = py;
	ptr->e_dx = 0;
	ptr->e_dy = 0;
	ptr->next = NULL;
	return (ptr);
}

void	ft_lstadd(t_data *data, t_enemy *new)
{
	new->next = *data->elist;
	*data->elist = new;
}

void	reset_brocoli(t_data *data)
{
	data->map.y = 0;
	while (data->map.y < data->size_y / IMG_W)
	{
		data->map.x = 0;
		while (data->map.x < data->size_x / IMG_H)
		{
			if (data->map.map[data->map.y][data->map.x] == 'M')
			{
				data->map.map[data->map.y][data->map.x] = 'X';
			}
			data->map.x += 1;
		}
		data->map.y += 1;
	}
	data->map.x = 0;
	data->map.y = 0;
}
