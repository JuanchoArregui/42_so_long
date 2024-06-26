/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_strucs_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 19:53:40 by jarregui          #+#    #+#             */
/*   Updated: 2024/06/26 20:48:10 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	init_game_struc_partial_1(t_game *game)
{
	game->debug = 0;
	game->mlx = NULL;
	game->tile_dim = 64;
	game->win_width = 0;
	game->win_height = 0;
	game->win = NULL;
	game->map_y = 0;
	game->map_x = 0;
	game->map_raw = NULL;
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
	game->exit_y = 0;
	game->exit_x = 0;
	game->players = 0;
	game->player_y = 0;
	game->player_x = 0;
	game->enem_y = 0;
	game->enem_x = 0;
	game->player_steps = 0;
	game->player_score = 0;
	game->y = 0;
	game->x = 0;
	game->loop_counter = 0;
	game->loop_current_frame = 0;
}

static void	init_img_struc(t_img *img)
{
	img->ptr = NULL;
	img->data = NULL;
	img->bpp = 0;
	img->size_line = 0;
	img->endian = 0;
}

static void	init_game_imgs_struc(t_game *game)
{
	init_img_struc(&game->imgs.wall);
	init_img_struc(&game->imgs.coll);
	init_img_struc(&game->imgs.coll_frame);
	init_img_struc(&game->imgs.player);
	init_img_struc(&game->imgs.enemy);
	init_img_struc(&game->imgs.door_open);
	init_img_struc(&game->imgs.door_close);
	init_img_struc(&game->imgs.bg);
}

void	init_game_strucs(t_game *game)
{
	init_game_struc_partial_1(game);
	init_game_struc_partial_2(game);
	init_game_imgs_struc(game);
}
