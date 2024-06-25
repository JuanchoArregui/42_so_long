/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_load_images_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:57:23 by jarregui          #+#    #+#             */
/*   Updated: 2024/06/25 15:35:17 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	set_wall_img(t_game *game)
{
	char	*wall_data;
	int		bg_pxl_index;
	int		wall_pixel_index;
	int		i;
	int		j;

	wall_data = mlx_get_data_addr(game->imgs.wall, &game->bg.wall_bpp,
			&game->bg.wall_size_line, &game->bg.wall_endian);
	i = 0;
	while (i < game->tile_dim)
	{
		j = 0;
		while (j < game->tile_dim)
		{
			bg_pxl_index = ((game->y * game->tile_dim + j) * game->win_width
					+ (game->x * game->tile_dim + i)) * (game->bg.bpp / 8);
			wall_pixel_index = (j * game->tile_dim + i)
				* (game->bg.wall_bpp / 8);
			ft_memcpy(&game->bg.data[bg_pxl_index],
				&wall_data[wall_pixel_index], game->bg.wall_bpp / 8);
			j++;
		}
		i++;
	}
}

static void	*create_and_load_background(t_game *game)
{
	void	*img_ptr;

	game->y = 0;
	game->x = 0;
	img_ptr = mlx_new_image(game->mlx, game->win_width, game->win_height);
	if (!img_ptr)
		ft_exit_error("Error al cargar la imagen del background", game);
	game->bg.data = mlx_get_data_addr(img_ptr, &game->bg.bpp,
			&game->bg.size_line, &game->bg.endian);
	game->y = 0;
	while (game->y < game->map_y)
	{
		game->x = 0;
		while (game->x < game->map_x)
		{
			if (game->map_wall[game->y][game->x])
				set_wall_img(game);
			game->x++;
		}
		game->y++;
	}
	return (img_ptr);
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
