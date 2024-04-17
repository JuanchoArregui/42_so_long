/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:12:20 by jarregui          #+#    #+#             */
/*   Updated: 2024/04/17 17:08:50 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	//BORRAR ESTO ANTES DE ENTREGARRRRRR!!!
	atexit(ft_get_leaks);

	if (argc == 1)
		ft_exit_error("Introduzca el nombre archivo del mapa a jugar.", &game);
	if (argc != 2)
		ft_exit_error("Numero de argumentos incorrecto.", &game);
	init_game(&game);
	check_map(argv[1], &game);
	set_map_array(argv[1], &game);
	check_map_array(&game);

	free(game.map_array);
	return (0);
}



//TODO: 
//set_map_array()  reduciir nº lineas y que cumpla norma:
// imprimir capa bordes
// imprimir capa collectibles
//Mirar como checar que el mapa sea resoluble ?????








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
