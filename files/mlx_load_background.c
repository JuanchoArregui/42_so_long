/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_load_background.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:57:23 by jarregui          #+#    #+#             */
/*   Updated: 2024/05/30 10:24:32 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void create_and_load_background(t_game *game) {
	ft_printf("\naux_x: %d, aux_y: %d", game->aux_x, game->aux_y);
	// int		x;
	// int		y;
	// char	*background_data;
	// int		background_bpp;
	// int		background_size_line;
	// int		background_endian;

	// game->imgs.background = mlx_new_image(game->mlx, game->win_width, game->win_height);
	// if (!game->imgs.background)
	// 	ft_exit_error("Error al cargar la imagen del background", game);
	// background_data = mlx_get_data_addr(game->imgs.background, &background_bpp, &background_size_line, &background_endian);

	// y = 0;
	// while (y < game->map_y)
	// {
	// 	x = 0;
	// 	while (x < game->map_x)
	// 	{
	// 		if (game->map_wall[x][y])
	// 		{
	// 			char    *wall_data;
    //             int     wall_bpp;
    //             int     wall_size_line;
    //             int     wall_endian;
	// 			// Get the data address of the wall image
    //             wall_data = mlx_get_data_addr(game->imgs.wall, &wall_bpp, &wall_size_line, &wall_endian);

    //             // Copy the wall image data to the correct position in the background image data
    //             for (int i = 0; i < game->tile_dim; i++)
    //             {
    //                 for (int j = 0; j < game->tile_dim; j++)
    //                 {
    //                     int background_pixel_index = ((y * game->tile_dim + j) * game->win_width + (x * game->tile_dim + i)) * (background_bpp / 8);
    //                     int wall_pixel_index = (j * game->tile_dim + i) * (wall_bpp / 8);

    //                     memcpy(&background_data[background_pixel_index], &wall_data[wall_pixel_index], wall_bpp / 8);
    //                 }
    //             }
	// 		}
	// 			// mlx_put_image_to_window(game->mlx, game->imgs.background, game->imgs.wall, 
	// 			// 	x * game->tile_dim, y * game->tile_dim);
	// 		x++;
	// 	}
	// 	y++;
	// }
	// // Añadir otros elementos estáticos si es necesario
}
