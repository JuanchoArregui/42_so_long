/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw_game_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:49:13 by jarregui          #+#    #+#             */
/*   Updated: 2024/06/25 16:19:47 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

static void	draw_scoreboard(t_game *game)
{
	int		pos_x;
	int		pos_y;
	char	*msg_steps;
	char	*msg_coll;

	pos_x = (game->tile_dim / 4);
	pos_y = (game->map_y + 0.4) * game->tile_dim;
	msg_steps = ft_strjoin("Total Movements: ", ft_itoa(game->player_steps));
	msg_coll = ft_strjoin("Remaining Collectibles: ",
			ft_itoa(game->coll_remain));
	mlx_string_put(game->mlx, game->win, pos_x, pos_y, 0xFFFF00, msg_steps);
	pos_y += 0.4 * game->tile_dim;
	mlx_string_put(game->mlx, game->win, pos_x, pos_y, 0xFFFF00, msg_coll);
}

void	draw_game(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->imgs.background, 0, 0);
	if (game->coll_remain > 0)
		draw_map_coll(game);
	if (game->coll_remain == 0)
		draw_tile(game, game->imgs.door_open, game->exit_x, game->exit_y);
	else
		draw_tile(game, game->imgs.door_close, game->exit_x, game->exit_y);
	draw_tile(game, game->imgs.player, game->player_x, game->player_y);
	draw_scoreboard(game);
}
