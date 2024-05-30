/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:49:13 by jarregui          #+#    #+#             */
/*   Updated: 2024/05/30 10:50:56 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_put_img(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img,
		x * game->tile_dim, y * game->tile_dim);
}

void	draw_background_map(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->imgs.background, 0, 0);
}

void	draw_player(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->imgs.player, 
		game->player_x * game->tile_dim, game->player_y * game->tile_dim);
}

void	draw_door(t_game *game)
{
	if (game->coll_remain == 0)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->imgs.door_open, 
			game->exit_x * game->tile_dim, game->exit_y * game->tile_dim);
	}
	else
	{
		mlx_put_image_to_window(game->mlx, game->win, game->imgs.door_close, 
			game->exit_x * game->tile_dim, game->exit_y * game->tile_dim);
	}
}

void	draw_colectibles(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_y)
	{
		x = 0;
		while (x < game->map_x)
		{
			ft_printf("\nmap_wall[%d][%d]: %c", x, y, game->map_wall[x][y]);
			if (game->map_wall[x][y])
			{
				// mlx_put_image_to_window(game->mlx, game->win, game->imgs.coll, 
				// 	x * game->tile_dim, y * game->tile_dim);
			}
			x++;
		}
		y++;
	}

	ft_printf("\n\nEN DRAW COLLECTIBLES :\n");
		y = 0;
		while (y < game->map_y)
		{
			ft_printf("\n");
			x = 0;
			while (x < game->map_x)
			{
				ft_printf("\nmap_wall[%d][%d]: %c", x, y, game->map_wall[x][y]);
				x++;
			}
			y++;
		}
		ft_printf("\n");

}

void	draw_map(t_game *game)
{
	
	
	game->aux_y = 0;
	while (game->aux_y < game->map_y)
	{
		game->aux_x = 0;
		while (game->aux_x < game->map_x)
		{
			if (game->map_wall[game->aux_x][game->aux_y])
				mlx_put_image_to_window(game->mlx, game->win, game->imgs.wall,
					game->aux_x * game->tile_dim, game->aux_x * game->tile_dim);
			game->aux_x++;
		}
		game->aux_y++;
	}
}

void draw_game(t_game *game) {
	// draw_background_map(game);
	// if (game->coll_remain > 0)
	//	draw_colectibles(game);
	// draw_door(game);
	// draw_player(game);
	draw_colectibles(game);
}
