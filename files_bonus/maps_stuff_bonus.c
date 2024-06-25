/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_stuff_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:18:43 by jarregui          #+#    #+#             */
/*   Updated: 2024/06/25 15:35:08 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_maps(t_game *game)
{
	game->map_raw = init_map(game);
	game->map_wall = init_map(game);
	game->map_coll = init_map(game);
	game->map_vstd = init_map(game);
	if (game->debug)
		ft_printf("\n✅ Array Maps inicializados.\n");
}

char	**init_map(t_game *game)
{
	char	**map;
	int		y;

	map = (char **)malloc(game->map_y * sizeof(char *));
	if (map == NULL)
		ft_exit_error("Error asignación memoria", game);
	y = 0;
	while (y < game->map_y)
	{
		map[y] = (char *)malloc(game->map_x * sizeof(char));
		if (map[y] == NULL)
			ft_exit_error("Error asignación memoria", game);
		y++;
	}
	populate_map(map, game->map_y, game->map_x);
	return (map);
}

void	populate_map(char **map, int map_y, int map_x)
{
	int	y;
	int	x;

	y = 0;
	while (y < map_y)
	{
		x = 0;
		while (x < map_x)
		{
			map[y][x] = 0;
			x++;
		}
		y++;
	}
}

void	free_map(char **map, int map_y)
{
	int	y;

	y = 0;
	while (y < map_y)
	{
		if (map[y])
			free(map[y]);
		y++;
	}
	if (map)
		free(map);
}
