/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_check_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:18:43 by jarregui          #+#    #+#             */
/*   Updated: 2024/06/25 15:34:56 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_map_full(t_game *game)
{
	print_walls(game);
	print_colls(game);
	if (game->players != 1)
		ft_exit_error(ft_strjoin("Num jugadores incorrecto: ",
				ft_itoa(game->players)), game);
	else if (game->debug)
		ft_printf("\n✅ 1 player set\n");
	if (game->exits != 1)
		ft_exit_error("No exit or more than 1 exit", game);
	else if (game->debug)
		ft_printf("\n✅ 1 exit set\n");
	if (game->collectibles == 0)
		ft_exit_error("No collectibles", game);
	else
	{
		game->coll_remain = game->collectibles;
		if (game->debug)
			ft_printf("\n✅ collectibles OK\n");
	}
	check_map_boundaries(game);
	print_flood(game);
	check_map_playable(game);
}

void	check_map_boundaries(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map_y)
	{
		if (y == 0 || y == game->map_y -1)
		{
			x = 0;
			while (x < game->map_x)
			{
				if (!game->map_wall[y][x])
					ft_exit_error("El Mapa no está cerrado *", game);
				x++;
			}
		}
		else if (!game->map_wall[y][0] || !game->map_wall[y][game->map_x -1])
			ft_exit_error("El Mapa no está cerrado **", game);
		y++;
	}
	if (game->debug)
		ft_printf("\n✅ Mapa bordes cerrados OK\n");
}

void	check_map_playable(t_game *game)
{
	int	y;
	int	x;

	y = 1;
	game->visited = 0;
	while (y < (game->map_y - 1))
	{
		x = 1;
		while (x < (game->map_x - 1))
			game->visited += check_pos(y, x++, game);
		y++;
	}
	print_flood(game);
	if (game->coll_remain > 0 || game->exited != 1)
	{
		if (game->visited > 0)
			check_map_playable(game);
		else if (game->exited != 1)
			ft_exit_error("No jugable. No acceso salida", game);
		else
			ft_exit_error("No jugable. No acceso todos coleccionables", game);
	}
	else
		if (game->debug)
			ft_printf("\n✅ El mapa es jugable\n");
}

int	check_pos(int y, int x, t_game *game)
{
	int	new_visited;

	new_visited = 0;
	if (game->map_vstd[y][x] == '1')
	{
		new_visited += check_mov(y, x - 1, game);
		new_visited += check_mov(y, x + 1, game);
		new_visited += check_mov(y - 1, x, game);
		new_visited += check_mov(y + 1, x, game);
		game->map_vstd[y][x] = '2';
	}
	return (new_visited);
}

int	check_mov(int y, int x, t_game *game)
{
	if (x > 0 && x < (game->map_x - 1) && y > 0 && y < (game->map_y - 1)
		&& !game->map_wall[y][x] && !game->map_vstd[y][x])
	{
		game->map_vstd[y][x] = '1';
		if (game->map_coll[y][x])
		{
			game->map_coll[y][x] = 0;
			game->coll_remain -= 1;
		}
		else if (x == game->exit_x && y == game->exit_y)
		{
			game->exited = 1;
		}
		return (1);
	}
	else
	{
		return (0);
	}
}
