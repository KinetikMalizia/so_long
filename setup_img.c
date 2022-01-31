#include "so_long.h"

void setup_img(t_data *data)
{
    int     height;
    int     width;
    t_img   *img;

    img = malloc(sizeof(t_img));
    if (!img)
        exit(EXIT_FAILURE);
    data->img = *img;
    data->img.ground = mlx_xpm_file_to_image(data->mlx,
                    "./sprite_xpm/ground_tile.xpm", &width, &height);
    data->img.wall = mlx_xpm_file_to_image(data->mlx,
                    "./sprite_xpm/tile_01.xpm", &width, &height);
    data->img.player = mlx_xpm_file_to_image(data->mlx,
                    "./sprite_xpm/spaceship.xpm", &width, &height);
    data->img.collectable= mlx_xpm_file_to_image(data->mlx,
                    "./sprite_xpm/collectable.xpm", &width, &height);
    data->img.exit_s = mlx_xpm_file_to_image(data->mlx,
                    "./sprite_xpm/exit_s.xpm", &width, &height);
    data->img.exit_w = mlx_xpm_file_to_image(data->mlx,
                    "./sprite_xpm/exit_w.xpm", &width, &height);
}

void    setup_player(t_data *data)
{
    t_player    *player;

    player = malloc(sizeof(t_player));
    if (!player)
        exit(EXIT_FAILURE);
    data->steps = 0;
    data->player = *player;
    data->player.delta_x = 0;
    data->player.delta_y = 0;
}