/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_load_images.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:57:23 by jarregui          #+#    #+#             */
/*   Updated: 2024/05/30 10:06:02 by jarregui         ###   ########.fr       */
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
	// create_and_load_background(game);
}

