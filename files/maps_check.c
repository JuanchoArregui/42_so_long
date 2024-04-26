/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:18:43 by jarregui          #+#    #+#             */
/*   Updated: 2024/04/26 10:42:56 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_map_full(t_game *game)
{
	if (game->debug)
	{
		ft_printf("\n\nWALLS:\n");
		print_map(game->map_wall, game->map_x, game->map_y);
		ft_printf("\n\nCOLLECTIBLES:\n");
		print_map(game->map_coll, game->map_x, game->map_y);
	}
	
	
	if (game->players != 1)
		ft_exit_error("No player or more than 1 player", game);
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
	if (game->debug)
		ft_printf("\n✅ El mapa está cerrado\n");
	check_map_playable(game);
		if (game->debug)
			ft_printf("\n✅ El mapa es jugable\n");


	
}

void	check_map_boundaries(t_game *game)
{
	size_t	x;
	size_t	y;

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
		else
		{
			if (!game->map_wall[0][y]
				|| !game->map_wall[game->map_x -1][y])
				ft_exit_error("El Mapa no está cerrado **", game);
		}
		y++;
	}
}

void	check_map_playable(t_game *game)
{
	size_t	x;
	size_t	y;
	size_t	new_visited;

	
	
	y = 1;
	new_visited = 0;


	if (game->debug)
	{
		ft_printf("\n\nVISITED ANTES DE ENTRAR:\n");
		ft_printf("\n****new visited: %d", new_visited);
		ft_printf("\n****coll_remain: %d", game->coll_remain);
		ft_printf("\n****exited: %d", game->exited);
		print_map(game->map_vstd, game->map_x, game->map_y);
	}

	
	while (y < (game->map_y - 1))
	{
		x = 1;
		while (x < (game->map_x - 1))
		{
			new_visited += check_pos(x, y, game);
			x++;
		}
		y++;
	}

	if (game->debug)
	{
		ft_printf("\n\nVISITED ANTES DEL BUCLE:\n");
		ft_printf("\n****new visited: %d", new_visited);
		ft_printf("\n****coll_remain: %d", game->coll_remain);
		ft_printf("\n****exited: %d", game->exited);
		print_map(game->map_vstd, game->map_x, game->map_y);
	}
	if (new_visited > 0 && (game->coll_remain > 0 || game->exited != 1))
		check_map_playable(game);
	else if (game->coll_remain > 0 || game->exited != 1)
		ft_exit_error("El Mapa no es jugable", game);
}

size_t	check_pos(size_t x, size_t y, t_game *game)
{
	size_t	new_visited;

	new_visited = 0;
	if (game->map_vstd[x][y])
	{
		new_visited += check_mov(x - 1, y, game);
		new_visited += check_mov(x + 1, y, game);
		new_visited += check_mov(x, y - 1, game);
		new_visited += check_mov(x, y + 1, game);
	}
	return (new_visited);
}

size_t	check_mov(size_t x, size_t y, t_game *game)
{
	if (x > 0 && x < (game->map_x - 1) && y > 0 && y < (game->map_y - 1)
		&& !game->map_wall[x][y] && !game->map_vstd[x][y])
	{
		game->map_vstd[x][y] = 'V';
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
