/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_load_images.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:57:23 by jarregui          #+#    #+#             */
/*   Updated: 2024/06/01 11:54:50 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void *create_and_load_background(t_game *game) {
	int		y;
	int		x;

	void	*img_ptr;
	char	*background_data;
	int		background_bpp;
	int		background_size_line;
	int		background_endian;

	ft_printf("\nx: %d, y: %d", game->x, game->y);
	
	img_ptr = mlx_new_image(game->mlx, game->win_width, game->win_height);
	if (!img_ptr)
		ft_exit_error("Error al cargar la imagen del background", game);
	background_data = mlx_get_data_addr(img_ptr, &background_bpp, &background_size_line, &background_endian);

	y = 0;
	while (y < game->map_y)
	{
		x = 0;
		while (x < game->map_x)
		{
			if (game->map_wall[y][x])
			{
				char    *wall_data;
                int     wall_bpp;
                int     wall_size_line;
                int     wall_endian;
				// Get the data address of the wall image
                wall_data = mlx_get_data_addr(game->imgs.wall, &wall_bpp, &wall_size_line, &wall_endian);

                // Copy the wall image data to the correct position in the background image data
                for (int i = 0; i < game->tile_dim; i++)
                {
                    for (int j = 0; j < game->tile_dim; j++)
                    {
                        int background_pixel_index = ((y * game->tile_dim + j) * game->win_width + (x * game->tile_dim + i)) * (background_bpp / 8);
                        int wall_pixel_index = (j * game->tile_dim + i) * (wall_bpp / 8);

                        memcpy(&background_data[background_pixel_index], &wall_data[wall_pixel_index], wall_bpp / 8);
                    }
                }
			}
				// mlx_put_image_to_window(game->mlx, img_ptr, game->imgs.wall, 
				// 	x * game->tile_dim, y * game->tile_dim);
			x++;
		}
		y++;
	}
	return (img_ptr);
	// Añadir otros elementos estáticos si es necesario
}


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

void	load_images(t_game *game)
{
	game->imgs.wall = ft_load_xpm(game, "sprites/wall.xpm");
	game->imgs.coll = ft_load_xpm(game, "sprites/coll.xpm");
	game->imgs.door_open = ft_load_xpm(game, "sprites/door_02.xpm");
	game->imgs.door_close = ft_load_xpm(game, "sprites/door_01.xpm");
	game->imgs.player = ft_load_xpm(game, "sprites/player.xpm");
	game->imgs.background = create_and_load_background(game);
	if (game->debug)
		ft_printf("\n✅ Imágenes necesarias cargadas satisfactoriamente\n");
}

