/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:18:43 by jarregui          #+#    #+#             */
/*   Updated: 2024/04/26 14:32:39 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_walls(t_game *game)
{
	size_t	x;
	size_t	y;

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
				if (game->map_wall[x][y])
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
	size_t	x;
	size_t	y;

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
				if (game->map_coll[x][y])
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
	size_t	x;
	size_t	y;

	if (game->debug)
	{
		y = 0;
		while (y < game->map_y)
		{
			ft_printf("\n");
			x = 0;
			while (x < game->map_x)
			{
				if (game->map_vstd[x][y] == '1')
					ft_printf("🟥");
				else if (game->map_vstd[x][y])
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
	size_t	x;
	size_t	y;

	if (game->debug)
	{
		y = 0;
		while (y < game->map_y)
		{
			ft_printf("\n");
			x = 0;
			while (x < game->map_x)
			{
				if (game->map_wall[x][y])
					ft_printf("🟧");
				else if (game->map_coll[x][y])
					ft_printf("🟡");
				else if (x == game->player_x && y == game->player_y)
					ft_printf("👤");
				else if (x == game->exit_x && y == game->exit_y)
					ft_printf("🟩");
				else
					ft_printf("⬛");
				x++;
			}
			y++;
		}
		ft_printf("\n");
	}
}
