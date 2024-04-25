/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stuff.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 19:53:40 by jarregui          #+#    #+#             */
/*   Updated: 2024/04/25 14:24:17 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t	ft_strlen_no_n(char *s)
{
	size_t	length;

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
	ft_free_maps(game);
	exit(0);
}

void	ft_free_maps(t_game *game)
{
	if (game->map_wall != NULL)
		free_map(game->map_wall, game->map_y);
	if (game->map_coll != NULL)
		free_map(game->map_coll, game->map_y);
}

void	ft_get_leaks(void)
{
	ft_printf("\n\nCHECKING FOR LEAKS AT EXIT:\n");
	system("leaks -q so_long");
	ft_printf("\n");
}

void	init_game(t_game *game)
{
	game->debug = 1;

	game->collectibles = 0;
	game->coll_remain = 0;
	game->exits = 0;
	game->players = 0;

	game->map_x = 0;
	game->map_y = 0;
	game->map_wall = NULL;
	game->map_coll = NULL;
	
	game->map_enem = NULL;
	game->map_play = NULL;
	game->map_vstd = NULL;




}
