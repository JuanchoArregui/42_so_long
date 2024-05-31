/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:18:43 by jarregui          #+#    #+#             */
/*   Updated: 2024/05/31 17:01:07 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_maps(t_game *game)
{
	game->map_raw = init_map(game);
	printf("Initializing maps...\n");
	ft_printf("\nDENTRO DE INIT MAPS");
	ft_printf("\ngame->map_y: %d", game->map_y);
	ft_printf("\ngame->map_x: %d", game->map_x);
	game->map_wall = init_map(game);
	ft_printf("\nDENTRO DE INIT MAPS---> despues de MAP WALL");
	ft_printf("\ngame->map_y: %d", game->map_y);
	ft_printf("\ngame->map_x: %d", game->map_x);
	game->map_coll = init_map(game);
	ft_printf("\nDENTRO DE INIT MAPS---> despues de MAP COLL");
	ft_printf("\ngame->map_y: %d", game->map_y);
	ft_printf("\ngame->map_x: %d", game->map_x);
	game->map_vstd = init_map(game);
	ft_printf("\nDENTRO DE INIT MAPS---> despues de MAP VSTD");
	ft_printf("\ngame->map_y: %d", game->map_y);
	ft_printf("\ngame->map_x: %d", game->map_x);


	if (!game->map_wall || !game->map_coll || !game->map_vstd) {
        ft_exit_error("Error: fallo en la asignación de memoria para los mapas.", game);
    }

	
	if (game->debug)
		ft_printf("\n✅ Array Maps inicializados.\n");
}

char	**init_map(t_game *game)
{
	char	**map;
	int		y;

	ft_printf("\nInitializing map with dimensions: array2d[%d][%d]\n", game->map_y, game->map_x);

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

	ft_printf("\nLiberando mapa con dimension y: array2d[%d] y con puntero: %p\n", map_y, map);

	y = 0;
	while (y < map_y)
	{
		// ft_printf("\nLiberando mapa con dimension y: array2d[%d] y con puntero: %p\n", map_y, map);
		if (map[y])
			free(map[y]);
		y++;
	}
	if (map)
		free(map);
}
