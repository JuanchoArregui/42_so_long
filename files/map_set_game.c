/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_set_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:18:43 by jarregui          #+#    #+#             */
/*   Updated: 2024/04/17 16:26:52 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_map_array(char *map, t_game *game)
{
	size_t	xyz;
	int		fd;
	char	*line;

	size_t	x;
	size_t	y;


	xyz = game->map_x * game->map_y * game->map_z;
	game->map_array = (int *)malloc(xyz * sizeof(int));
	if (!game->map_array)
		ft_exit_error("Error al reservar memoria", game);
	while (xyz > 0)
	{
		game->map_array[xyz - 1] = 0;
		xyz--;
	}


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
			if (line[x] == '0')
				game->map_array[indx(x, y, 0, game)] = 0;
			else if (line[x] == '1')
				game->map_array[indx(x, y, 0, game)] = 1;
			else if (line[x] == 'C')
			{
				game->collectibles += 1;
				game->map_array[indx(x, y, 1, game)] = 1;
			}
			else if (line[x] == 'E')
			{
				game->exits += 1;
				game->map_array[indx(x, y, 1, game)] = 2;
			}
			else if (line[x] == 'P')
			{
				game->players += 1;
				game->player_x = x;
				game->player_y = y;
			}
			else
			{
				ft_printf("AQUI NO DEBERIAMOS LLEGAR!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
			}
			x++;
		}
		free(line);
		y++;
	}
}

size_t	indx(size_t x, size_t y, size_t z, t_game *game)
{
	size_t	indx;

	indx = (x) + (y * (game->map_x)) + (z * (game->map_x * game->map_y));
	return (indx);
}
