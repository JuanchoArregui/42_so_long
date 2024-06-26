/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:02:50 by jarregui          #+#    #+#             */
/*   Updated: 2024/04/03 14:47:07 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"

int	split_buff(char **ptr_buff, char **ptr_ln)
{
	char	*ptr_temp;
	int		check;
	int		buff_len;
	int		buff_nl_len;

	check = 0;
	ptr_temp = NULL;
	buff_len = ft_my_strlen(*ptr_buff);
	buff_nl_len = ft_strlen_n(*ptr_buff);
	if (buff_nl_len > 0 && buff_len > buff_nl_len)
	{
		check += ft_ptr_cpy_ptr(ptr_buff, buff_nl_len, 0, &ptr_temp);
		(*ptr_buff)[buff_nl_len] = '\0';
	}
	check += ft_ptr_cpy_ptr(ptr_buff, 0, ft_my_strlen(*ptr_ln), ptr_ln);
	ft_free_ptr_ptr(ptr_buff);
	*ptr_buff = ptr_temp;
	if (check < 0)
		return (-1);
	if (buff_nl_len > 0)
		return (1);
	return (0);
}

char	*read_until_n_or_0(int fd, char **ptr_buff, char **ptr_ln)
{
	int		rd_bytes;
	int		new_or_end_line;

	rd_bytes = 1;
	new_or_end_line = 0;
	while (!new_or_end_line && rd_bytes > 0)
	{
		*ptr_buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!(*ptr_buff))
			return (NULL);
		rd_bytes = read(fd, *ptr_buff, BUFFER_SIZE);
		if (rd_bytes == -1)
			return (ft_free_ptr_ptr(ptr_buff), NULL);
		else if (rd_bytes == 0)
			return (ft_free_ptr_ptr(ptr_buff), *ptr_ln);
		(*ptr_buff)[rd_bytes] = '\0';
		new_or_end_line = split_buff(ptr_buff, ptr_ln);
		if (new_or_end_line < 0)
			return (NULL);
		else if (new_or_end_line == 1)
			return (*ptr_ln);
	}
	return (ft_free_ptr_ptr(ptr_ln), NULL);
}

char	*get_next_line(int fd)
{
	char		*ptr_ln;
	static char	*ptr_buff;
	int			new_line;
	char		*aux;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ptr_ln = NULL;
	if (ptr_buff != NULL)
	{
		new_line = split_buff(&ptr_buff, &ptr_ln);
		if (new_line < 0)
			return (NULL);
		if (new_line == 1)
			return (ptr_ln);
	}
	aux = ptr_ln;
	ptr_ln = read_until_n_or_0(fd, &ptr_buff, &ptr_ln);
	if (!ptr_ln)
		ft_free_ptr_ptr(&aux);
	return (ptr_ln);
}

// int	main(void)
// {
// 	char	*line;
// 	int		t;
// 	int		i;
// 	char	file_name[17];
// 	int		fd;

// 	t = 0;
// 	while (t < 9)
// 	{
// 		i = 1;
// 		sprintf(file_name, "%s%d%s", "tests/test_", t, ".txt");
// 		fd = open(file_name, O_RDONLY);
// 		printf("\n\n\n\n\nARCHIVO - %d - %s", t++, file_name);
// 		line = get_next_line(fd);
// 		while (line != NULL)
// 		{
// 			printf("\nline [%02d]: \"%s\"", i, line);
// 			i++;
// 			ft_free_ptr_ptr(&line);
// 			line = get_next_line(fd);
// 		}
// 		ft_free_ptr_ptr(&line);
// 		close(fd);
// 	}
// system("leaks -q a.out");
// 	return (0);
// }

// int main(void)
// {
// 	int fd = open("tests/read_error.txt", O_RDONLY);
// 	char *linea;

// 	linea = get_next_line(fd);
// 	printf("%s", linea);
// 	free(linea);

// 	linea = get_next_line(40);//esto va a dar error de lectura
// 	printf("<%s>", linea);
// 	free(linea);

// 	linea = get_next_line(fd);
// 	printf("%s", linea);
// 	free(linea);

// 	linea = get_next_line(fd);
// 	printf("%s", linea);
// 	free(linea);

// 	linea = get_next_line(fd);
// 	printf("%s", linea);
// 	free(linea);

// 	system("leaks -q a.out");
// }

// gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c 
// get_next_line.h -fsanitize=address && ./a.out