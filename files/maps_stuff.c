/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:18:43 by jarregui          #+#    #+#             */
/*   Updated: 2024/04/25 14:23:14 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_maps(t_game *game)
{
	game->map_wall = init_map(game);
	game->map_coll = init_map(game);
}

char	**init_map(t_game *game)
{
	char	**map;
	size_t	y;

	map = (char **)malloc(game->map_x * sizeof(char *));
	if (map == NULL)
		ft_exit_error("Error asignación memoria", game);
	y = 0;
	while (y < game->map_y)
	{
		map[y] = (char *)malloc(game->map_y * sizeof(char));
		if (map[y] == NULL)
			ft_exit_error("Error asignación memoria", game);
		y++;
	}
	populate_map(map, game->map_x, game->map_y);
	return (map);
}

void	populate_map(char **map, size_t map_x, size_t map_y)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (x < map_x)
	{
		while (y < map_y)
		{
			map[x][y] = 0;
			y++;
		}
		x++;
	}
}

void	free_map(char **map, size_t map_y)
{
	size_t	y;

	y = 0;
	while (y < map_y)
	{
		free(map[y]);
		y++;
	}
	free(map);
}

void	print_map(char **map, size_t map_x, size_t map_y)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (x < map_x)
	{
		ft_printf("\n");
		while (y < map_y)
		{
			map[x][y] = 0;
			if (map[x][y])
				ft_printf("🟧");
			else
				ft_printf("⬛");
			y++;
		}
		x++;
	}
	ft_printf("\n");
}
