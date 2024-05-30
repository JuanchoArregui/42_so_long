/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:12:20 by jarregui          #+#    #+#             */
/*   Updated: 2024/05/30 15:05:06 by jarregui         ###   ########.fr       */
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
	
	ft_free_game(game);
	exit(0);
	return (0);
}

int move_up(t_game *game)
{
	if (!game->map_wall[game->player_x][game->player_y + 1])
	{
		game->player_y += 1;
		if (game->map_coll[game->player_x][game->player_y])
		{
			game->map_coll[game->player_x][game->player_y] = 0;
			game->coll_remain -= 1;
			//aqui checar si coll_remain == 0 y si es así abrir la puerta!
		}
		//Aqui poner el codigo o función para que imprima esa tile o el mapa entero
		return (1);
	}
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
		move_up(game);
		// 	moved = move_to(game, game->player.tile->up);
	}
	else if (key_pressed == KEY_S)
	{
		ft_printf("\nDOWN");
		// 	moved = move_to(game, game->player.tile->down);
	}
	else if (key_pressed == KEY_A)
	{
		ft_printf("\nLEFT");
		// 	moved = move_to(game, game->player.tile->left);
	}
	else if (key_pressed == KEY_D)
	{
		ft_printf("\nRIGHT");
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

void start_game(t_game *game)
{
	reset_collectibles(game);
	game->win_width = game->tile_dim * game->map_x;
	game->win_height = game->tile_dim * game->map_y;

	ft_printf("\n55555");
	ft_printf("\ngame->map_x: %d", game->map_x);
	ft_printf("\ngame->map_y: %d", game->map_y);
	ft_printf("\ngame->win_width: %d", game->win_width);
	ft_printf("\ngame->win_height: %d", game->win_height);
	game->mlx = mlx_init();

	ft_printf("\nincializado mlx");




	if (!game->mlx)
		ft_exit_error("Error al iniciar Minilib", game);
	game->win = mlx_new_window(game->mlx, game->win_width, game->win_height, "so_long");
	if (!game->win)
		ft_exit_error("Error al crear ventana", game);

	ft_printf("\ncreada ventana win");

	// Cargar las imágenes
	load_images(game);

	// Dibujar el mapa, personaje y coleccionables
	draw_game(game);


	

	// Register key press hook
	mlx_hook(game->win, KeyPress, KeyPressMask, &on_keypress, &game);
 
	// Register destroy hook
	mlx_hook(game->win, DestroyNotify, StructureNotifyMask, &on_destroy, &game);
 
	// Loop over the MLX pointer
	mlx_loop(game->mlx);

	ft_printf("\n antes de salir de start_game");

	
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

	 printf("Game structure initialized.\n");

	ft_printf("\n00000000");
	ft_printf("\ngame->map_x: %d", game.map_x);
	ft_printf("\ngame->map_y: %d", game.map_y);
	ft_printf("\ngame.players: %d", game.players);


	check_map_basic(argv[1], &game);

	ft_printf("\n111111");
	ft_printf("\ngame.map_x: %d", game.map_x);
	ft_printf("\ngame.map_y: %d", game.map_y);
	ft_printf("\ngame.players: %d", game.players);

	init_maps(&game);

	ft_printf("\n22222");
	ft_printf("\ngame.map_x: %d", game.map_x);
	ft_printf("\ngame.map_y: %d", game.map_y);
	ft_printf("\ngame.players: %d", game.players);

	set_maps(argv[1], &game);

	ft_printf("\n3333");
	ft_printf("\ngame.map_x: %d", game.map_x);
	ft_printf("\ngame.map_y: %d", game.map_y);
	ft_printf("\ngame.players: %d", game.players);


	check_map_full(&game);

	ft_printf("\n44444");
	ft_printf("\ngame.map_x: %d", game.map_x);
	ft_printf("\ngame.map_y: %d", game.map_y);
	ft_printf("\ngame.players: %d", game.players);

	start_game(&game);
	

	



	ft_printf("\n antes de terminar main");

	ft_free_game(&game);
	return (0);
}


// TODO: mirar norma y empezar con la parte gr'afica






// int	main(void)
// {
// 	void	*img;
// 	void	*mlx;

// 	mlx = mlx_init();
// 	img = mlx_new_image(mlx, 1920, 1080);

	

// 	// mlx = mlx_init();
// 	// if (!mlx)
// 	// 	return (1);
// 	// win = mlx_new_window(mlx, 600, 400, "hi :)");
// 	// if (!win)
// 	// 	return (free(mlx), 1);
// 	// mlx_destroy_window(mlx, win);
// 	// mlx_destroy_display(mlx);
// 	// free(mlx);
// 	return (0);
// }

//valgrind --leak-check=full --track-origins=yes ./so_long maps/map4.ber

// minilibs guide: https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html
// https://reactive.so/post/42-a-comprehensive-guide-to-so_long

//project with pacman: https://github.com/madebypixel02/so_long
