/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:12:20 by jarregui          #+#    #+#             */
/*   Updated: 2024/04/02 11:27:20 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
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
