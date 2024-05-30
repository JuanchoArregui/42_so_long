/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_strucs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 19:53:40 by jarregui          #+#    #+#             */
/*   Updated: 2024/05/30 10:18:14 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	init_game_struc_partial_1(t_game *game)
{
	game->debug = 1;

	game->mlx = NULL;
	game->tile_dim = 64;
	game->win_width = 0;
	game->win_height = 0;
	game->win = NULL;


	game->map_x = 0;
	game->map_y = 0;
	game->map_wall = NULL;

	game->map_coll = NULL;
	game->collectibles = 0;
	game->coll_remain = 0;

	game->map_vstd = NULL;
	game->visited = 0;
}

static void	init_game_struc_partial_2(t_game *game)
{
	game->exits = 0;
	game->exited = 0;
	game->exit_x = 0;
	game->exit_y = 0;

	game->players = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->player_steps = 0;
	game->player_score = 0;

	game->aux_x = 0;
	game->aux_y = 0;
}

static void	init_game_imgs_struc(t_game *game)
{
	game->imgs.wall = NULL;
	game->imgs.coll = NULL;
	game->imgs.player = NULL;
	game->imgs.door_open = NULL;
	game->imgs.door_close = NULL;
	game->imgs.background = NULL;
}

void	init_game_struc(t_game *game)
{
	init_game_struc_partial_1(game);
	init_game_struc_partial_2(game);
	init_game_imgs_struc(game);
}
