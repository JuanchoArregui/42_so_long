/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stuff.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 19:53:40 by jarregui          #+#    #+#             */
/*   Updated: 2024/04/16 10:43:40 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_strlen_no_n(char *s)
{
	size_t	length;

	length = ft_strlen(s);
	printf("\n\n\n* length: %zu, %c", length, s[length - 1]);

	if (s[length - 1] != '\n')
		printf("\n---- %c", s[length - 1]);

		
	if (length && s[length - 1] == '\n')
		length -= 1;

	printf("\nto return length: %zu", length);


	return (length);
}

void	ft_exit_error(const char *text, t_game *game)
{
	write(2, "Error\n", 6);
	if (text != NULL && *text != '\0')
		ft_printf("❌ %s\n\n", text);
	if (game->debug)
	{
		ft_printf("");
	}
	exit(0);
}

void	ft_get_leaks(void)
{
	system("leaks -q so_long");
}




void	check_map(char *map, t_game *game)
{
	check_map_extension(map, game);
	read_map(map, game);
	check_map_dimensions(map, game);
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
}

void	read_map(char *map, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_exit_error("Error al abrir el archivo.", game);

	if (game->debug)
		ft_printf(" \nMapa proporcionado:\n");
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
	int		i;
	size_t	length;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_exit_error("Error al abrir el archivo.", game);
	line = get_next_line(fd);
	game->map_width = ft_strlen_no_n(line);
	i = 0;
	while (line != NULL)
	{
		i++;
		free(line);
		line = get_next_line(fd);
		length = ft_strlen_no_n(line);
		if (line != NULL && game->map_width != length)
		{
			if (game->debug)
			{

				ft_printf("\nMap dim. KO: %d x %d. %s", game->map_width, length, line);
			}
			free(line);
			ft_exit_error("El mapa no es rectangular", game);
		}
	}
	game->map_height = i;
	if (game->debug)
		ft_printf("\nMap dim. OK: %d x %d", game->map_width, game->map_height);
}
