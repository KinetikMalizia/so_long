/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_right.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeancarlen <jeancarlen@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:45:41 by jeancarlen        #+#    #+#             */
/*   Updated: 2022/01/28 15:17:44 by jeancarlen       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void wall_check(t_data *data)
{
    int x;
    int y;
    
    x = 0;
    while (x < data->size_x / IMG_W)
    {
        y = 0;
        while (y < data->size_y / IMG_H)
        {
            if ((y == 0 || x == 0) && data->map.map[y][x] != '1')
            {
                prline("manque de wall\n");
                exit(EXIT_FAILURE);
            }
            if ((x == (data->size_x / IMG_H - 1)
                || y == (data->size_y / IMG_W - 1))
                && data->map.map[y][x] != '1')
            {
                prline("manque de wall\n");
                exit(EXIT_FAILURE);
            }
         //   if ()
            y++;
        }
        x++;
    }
}

int mvt_check(t_data *data)
{
    int new_x;
    int new_y;

    new_y = data->player.p_y + data->player.delta_y;
    new_x = data->player.p_x + data->player.delta_x;
    if (data->map.map[new_y][new_x] == '1')
    {
        prline("can't go through walls!");
        return (0);
    }
    else if (data->map.map[new_y][new_x] == '0')
        return (1);
    else if (data->map.map[new_y][new_x] == 'C')
    {
        collect(data, new_x, new_y);
        return (1);
    }
    else if (data->map.map[new_y][new_x] == 'E')
    {
        if(data->map.collectables == 0)
        {
            data->steps += 1;
            win_game(data);
        }
        else
        {
            prline("you didn't collect all the pizza!");
            return (0);
        }
    }
    return (0);
}
//rajouté le check si y'a tout dedans

void win_game(t_data *data)
{
    printf("CONGRATULATIONS!\n");
    printf("you made %d steps!\n", data->steps);
	exit(EXIT_SUCCESS);
}
