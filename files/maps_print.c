/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:18:43 by jarregui          #+#    #+#             */
/*   Updated: 2024/05/30 10:47:05 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_walls(t_game *game)
{
	int	x;
	int	y;

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
	ft_printf("\n\nTODAVIA EN PRINT WALLS :\n");
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

void	print_colls(t_game *game)
{
	int	x;
	int	y;

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
	int	x;
	int	y;

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
	int	x;
	int	y;

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
