/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 18:38:26 by jarregui          #+#    #+#             */
/*   Updated: 2024/04/17 16:56:14 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "printf.h"
# include "get_next_line.h"
# include "mlx.h"
# include <stdlib.h>

typedef struct s_game
{
	int			debug;
	size_t		map_x;
	size_t		map_y;
	size_t		map_z;
	int			*map_array;

	int			collectibles;
	int			exits;
	int			players;

	int			player_x;
	int			player_y;
	int			player_steps;
	int			player_score;
}	t_game;

// files/stuff.c
size_t	ft_strlen_no_n(char *s);
void	ft_exit_error(const char *text, t_game *game);
void	ft_get_leaks(void);
void	init_game(t_game *game);

// files/map_arg_check.c
void	check_map(char *map, t_game *game);
void	check_map_extension(char *map, t_game *game);
void	read_map(char *map, t_game *game);
void	check_map_dimensions(char *map, t_game *game);
void	check_map_chars(char *map, t_game *game);

// files/map_set_game.c
void	set_map_array(char *map, t_game *game);
size_t	indx(size_t x, size_t y, size_t z, t_game *game);
void	check_map_array(t_game *game);
void	check_map_boundaries(t_game *game);

// # include<unistd.h>
// # include<limits.h>
// # include<stdio.h>
// # include<fcntl.h>


// typedef struct s_list
// {
// 	void	*mlx;
// 	void	*win;
// 	void	*bush;
// 	void	*fond;
// 	void	*poke;
// 	void	*npc;
// 	void	*npcstart;
// 	void	*npcmv;
// 	void	*npcleft;
// 	void	*npclmv;
// 	void	*npcright;
// 	void	*npcrmv;
// 	void	*npcback;
// 	void	*npcbmv;
// 	void	*imgexit;
// 	int		errors;
// 	int		moves;
// 	int		npccontrol;
// 	int		linecontrol;
// 	int		x;
// 	int		y;
// 	int		consum;
// 	int		ex;
// 	int		back;
// 	int		wall;
// 	int		player;
// 	int		enemy;
// 	int		height_l;
// 	int		width_l;
// 	char	*big_line;
// }	t_list;

// int		init_data(t_list *d, char *map);
// int		ft_strlen(const char *s);
// int		key_press(int key, t_list *d);
// int		check_exit(t_list *d, char letter);
// int		ft_free(t_list *d);
// void	print_map(t_list *d);
// void	read_map(char *map, t_list *d);
// void	ft_bzero(void *s, size_t n);
// void	ft_error(t_list *d, int num);
// void	*ft_memset(void *b, int c, size_t len);
// void	*ft_calloc(size_t count, size_t size);
// char	*get_next_line(int fd);
// char	*ft_strjoin(char *s1, char *s2);
// char	*ft_strchr(const char *s, int c);
// char	*ft_itoa(int n);

#endif
