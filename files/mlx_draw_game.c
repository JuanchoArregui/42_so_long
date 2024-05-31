/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:49:13 by jarregui          #+#    #+#             */
/*   Updated: 2024/05/31 18:03:42 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	draw_map_wall(t_game *game)
{
	game->y = 0;
	while (game->y < game->map_y)
	{
		game->x = 0;
		while (game->x < game->map_x)
		{
			if (game->map_wall[game->y][game->x])
				draw_tile(game, game->imgs.wall, game->x, game->y);
			game->x++;
		}
		game->y++;
	}
}

static void	draw_map_coll(t_game *game)
{
	game->y = 0;
	while (game->y < game->map_y)
	{
		game->x = 0;
		while (game->x < game->map_x)
		{
			if (game->map_coll[game->y][game->x])
				draw_tile(game, game->imgs.coll, game->x, game->y);
			game->x++;
		}
		game->y++;
	}
}

void	draw_tile(t_game *game, void *img_ptr, int x, int y)
{
	if (!img_ptr)
		ft_exit_error("Error puntero a imagen no iniciado", game);
	mlx_put_image_to_window(game->mlx, game->win, img_ptr,
		x * game->tile_dim, y * game->tile_dim);
}

void	draw_game(t_game *game)
{
	draw_map_wall(game);
	if (game->coll_remain > 0)
		draw_map_coll(game);
	if (game->coll_remain == 0)
		draw_tile(game, game->imgs.door_open, game->exit_x, game->exit_y);
	else
		draw_tile(game, game->imgs.door_close, game->exit_x, game->exit_y);
	draw_tile(game, game->imgs.player, game->player_x, game->player_y);
}
