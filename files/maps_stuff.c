/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:18:43 by jarregui          #+#    #+#             */
/*   Updated: 2024/05/29 11:14:38 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_maps(t_game *game)
{
	printf("Initializing maps...\n");
	ft_printf("\nDENTRO DE INIT MAPS");
	ft_printf("\ngame.map_x: %d", game->map_x);
	ft_printf("\ngame->map_y: %d", game->map_y);
	game->map_wall = init_map(game);
	ft_printf("\nDENTRO DE INIT MAPS---> despues de MAP WALL");
	ft_printf("\ngame->map_x: %d", game->map_x);
	ft_printf("\ngame->map_y: %d", game->map_y);
	game->map_coll = init_map(game);
	ft_printf("\nDENTRO DE INIT MAPS---> despues de MAP COLL");
	ft_printf("\ngame->map_x: %d", game->map_x);
	ft_printf("\ngame->map_y: %d", game->map_y);
	game->map_vstd = init_map(game);
	ft_printf("\nDENTRO DE INIT MAPS---> despues de MAP VSTD");
	ft_printf("\ngame->map_x: %d", game->map_x);
	ft_printf("\ngame->map_y: %d", game->map_y);

	if (!game->map_wall || !game->map_coll || !game->map_vstd) {
        ft_exit_error("Error: fallo en la asignación de memoria para los mapas.", game);
    }

	
	if (game->debug)
		ft_printf("\n✅ Array Maps inicializados.\n");
}

char	**init_map(t_game *game)
{
	char	**map;
	int	x;

	ft_printf("\nInitializing map with dimensions: %d x %d\n", game->map_x, game->map_y);

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

void	populate_map(char **map, int map_x, int map_y)
{
	int	x;
	int	y;

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

void	free_map(char **map, int map_x)
{
	ft_printf("\n\nLIBERANDO MAPA  %p - %d", map, map_x);
	
	
	int	x;

	x = 0;
	while (x < map_x)
	{
		ft_printf("\nx: %d", x);
		
		if (map[x])
			free(map[x]);
		x++;
	}
	if (map)
		free(map);
}
