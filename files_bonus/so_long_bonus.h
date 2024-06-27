/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 18:38:26 by jarregui          #+#    #+#             */
/*   Updated: 2024/06/27 19:00:39 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libs/get_next_line/get_next_line.h"
# include "../libs/libft/libft.h"
# include "../libs/printf/printf.h"
# include "../libs/minilib/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include <math.h>

/* key codes */
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define NUM_FRAMES 10

typedef struct s_img
{
	void		*ptr;
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
}	t_img;

typedef struct s_imgs
{
	t_img		wall;
	t_img		coll;
	t_img		coll_frame;
	t_img		player;
	t_img		enemy_a;
	t_img		enemy_b;
	t_img		door_open;
	t_img		door_close;
	t_img		bg;
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

	int			enemy;
	int			enem_y;
	int			enem_x;

	int			y;
	int			x;

	int			loop_counter;
	int			loop_current_frame;
}	t_game;

// files_bonus/main.c
int		on_destroy(t_game *game);
int		on_keypress(int key_pressed, t_game *game);

// files_bonus/map_arg_check.c
void	check_map_basic(char *map, t_game *game);
void	check_map_extension(char *map, t_game *game);
void	read_map(char *map, t_game *game);
void	check_map_dimensions(char *map, t_game *game);
void	check_map_chars(char *map, t_game *game);

//files_bonus/maps_stuff.c
void	init_maps(t_game *game);
char	**init_map(t_game *game);
void	populate_map(char **map, int map_y, int map_x);
void	free_map(char **map, int map_y);

// files_bonus/maps_set.c
void	set_maps(char *map, t_game *game);
void	set_characters(char chr, int y, int x, t_game *game);

// files_bonus/maps_check.c
void	check_map_full(t_game *game);
void	check_map_boundaries(t_game *game);
void	check_map_playable(t_game *game);
int		check_pos(int y, int x, t_game *game);
int		check_mov(int y, int x, t_game *game);

//files_bonus/maps_print.c
void	print_walls(t_game *game);
void	print_colls(t_game *game);
void	print_flood(t_game *game);
void	print_full_map_game(t_game *game);

// files_bonus/mlx_load_images.c
// Note: auxiliary functions marked as static, so no need to include the here
void	load_images(t_game *game);

// files_bonus/mlx_draw_game.c
void	draw_tile(t_game *game, void *img, int x, int y);
void	draw_game(t_game *game);

// files_bonus/game_init_strucs.c
void	init_game_strucs(t_game *game);

// files_bonus/game_stuff.c
int		ft_strlen_no_n(char *s);
void	ft_exit_error(const char *text, t_game *game);
void	ft_free_game(t_game *game);
void	reset_collectibles(t_game *game);

// files_bonus/mlx_animate_game.c
void	set_enemy(t_game *game);
void	move_enemy(t_game *game, int dif_x, int dif_y);
void	set_img_dims(t_game *game, t_img *img, int dim_x, int dim_y);
int		update_anim(t_game *game);
void	generate_frame(t_game *game, t_img *sprite, t_img *frame);

// files_bonus/game_random.c
void	generate_random_number(unsigned int *random_number, t_game *game);
int		get_random_enemy_number(t_game *game);
void	transform_coll_to_enemy(t_game *game, int coll_enemy);
void	check_exit(t_game *game);
void	check_death(t_game *game);

#endif
