/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:12:20 by jarregui          #+#    #+#             */
/*   Updated: 2024/05/16 10:25:12 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;
	void	*img;
	void	*mlx;

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
	print_full_map_game(&game);

	

	mlx = mlx_init();
	img = mlx_new_image(mlx, 1920, 1080);
	mlx_loop(mlx);
	ft_printf("%p", img);

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

	

// 	// mlx_ptr = mlx_init();
// 	// if (!mlx_ptr)
// 	// 	return (1);
// 	// win_ptr = mlx_new_window(mlx_ptr, 600, 400, "hi :)");
// 	// if (!win_ptr)
// 	// 	return (free(mlx_ptr), 1);
// 	// mlx_destroy_window(mlx_ptr, win_ptr);
// 	// mlx_destroy_display(mlx_ptr);
// 	// free(mlx_ptr);
// 	return (0);
// }

// minilibs guide: https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html

//project with pacman: https://github.com/madebypixel02/so_long
