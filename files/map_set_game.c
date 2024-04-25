/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_set_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:18:43 by jarregui          #+#    #+#             */
/*   Updated: 2024/04/25 12:25:01 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_maps(char *map, t_game *game)
{
	int		fd;
	char	*line;
	size_t	x;
	size_t	y;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_exit_error("Error al abrir el archivo.", game);
	y = 0;
	while (y < game->map_y)
	{
		line = get_next_line(fd);
		x = 0;
		while (x < game->map_x)
		{
			set_character(line[x], x, y, game);
			x++;
		}
		free(line);
		y++;
	}
}

set_character(char	chr, size_t x, size_t y, t_game *game)
{
	if (chr == '1')
		game->map_wall[x][y] = chr;
	else if (chr == 'C')
	{
		game->collectibles += 1;
		game->map_coll[x][y] = chr;
	}
	else if (chr == 'E')
	{
		game->exits += 1;
		game->exit_x = x;
		game->exit_y = y;
	}
	else if (chr == 'P')
	{
		game->players += 1;
		game->player_x = x;
		game->player_y = y;
	}
	else if (chr != '0')
	{
		ft_printf("AQUI NO DEBERIAMOS LLEGAR!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
	}
}

void	check_map_array(t_game *game)
{
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
	else if (game->debug)
		ft_printf("\n✅ collectibles OK\n");

	check_map_boundaries(game);
	if (game->debug)
		ft_printf("\n✅ El mapa está cerrado\n");

}

void	check_map_boundaries(t_game *game)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < game->map_y)
	{
		x = 0;
		if (y == 0 || y == game->map_y -1)
		{
			while (x < game->map_x)
			{
				if (game->map_array[indx(x, y, 0, game)] != 1)
					ft_exit_error("El Mapa no está cerrado", game);
				x++;
			}
		}
		else
		{
			if (game->map_array[indx(0, y, 0, game)] != 1
				|| game->map_array[indx(game->map_x - 1, y, 0, game)] != 1)
				ft_exit_error("El Mapa no está cerrado", game);
		}
		y++;
	}
}


