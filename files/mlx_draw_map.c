/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:49:13 by jarregui          #+#    #+#             */
/*   Updated: 2024/05/29 11:11:21 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void draw_map(t_game *game) {


    ft_printf("\n666666 DENTRO DE DRAW MAP");
	ft_printf("\ngame->map_x: %d", game->map_x);
	ft_printf("\ngame->map_y: %d", game->map_y);
	ft_printf("\ngame->win_width: %d", game->win_width);
	ft_printf("\ngame->win_height: %d", game->win_height);



    // int	x;
    // int	y;

    // y = 0;
    // while (y < game->map_y)
    // {
    //     x = 0;
    //     while (x < game->map_x)
    //     {
    //         if (game->map_wall[x][y])
    //             mlx_put_image_to_window(game->mlx, game->win, game->imgs.wall, 
    //                 x * game->tile_dim, y * game->tile_dim);
    //         x++;
    //     }
    //     y++;
    // }
}

