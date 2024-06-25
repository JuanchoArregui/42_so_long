/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_arg_check_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 19:53:40 by jarregui          #+#    #+#             */
/*   Updated: 2024/06/25 15:34:52 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_map_basic(char *map, t_game *game)
{
	check_map_extension(map, game);
	read_map(map, game);
	if (game->debug)
		ft_printf("\n✅ Map extension OK: '.ber'\n");
	check_map_dimensions(map, game);
	if (game->map_y < 3)
		ft_exit_error("Error altura mínima mapa", game);
	if (game->debug)
		ft_printf("\n✅ Map dim. OK. array2d[y][x]:  [%d][%d]\n",
			game->map_y, game->map_x);
	check_map_chars(map, game);
	if (game->debug)
		ft_printf("\n✅ Map valid chars OK.\n");
}

void	check_map_extension(char *map, t_game *game)
{
	int	i;

	i = ft_strlen(map);
	if (i >= 4 && map[i - 4] == '.' && map[i - 3] == 'b'
		&& map[i - 2] == 'e' && map[i - 1] == 'r')
		;
	else
		ft_exit_error("extensión de archivo incorrecta. Debe ser .ber", game);
	if (game->debug)
		ft_printf("\n✅ Map extension is .ber\n");
}

void	read_map(char *map, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_exit_error("Error al abrir el archivo.", game);
	else if (game->debug)
		ft_printf("\n✅ Map archivo abierto y legible.\n");
	if (game->debug)
		ft_printf(" \n\n\n🗺️  Mapa proporcionado:\n\n");
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (game->debug)
			ft_printf("%s", line);
		if (line)
			free(line);
		line = get_next_line(fd);
	}
	if (game->debug)
		ft_printf("\n\n");
}

void	check_map_dimensions(char *map, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_exit_error("Error al abrir el archivo.", game);
	line = get_next_line(fd);
	while (line != NULL)
	{
		game->map_x = ft_strlen_no_n(line);
		if (game->map_x < 3)
		{
			free(line);
			ft_exit_error("Error ancho mínimo mapa o linea vacía", game);
		}
		game->map_y++;
		free(line);
		line = get_next_line(fd);
		if (line != NULL && game->map_x != ft_strlen_no_n(line))
		{
			free(line);
			ft_exit_error("El mapa no es rectangular", game);
		}
	}
}

void	check_map_chars(char *map, t_game *game)
{
	int		fd;
	char	*line;
	int		len;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_exit_error("Error al abrir el archivo.", game);
	line = get_next_line(fd);
	while (line != NULL)
	{
		len = ft_strlen_no_n(line);
		while (len > 0)
		{
			if (line[len - 1] != '\n' && line[len - 1] != 'C'
				&& line[len - 1] != 'E' && line[len - 1] != 'P'
				&& line[len - 1] != '0' && line[len - 1] != '1')
				ft_exit_error("Caracteres inválidos", game);
			len--;
		}
		free(line);
		line = get_next_line(fd);
	}
}
