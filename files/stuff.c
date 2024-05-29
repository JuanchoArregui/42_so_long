/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stuff.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 19:53:40 by jarregui          #+#    #+#             */
/*   Updated: 2024/05/29 11:07:26 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_strlen_no_n(char *s)
{
	int	length;

	length = ft_strlen(s);
	if (length && s[length - 1] == '\n')
		length -= 1;
	return (length);
}

void	ft_exit_error(const char *text, t_game *game)
{
	if (text != NULL && *text != '\0' && game->debug)
		ft_printf("\n❌ %s\n\n", text);
	else
		write(2, "Error\n", 6);
	ft_free_game(game);
	exit(0);
}

void	ft_free_game(t_game *game)
{
ft_printf("\n\n\n---> LIBERADO ft_free_game. CHECK map_x: %d", game->map_x);
	
	
	if (game->map_wall != NULL)
	{

		free_map(game->map_wall, game->map_x);
ft_printf("\nLIBERADO MAPA map_wall");
	}

	if (game->map_coll != NULL)
	{

		free_map(game->map_coll, game->map_x);
ft_printf("\nLIBERADO MAPA map_coll");
	}

	if (game->map_vstd != NULL)
	{

		free_map(game->map_vstd, game->map_x);
ft_printf("\nLIBERADO MAPA map_vstd");
	}

	if (game->win && game->mlx)
	{
		mlx_destroy_window(game->mlx, game->win);
ft_printf("\nLIBERADO WIN");
	}

	if (game->mlx)
	{

		mlx_destroy_display(game->mlx);
ft_printf("\nLIBERADO MLX");
	}

}

void	ft_get_leaks(void)
{
	ft_printf("\n\nCHECKING FOR LEAKS AT EXIT:\n");
	system("leaks -q so_long");
	ft_printf("\n");
}

void	init_game_struc(t_game *game)
{
	game->debug = 1;

	game->mlx = NULL;
	game->tile_dim = 64;
	game->win_width = 0;
	game->win_height = 0;
	game->win = NULL;
	game->imgs.door_open = NULL;
	game->imgs.door_close = NULL;

	game->map_x = 0;
	game->map_y = 0;
	game->map_wall = NULL;

	game->map_coll = NULL;
	game->collectibles = 0;
	game->coll_remain = 0;

	game->map_vstd = NULL;
	game->visited = 0;

	game->exits = 0;
	game->exited = 0;
	game->exit_x = 0;
	game->exit_y = 0;

	game->players = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->player_steps = 0;
	game->player_score = 0;

}
