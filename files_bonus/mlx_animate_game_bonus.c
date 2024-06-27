/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_animate_game_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:49:13 by jarregui          #+#    #+#             */
/*   Updated: 2024/06/27 18:59:32 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	set_enemy(t_game *game)
{
	int	random_enemy;

	if (game->coll_remain > 1)
	{
		random_enemy = get_random_enemy_number(game);
		transform_coll_to_enemy(game, random_enemy);
		if (game->debug)
			printf("random_enemy: %d of %d\n", random_enemy, game->coll_remain);
	}
}

void	move_enemy(t_game *game, int dif_x, int dif_y)
{
	int	go_x;

	dif_x = game->enem_x - game->player_x;
	dif_y = game->enem_y - game->player_y;
	if (fabs((double)dif_x) > fabs((double)dif_y))
		go_x = 1;
	else
		go_x = 0;
	if (dif_x != 0)
		dif_x = dif_x / fabs((double)dif_x);
	if (dif_y != 0)
		dif_y = dif_y / fabs((double)dif_y);
	if (go_x && !game->map_wall[game->enem_y][game->enem_x - dif_x])
		game->enem_x -= dif_x;
	else if (!go_x && !game->map_wall[game->enem_y - dif_y][game->enem_x])
		game->enem_y -= dif_y;
	else if (!game->map_wall[game->enem_y + dif_y][game->enem_x])
		game->enem_y += dif_y;
	else if (!game->map_wall[game->enem_y][game->enem_x + dif_x])
		game->enem_x += dif_x;
}

void	set_img_dims(t_game *game, t_img *img, int dim_x, int dim_y)
{
	img->ptr = mlx_new_image(game->mlx, dim_x, dim_y);
	if (!img->ptr)
		ft_exit_error("Error al reservar dimesiones imagen", game);
	img->data = mlx_get_data_addr(img->ptr, &img->bpp, &img->size_line,
			&img->endian);
}

void	generate_frame(t_game *game, t_img *sprite, t_img *frame)
{
	int		dest_pxl_indx;
	int		src_pxl_indx;
	int		i;
	int		j;
	int		x_offset;

	x_offset = (game->loop_current_frame % NUM_FRAMES) * game->tile_dim;
	i = 0;
	while (i < game->tile_dim)
	{
		j = 0;
		while (j < game->tile_dim)
		{
			dest_pxl_indx = ((j * game->tile_dim) + i) * (frame->bpp / 8);
			src_pxl_indx = ((j * (sprite->size_line / (sprite->bpp / 8)))
					+ (i + x_offset)) * (sprite->bpp / 8);
			ft_memcpy(&frame->data[dest_pxl_indx],
				&sprite->data[src_pxl_indx],
				sprite->bpp / 8);
			j++;
		}
		i++;
	}
}

int	update_anim(t_game *game)
{
	if (!game->exited)
	{
		game->loop_counter++;
		if (game->loop_counter > 3000)
		{
			game->loop_counter = 0;
			game->loop_current_frame
				= (game->loop_current_frame + 1) % NUM_FRAMES;
			if (game->coll_remain)
				generate_frame(game, &game->imgs.coll, &game->imgs.coll_frame);
			if (game->enemy && ((game->loop_current_frame + 1) % 5 == 0))
				move_enemy(game, 0, 0);
			draw_game(game);
			check_death(game);
			if (game->debug)
				ft_printf("⏰ LOOP Cicle --> frame: %d\n",
					game->loop_current_frame);
		}
	}
	return (0);
}
