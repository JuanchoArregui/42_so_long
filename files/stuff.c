/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stuff.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 19:53:40 by jarregui          #+#    #+#             */
/*   Updated: 2024/04/03 12:30:07 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// void	ft_error(char **ptr_char, t_array_int *arg_num)
void	ft_error(const char *text)
{
	write(2, "Error\n", 6);
	if (text != NULL && *text != '\0')
		ft_printf("%s\n", text);
	exit(0);
}

void	check_map(char *file_name)
{
	check_map_extension(file_name);
}

void	check_map_extension(char *file_name)
{
	int	i;

	i = ft_strlen(file_name);
	if (i >= 4 && file_name[i - 4] == '.' && file_name[i - 3] == 'b'
		&& file_name[i - 2] == 'e' && file_name[i - 1] == 'r')
		;
	else
		ft_error("extensión de archivo incorrecta. Debe ser .ber");
}