/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:12:20 by jarregui          #+#    #+#             */
/*   Updated: 2024/04/03 12:28:48 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	if (argc == 1)
		ft_error("Introduzca el nombre del archivo con el mapa a jugar.");
	if (argc != 2)
		ft_error("Numero de argumentos incorrecto.");
	check_map(argv[1]);



	return (0);
}

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
