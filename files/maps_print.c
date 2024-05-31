/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:18:43 by jarregui          #+#    #+#             */
/*   Updated: 2024/05/31 13:14:28 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_walls(t_game *game)
{
	int	y;
	int	x;

	if (game->debug)
	{
		ft_printf("\n\nWALLS:\n");
		y = 0;
		while (y < game->map_y)
		{
			ft_printf("\n");
			x = 0;
			while (x < game->map_x)
			{
				if (game->map_wall[y][x])
					ft_printf("🟧");
				else
					ft_printf("⬛");
				x++;
			}
			y++;
		}
		ft_printf("\n");
	}
}

void	print_colls(t_game *game)
{
	int	y;
	int	x;

	if (game->debug)
	{
		ft_printf("\n\nCOLLECTIBLES:\n");
		y = 0;
		while (y < game->map_y)
		{
			ft_printf("\n");
			x = 0;
			while (x < game->map_x)
			{
				if (game->map_coll[y][x])
					ft_printf("🟡");
				else
					ft_printf("⬛");
				x++;
			}
			y++;
		}
		ft_printf("\n");
	}
}

void	print_flood(t_game *game)
{
	int	y;
	int	x;

	if (game->debug)
	{
		y = 0;
		while (y < game->map_y)
		{
			ft_printf("\n");
			x = 0;
			while (x < game->map_x)
			{
				if (game->map_vstd[y][x] == '1')
					ft_printf("🟥");
				else if (game->map_vstd[y][x])
					ft_printf("⬜");
				else
					ft_printf("⬛");
				x++;
			}
			y++;
		}
		ft_printf("\n");
	}
}

void	print_full_map_game(t_game *game)
{
	if (game->debug)
	{
		game->y = 0;
		while (game->y < game->map_y)
		{
			ft_printf("\n");
			game->x = 0;
			while (game->x < game->map_x)
			{
				if (game->map_wall[game->y][game->x])
					ft_printf("🟧");
				else if (game->map_coll[game->y][game->x])
					ft_printf("🟡");
				else if (game->x == game->player_x && game->y == game->player_y)
					ft_printf("👤");
				else if (game->x == game->exit_x && game->y == game->exit_y)
					ft_printf("🟩");
				else
					ft_printf("⬛");
				game->x++;
			}
			game->y++;
		}
		ft_printf("\n");
	}
}
