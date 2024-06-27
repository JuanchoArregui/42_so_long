/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_random_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:30:08 by jarregui          #+#    #+#             */
/*   Updated: 2024/06/27 13:19:25 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	generate_random_number(unsigned int *random_number, t_game *game)
{
	int		fd;
	ssize_t	result;

	fd = open("/dev/urandom", O_RDONLY);
	if (fd == -1)
		ft_exit_error("Error abriendo /dev/urandom", game);
	result = read(fd, random_number, sizeof(unsigned int));
	if (result == -1)
	{
		close(fd);
		ft_exit_error("Error leyendo /dev/urandom", game);
	}
	else if (result != sizeof(unsigned int))
	{
		close(fd);
		ft_exit_error("Error lect. incompleta /dev/urandom", game);
	}
	close(fd);
}

int	get_random_enemy_number(t_game *game)
{
	int				range;
	unsigned int	random_number;

	range = game->coll_remain;
	generate_random_number(&random_number, game);
	return ((random_number % range) + 1);
}

void	transform_coll_to_enemy(t_game *game, int coll_enemy)
{
	int	coll_counter;

	coll_counter = 0;
	game->y = 0;
	while (game->y < game->map_y)
	{
		game->x = 0;
		while (game->x < game->map_x)
		{
			if (game->map_coll[game->y][game->x])
			{
				coll_counter += 1;
				if (coll_counter == coll_enemy)
				{
					game->enemy = 1;
					game->map_coll[game->y][game->x] = 0;
					game->coll_remain -= 1;
					game->enem_y = game->y;
					game->enem_x = game->x;
				}
			}
			game->x++;
		}
		game->y++;
	}
}

void	check_exit(t_game *game)
{
	int	msg_x;
	int	msg_y;

	msg_x = ((game->map_x * game->tile_dim) / 2) - (game->tile_dim * 1.5);
	msg_y = (game->map_y * game->tile_dim) / 2;
	if (game->coll_remain == 0 && game->player_y == game->exit_y
		&& game->player_x == game->exit_x)
	{
		game->exited = 1;
		mlx_clear_window(game->mlx, game->win);
		mlx_string_put(game->mlx, game->win, msg_x, msg_y, 0xFFA500,
			"    Mission Accomplished!!");
	}
}

void	check_death(t_game *game)
{
	int	msg_x;
	int	msg_y;

	msg_x = ((game->map_x * game->tile_dim) / 2) - (game->tile_dim * 1.5);
	msg_y = (game->map_y * game->tile_dim) / 2;
	if (game->player_y == game->enem_y && game->player_x == game->enem_x)
	{
		game->exited = 1;
		mlx_clear_window(game->mlx, game->win);
		mlx_string_put(game->mlx, game->win, msg_x, msg_y, 0xFF0000,
			"      Game Over!!!!");
	}
}
