# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 17:13:29 by jarregui          #+#    #+#              #
#    Updated: 2024/05/21 09:57:18 by jarregui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# INCLUDE COLOR VARIABLES DECLARATION:
include ../colors.mk

NAME = get_next_line.a

SRCS =	files/get_next_line.c\
		files/get_next_line_utils.c

OBJS = ${SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

all: ${NAME}

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@

# CREAMOS BIBLIOTECA ESTATICA Y NO UN EJECUTABLE (NO HAY MAIN)
${NAME}: ${OBJS}
	@ar rc ${NAME} ${OBJS}
	@ranlib ${NAME}

clean: 
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
