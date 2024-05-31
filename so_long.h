/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 18:38:26 by jarregui          #+#    #+#             */
/*   Updated: 2024/05/31 13:15:59 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libs/get_next_line/get_next_line.h"
# include "libs/libft/libft.h"
# include "libs/printf/printf.h"
# include "libs/minilib/minilibx_linux/mlx.h"
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>

/* Size of every sprite */
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

typedef struct s_imgs
{
	void		*wall;
	void		*coll;
	void		*player;
	void		*door_open;
	void		*door_close;
	void		*background;
}	t_imgs;

typedef struct s_game
{
	int			debug;

	void		*mlx;
	int			tile_dim;
	int			win_width;
	int			win_height;
	void		*win;
	
	t_imgs		imgs;

	int			map_y;
	int			map_x;
	char		**map_raw;
	char		**map_wall;
	char		**map_coll;
	int			collectibles;
	int			coll_remain;

	char		**map_vstd;
	int			visited;

	int			exits;
	int			exited;
	int			exit_y;
	int			exit_x;

	int			players;
	int			player_y;
	int			player_x;
	int			player_steps;
	int			player_score;

	int			y;
	int			x;

}	t_game;


// main.c
int		on_destroy(t_game *game);
int		on_keypress(int key_pressed, t_game *game);

// files/map_arg_check.c
void	check_map_basic(char *map, t_game *game);
void	check_map_extension(char *map, t_game *game);
void	read_map(char *map, t_game *game);
void	check_map_dimensions(char *map, t_game *game);
void	check_map_chars(char *map, t_game *game);

//files/maps_stuff.c
void	init_maps(t_game *game);
char	**init_map(t_game *game);
void	populate_map(char **map, int map_y, int map_x);
void	free_map(char **map, int map_y);

// files/maps_set.c
void	set_maps(char *map, t_game *game);
void	set_characters(char chr, int y, int x, t_game *game);

// files/maps_check.c
void	check_map_full(t_game *game);
void	check_map_boundaries(t_game *game);
void	check_map_playable(t_game *game);
int		check_pos(int y, int x, t_game *game);
int		check_mov(int y, int x, t_game *game);

//files/maps_print.c
void	print_walls(t_game *game);
void	print_colls(t_game *game);
void	print_flood(t_game *game);
void	print_full_map_game(t_game *game);


// files/mlx_load_images.c
// Note: auxiliary functions marked as static, so no need to include the here
void	load_images(t_game *game);

// files/mlx_load_background.c
void	create_and_load_background(t_game *game);

// files/mlx_draw_game.c
void	draw_tile(t_game *game, void *img, int x, int y);
void	draw_game(t_game *game);

// files/game_init_strucs.c
void	init_game_strucs(t_game *game);

// files/game_stuff.c
int		ft_strlen_no_n(char *s);
void	ft_exit_error(const char *text, t_game *game);
void	ft_free_game(t_game *game);
void	ft_get_leaks(void);
void	reset_collectibles(t_game *game);



#endif
