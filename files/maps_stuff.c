/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:18:43 by jarregui          #+#    #+#             */
/*   Updated: 2024/04/26 13:10:11 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_maps(t_game *game)
{
	game->map_wall = init_map(game);
	game->map_coll = init_map(game);
	game->map_vstd = init_map(game);
	if (game->debug)
		ft_printf("\n✅ Array Maps inicializados.\n");
}

char	**init_map(t_game *game)
{
	char	**map;
	size_t	x;

	map = (char **)malloc(game->map_x * sizeof(char *));
	if (map == NULL)
		ft_exit_error("Error asignación memoria", game);
	x = 0;
	while (x < game->map_x)
	{
		map[x] = (char *)malloc(game->map_y * sizeof(char));
		if (map[x] == NULL)
			ft_exit_error("Error asignación memoria", game);
		x++;
	}
	populate_map(map, game->map_x, game->map_y);
	return (map);
}

void	populate_map(char **map, size_t map_x, size_t map_y)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < map_y)
	{
		x = 0;
		while (x < map_x)
		{
			map[x][y] = 0;
			x++;
		}
		y++;
	}
}

void	free_map(char **map, size_t map_x)
{
	size_t	x;

	x = 0;
	while (x < map_x)
	{
		free(map[x]);
		x++;
	}
	free(map);
}
