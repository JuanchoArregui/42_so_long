/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 18:38:26 by jarregui          #+#    #+#             */
/*   Updated: 2024/05/16 23:17:14 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include "libft.h"
# include "printf.h"
# include "mlx.h"
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
	void			*door_open;
	void			*door_close;
}	t_imgs;

typedef struct s_game
{
	int			debug;

	void		*mlx;
	int			tile_dim;
	int			win_width;
    int 		win_height;
	void		*win;
	t_imgs		imgs;

	size_t		map_x;
	size_t		map_y;
	char		**map_wall;

	char		**map_coll;
	size_t		collectibles;
	size_t		coll_remain;

	char		**map_vstd;
	size_t		visited;

	size_t		exits;
	size_t		exited;
	size_t		exit_x;
	size_t		exit_y;

	size_t		players;
	size_t		player_x;
	size_t		player_y;
	size_t		player_steps;
	size_t		player_score;

}	t_game;


// main.c
int on_destroy(t_game *game);
int on_keypress(int keysym, t_game *game);

// files/images.c
void		open_images(t_game *game);


// files/stuff.c
size_t	ft_strlen_no_n(char *s);
void	ft_exit_error(const char *text, t_game *game);
void	ft_free_game(t_game *game);
void	ft_get_leaks(void);
void	init_game_struc(t_game *game);

// files/map_arg_check.c
void	check_map_basic(char *map, t_game *game);
void	check_map_extension(char *map, t_game *game);
void	read_map(char *map, t_game *game);
void	check_map_dimensions(char *map, t_game *game);
void	check_map_chars(char *map, t_game *game);

//files/maps_stuff.c
void	init_maps(t_game *game);
char	**init_map(t_game *game);
void	populate_map(char **map, size_t map_x, size_t map_y);
void	free_map(char **map, size_t map_y);

// files/maps_set.c
void	set_maps(char *map, t_game *game);
void	set_characters(char chr, size_t x, size_t y, t_game *game);

// files/maps_check.c
void	check_map_full(t_game *game);
void	check_map_boundaries(t_game *game);
void	check_map_playable(t_game *game);
size_t	check_pos(size_t x, size_t y, t_game *game);
size_t	check_mov(size_t x, size_t y, t_game *game);

//files/maps_print.c
void	print_walls(t_game *game);
void	print_colls(t_game *game);
void	print_flood(t_game *game);
void	print_full_map_game(t_game *game);

#endif
