/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:18:43 by jarregui          #+#    #+#             */
/*   Updated: 2024/05/30 14:58:28 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
	int	x;
	int	y;

	y = 0;
	while (y < game->map_y)
	{
		if (y == 0 || y == game->map_y -1)
		{
			x = 0;
			while (x < game->map_x)
			{
				if (!game->map_wall[x][y])
					ft_exit_error("El Mapa no está cerrado *", game);
				x++;
			}
		}
		else if (!game->map_wall[0][y] || !game->map_wall[game->map_x -1][y])
			ft_exit_error("El Mapa no está cerrado **", game);
		y++;
	}
	if (game->debug)
		ft_printf("\n✅ Mapa bordes cerrados OK\n");
}

void	check_map_playable(t_game *game)
{
	int	x;
	int	y;

	y = 1;
	game->visited = 0;
	while (y < (game->map_y - 1))
	{
		x = 1;
		while (x < (game->map_x - 1))
			game->visited += check_pos(x++, y, game);
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

int	check_pos(int x, int y, t_game *game)
{
	int	new_visited;

	new_visited = 0;
	if (game->map_vstd[x][y] == '1')
	{
		new_visited += check_mov(x - 1, y, game);
		new_visited += check_mov(x + 1, y, game);
		new_visited += check_mov(x, y - 1, game);
		new_visited += check_mov(x, y + 1, game);
		game->map_vstd[x][y] = '2';
	}
	return (new_visited);
}

int	check_mov(int x, int y, t_game *game)
{
	if (x > 0 && x < (game->map_x - 1) && y > 0 && y < (game->map_y - 1)
		&& !game->map_wall[x][y] && !game->map_vstd[x][y])
	{
		game->map_vstd[x][y] = '1';
		if (game->map_coll[x][y])
		{
			game->map_coll[x][y] = 0;
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
