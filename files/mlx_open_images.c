/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_open_images.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:57:23 by jarregui          #+#    #+#             */
/*   Updated: 2024/05/29 16:51:43 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// static void	open_enemy_imgs(t_game *game)
// {
// 	game->enemy_imgs.basic_01 = mlx_xpm_file_to_image(game->mlx,
// 			"sprites/enemy_01.xpm",
// 			&game->img_size.x, &game->img_size.y);
// 	game->enemy_imgs.basic_02 = mlx_xpm_file_to_image(game->mlx,
// 			"sprites/enemy_02.xpm",
// 			&game->img_size.x, &game->img_size.y);
// 	game->enemy_imgs.basic_current = game->enemy_imgs.basic_01;
// 	game->enemy_imgs.follow_01 = mlx_xpm_file_to_image(game->mlx,
// 			"sprites/enemy_03.xpm",
// 			&game->img_size.x, &game->img_size.y);
// 	game->enemy_imgs.follow_02 = mlx_xpm_file_to_image(game->mlx,
// 			"sprites/enemy_04.xpm",
// 			&game->img_size.x, &game->img_size.y);
// 	game->enemy_imgs.follow_current = game->enemy_imgs.follow_01;
// }

static void	load_door_imgs(t_game *game)
{
	game->imgs.door_open = mlx_xpm_file_to_image(game->mlx,
			"sprites/door_01.xpm",
			&game->tile_dim, &game->tile_dim);
	if (!game->imgs.door_open)
		ft_exit_error("Error al cargar la imagen door_open", game);
	game->imgs.door_close = mlx_xpm_file_to_image(game->mlx,
			"sprites/door_02.xpm",
			&game->tile_dim, &game->tile_dim);
	if (!game->imgs.door_close)
		ft_exit_error("Error al cargar la imagen door_close", game);
}

static void	load_wall_imgs(t_game *game)
{
	game->imgs.wall = mlx_xpm_file_to_image(game->mlx,
			"sprites/wall.xpm",
			&game->tile_dim, &game->tile_dim);
	if (!game->imgs.wall)
		ft_exit_error("Error al cargar la imagen de la pared", game);
}

static void create_and_load_background(t_game *game) {

    ft_printf("\n666666 DENTRO DE CREATE BACKGROUND");
	ft_printf("\ngame->map_x: %d", game->map_x);
	ft_printf("\ngame->map_y: %d", game->map_y);
	ft_printf("\ngame->win_width: %d", game->win_width);
	ft_printf("\ngame->win_height: %d", game->win_height);





    // guardamos la imagen completa del background de las paredes del fondo
    int	x;
    int	y;

	game->imgs.background = mlx_new_image(game->mlx, game->win_width, game->win_height);
	// background_data = mlx_get_data_addr(game->imgs.background, &game->imgs.bpp, &game->imgs.line_length, &game->imgs.endian);
    
    y = 0;
    while (y < game->map_y)
    {
        x = 0;
        while (x < game->map_x)
        {
            if (game->map_wall[x][y])
                mlx_put_image_to_window(game->mlx, game->imgs.background, game->imgs.wall, 
                    x * game->tile_dim, y * game->tile_dim);
            x++;
        }
        y++;
    }
    // Añadir otros elementos estáticos si es necesario
}

/* Opens with the mlx all images needed in the game */
void	load_images(t_game *game)
{
	// open_wallimgs_up (game);
	// open_wallimgs_down (game);
	// open_player_imgs(game);
	// open_collect_imgs(game);
	// open_enemy_imgs(game);
	load_door_imgs(game);
	load_wall_imgs(game);
	create_and_load_background(game);
}

