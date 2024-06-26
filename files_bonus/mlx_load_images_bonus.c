/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_load_images_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:57:23 by jarregui          #+#    #+#             */
/*   Updated: 2024/06/27 00:16:41 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	set_wall_img(t_game *game)
{
	int		bg_pxl_index;
	int		wall_pixel_index;
	int		i;
	int		j;

	i = 0;
	while (i < game->tile_dim)
	{
		j = 0;
		while (j < game->tile_dim)
		{
			bg_pxl_index = ((game->y * game->tile_dim + j) * game->win_width
					+ (game->x * game->tile_dim + i)) * (game->imgs.bg.bpp / 8);
			wall_pixel_index = (j * game->tile_dim + i)
				* (game->imgs.wall.bpp / 8);
			ft_memcpy(&game->imgs.bg.data[bg_pxl_index],
				&game->imgs.wall.data[wall_pixel_index],
				game->imgs.wall.bpp / 8);
			j++;
		}
		i++;
	}
}

static void	generate_background(t_game *game)
{
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
}

static void	ft_load_tile_xpm(t_game *game, t_img *img, char *file)
{
	char	*err_msg;

	img->ptr = mlx_xpm_file_to_image(game->mlx, file,
			&game->tile_dim, &game->tile_dim);
	if (!img->ptr)
	{
		err_msg = ft_strjoin("Error al cargar la imagen: ", file);
		ft_exit_error(err_msg, game);
	}
	img->data = mlx_get_data_addr(img->ptr, &img->bpp, &img->size_line,
			&img->endian);
}

static void	*ft_load_sprite_xpm(t_game *game, char *file, int dim_x, int dim_y)
{
	void	*img_ptr;
	char	*err_msg;
	int		px_dim_x;
	int		px_dim_y;

	px_dim_x = game->tile_dim * dim_x;
	px_dim_y = game->tile_dim * dim_y;
	img_ptr = mlx_xpm_file_to_image(game->mlx, file, &px_dim_x, &px_dim_y);
	if (!img_ptr)
	{
		err_msg = ft_strjoin("Error al cargar la imagen: ", file);
		ft_exit_error(err_msg, game);
	}
	return (img_ptr);
}

void	load_images(t_game *game)
{
	game->imgs.coll.ptr = ft_load_sprite_xpm(game,
			"sprites/coin_sprite.xpm", 10, 1);
	game->imgs.coll.data = mlx_get_data_addr(game->imgs.coll.ptr,
			&game->imgs.coll.bpp, &game->imgs.coll.size_line,
			&game->imgs.coll.endian);
	ft_load_tile_xpm(game, &game->imgs.wall, "sprites/wall.xpm");
	ft_load_tile_xpm(game, &game->imgs.door_open, "sprites/door_02.xpm");
	ft_load_tile_xpm(game, &game->imgs.door_close, "sprites/door_01.xpm");
	ft_load_tile_xpm(game, &game->imgs.player, "sprites/player.xpm");
	ft_load_tile_xpm(game, &game->imgs.enemy, "sprites/enemy.xpm");
	set_img_dims(game, &game->imgs.bg, game->win_width, game->win_height);
	set_img_dims(game, &game->imgs.coll_frame, game->tile_dim, game->tile_dim);
	generate_background(game);
	generate_frame(game, &game->imgs.coll, &game->imgs.coll_frame);
	if (game->debug)
		ft_printf("\n✅ Imágenes necesarias cargadas satisfactoriamente\n");
}
