/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:12:20 by jarregui          #+#    #+#             */
/*   Updated: 2024/06/01 12:11:41 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//TODO:
// revisar map_x y map_y que veo que no mantienen el valor. Qué passa???
//mirar si puede ser por usar size_t en vez de int
//repasar asignación de valores
//al liberar los mapas (map_x llega mal) y también me da SIGSEGV 

//KKKK

int on_destroy(t_game *game)
{
	ft_printf("\n******EVENTO ON DETROY************");
	ft_printf("\n******game->map_y: %d************", game->map_y);
	
	ft_free_game(game);
	exit(0);
	return (0);
}

int	move_up(t_game *game)
{
	ft_printf("\nMOVE UP");
	ft_printf("\nplayer en pos[%d][%d] checkeing for [%d][%d]", game->player_y, game->player_x,  game->player_y - 1, game->player_x);
	
	if (!game->map_wall[game->player_y - 1][game->player_x])
	{
		ft_printf("\nMOVE UP----> OK");
		game->player_y -= 1;
		if (game->map_coll[game->player_y][game->player_x])
		{
			game->map_coll[game->player_y][game->player_x] = 0;
			game->coll_remain -= 1;
		}
		draw_game(game);
		return (1);
	}
	ft_printf("\nMOVE UP----> KOOO. hay pared");

	return (0);
}

static int	try_move(t_game *game, int target_y, int target_x)
{
	ft_printf("\nTRYING MOVE");
	ft_printf("\nplayer en pos[%d][%d] checkeing for [%d][%d]", game->player_y, game->player_x,  target_y, target_x);
	
	if (!game->map_wall[target_y][target_x])
	{
		ft_printf("\nMOVE ----> OK");
		game->player_y = target_y;
		game->player_x = target_x;
		if (game->map_coll[target_y][target_x])
		{
			game->map_coll[target_y][target_x] = 0;
			game->coll_remain -= 1;
		}
		draw_game(game);
		return (1);
	}
	ft_printf("\nMOVE ----> KOOO. hay pared");

	return (0);
}

int on_keypress(int key_pressed, t_game *game)
{
	(void)game;
	

	if (key_pressed == KEY_ESC)
	{
		ft_printf("\nESC");
		on_destroy(game);
	}
	else if (key_pressed == KEY_W)
	{
		ft_printf("\nUP");
		// move_up(game);
		try_move(game, game->player_y - 1, game->player_x);
		// 	moved = move_to(game, game->player.tile->up);
	}
	else if (key_pressed == KEY_S)
	{
		ft_printf("\nDOWN");
		try_move(game, game->player_y + 1, game->player_x);

		// 	moved = move_to(game, game->player.tile->down);
	}
	else if (key_pressed == KEY_A)
	{
		ft_printf("\nLEFT");
		try_move(game, game->player_y, game->player_x - 1);

		// 	moved = move_to(game, game->player.tile->left);
	}
	else if (key_pressed == KEY_D)
	{
		ft_printf("\nRIGHT");
		try_move(game, game->player_y, game->player_x + 1);

		// 	moved = move_to(game, game->player.tile->right);
	}
	else{
		ft_printf("\n\nPressed key: %d", key_pressed);
	}


	// if (moved)
	// 	printf("Moves -> %02d\n", ++game->moves);


	// else if (key == RESET)
	// 	return (reset(game));


	return (0);
}

void	start_game(t_game *game)
{
	reset_collectibles(game);
	game->win_width = game->tile_dim * game->map_x;
	game->win_height = game->tile_dim * game->map_y;
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
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game	game;

	//BORRAR ESTO ANTES DE ENTREGARRRRRR!!!
	atexit(ft_get_leaks);
	// Y QUITAR FLAGS SANITIZE

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
	

	



	ft_printf("\n AQUI LLEGO?????????????????? antes de terminar main");
	ft_free_game(&game);

	return (0);
}

//valgrind --leak-check=full --track-origins=yes ./so_long maps/map4.ber

// minilibs guide: https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html
// https://reactive.so/post/42-a-comprehensive-guide-to-so_long

//project with pacman: https://github.com/madebypixel02/so_long
