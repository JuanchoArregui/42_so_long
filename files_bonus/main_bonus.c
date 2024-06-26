/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:12:20 by jarregui          #+#    #+#             */
/*   Updated: 2024/06/27 00:16:01 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	on_destroy(t_game *game)
{
	ft_free_game(game);
	exit(0);
	return (0);
}

static int	try_move(t_game *game, int target_y, int target_x, char *text)
{
	if (!game->map_wall[target_y][target_x])
	{
		if (game->debug)
			ft_printf("\nMOVE %s----> ✅\n", text);
		game->player_y = target_y;
		game->player_x = target_x;
		if (game->map_coll[target_y][target_x])
		{
			game->map_coll[target_y][target_x] = 0;
			game->coll_remain -= 1;
		}
		game->player_steps += 1;
		draw_game(game);
		check_exit(game);
		return (1);
	}
	if (game->debug)
	{
		ft_printf("\nMOVE %s----> ❌", text);
		ft_printf("\nNo way going from [%d][%d] to[%d][%d]\n",
			game->player_y, game->player_x, target_y, target_x);
	}
	return (0);
}

int	on_keypress(int key_pressed, t_game *game)
{
	(void)game;
	if (key_pressed == KEY_ESC)
		on_destroy(game);
	if (!game->exited)
	{
		if (key_pressed == KEY_W || key_pressed == UP)
			try_move(game, game->player_y - 1, game->player_x, "UP");
		else if (key_pressed == KEY_S || key_pressed == DOWN)
			try_move(game, game->player_y + 1, game->player_x, "DOWN");
		else if (key_pressed == KEY_A || key_pressed == LEFT)
			try_move(game, game->player_y, game->player_x - 1, "LEFT");
		else if (key_pressed == KEY_D || key_pressed == RIGHT)
			try_move(game, game->player_y, game->player_x + 1, "RIGHT");
		else if (game->debug)
			ft_printf("\nInvalid Pressed key: %d", key_pressed);
	}
	return (0);
}

static void	start_game(t_game *game)
{
	reset_collectibles(game);
	game->win_width = game->tile_dim * game->map_x;
	game->win_height = game->tile_dim * (game->map_y + 1);
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_exit_error("Error al iniciar Minilib", game);
	game->win = mlx_new_window(game->mlx, game->win_width,
			game->win_height, "so_long");
	if (!game->win)
		ft_exit_error("Error al crear ventana", game);
	load_images(game);
	draw_game(game);
	mlx_hook(game->win, KeyPress, KeyPressMask, &on_keypress, game);
	mlx_hook(game->win, DestroyNotify, StructureNotifyMask, &on_destroy, game);
	mlx_loop_hook(game->mlx, update_anim, game);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 1)
		ft_exit_error("Falta el nombre archivo del mapa a jugar.", &game);
	if (argc != 2)
		ft_exit_error("Numero de argumentos incorrecto.", &game);
	init_game_strucs(&game);
	check_map_basic(argv[1], &game);
	init_maps(&game);
	set_maps(argv[1], &game);
	check_map_full(&game);
	start_game(&game);
	return (0);
}

// Incluir en el main para comprobar leaks al finalizar el programa:
// atexit(ft_get_leaks);

// static void	ft_get_leaks(void)
// {
// 	ft_printf("\n\nCHECKING FOR LEAKS AT EXIT:\n");
// 	system("leaks -q so_long");
// 	ft_printf("\n");
// }

//valgrind --leak-check=full --track-origins=yes ./so_long maps/map4.ber
