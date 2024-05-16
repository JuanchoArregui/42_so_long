/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:12:20 by jarregui          #+#    #+#             */
/*   Updated: 2024/05/16 12:58:35 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int on_destroy(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
	return (0);
}

int on_keypress(int keysym, t_game *game)
{
	(void)game;
	ft_printf("Pressed key: %d\\n", keysym);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	//BORRAR ESTO ANTES DE ENTREGARRRRRR!!!
	atexit(ft_get_leaks);

	if (argc == 1)
		ft_exit_error("Introduzca el nombre archivo del mapa a jugar.", &game);
	if (argc != 2)
		ft_exit_error("Numero de argumentos incorrecto.", &game);
	init_game_struc(&game);
	check_map_basic(argv[1], &game);
	init_maps(&game);
	set_maps(argv[1], &game);
	check_map_full(&game);
	

	

	game.mlx = mlx_init();
	if (!game.mlx)
		return (1);
	game.win = mlx_new_window(game.mlx, 600, 400, "hi :)");
	if (!game.win)
		return (free(game.mlx), 1);
	// Register key release hook
	mlx_hook(game.win, KeyRelease, KeyReleaseMask, &on_keypress, &game);
 
	// Register destroy hook
	mlx_hook(game.win, DestroyNotify, StructureNotifyMask, &on_destroy, &game);
 
	// Loop over the MLX pointer
	mlx_loop(game.mlx);







	ft_free_maps(&game);
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

// minilibs guide: https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html
// https://reactive.so/post/42-a-comprehensive-guide-to-so_long

//project with pacman: https://github.com/madebypixel02/so_long
