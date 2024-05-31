/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_load_images.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:57:23 by jarregui          #+#    #+#             */
/*   Updated: 2024/05/31 17:07:30 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	*ft_load_xpm(t_game *game, char *file)
{
	void	*img_ptr;
	char	*err_msg;

	img_ptr = mlx_xpm_file_to_image(game->mlx, file,
			&game->tile_dim, &game->tile_dim);
	if (!img_ptr)
	{
		err_msg = ft_strjoin("Error al cargar la imagen: ", file);
		ft_exit_error(err_msg, game);
	}
	return (img_ptr);
}

/* Opens with the mlx all images needed in the game */
void	load_images(t_game *game)
{
	game->imgs.wall = ft_load_xpm(game, "sprites/wall.xpm");
	game->imgs.coll = ft_load_xpm(game, "sprites/coll.xpm");
	game->imgs.door_open = ft_load_xpm(game, "sprites/door_02.xpm");
	game->imgs.door_close = ft_load_xpm(game, "sprites/door_01.xpm");
	game->imgs.player = ft_load_xpm(game, "sprites/player.xpm");
	
	// open_wallimgs_up (game);
	// open_wallimgs_down (game);
	// open_player_imgs(game);
	// open_collect_imgs(game);
	// open_enemy_imgs(game);
	// load_door_imgs(game);
	// load_wall_imgs(game);
	// create_and_load_background(game);

	if (game->debug)
			ft_printf("\n✅ Imágenes necesarias cargadas satisfactoriamente\n");
}

