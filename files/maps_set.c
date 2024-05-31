/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:18:43 by jarregui          #+#    #+#             */
/*   Updated: 2024/05/31 17:55:25 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_maps(char *map, t_game *game)
{
	int		fd;
	char	*line;
	int		y;
	int		x;

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
			set_characters(line[x], y, x, game);
			x++;
		}
		free(line);
		y++;
	}
}

void	set_characters(char chr, int y, int x, t_game *game)
{
	game->map_raw[y][x] = chr;
	if (chr == '1')
	{
		game->map_wall[y][x] = 1;
	}
	else if (chr == 'C')
	{
		game->collectibles += 1;
		game->map_coll[y][x] = 1;
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
		game->map_vstd[y][x] = '1';
	}
}
