# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 17:13:29 by jarregui          #+#    #+#              #
#    Updated: 2024/05/21 12:39:55 by jarregui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# INCLUDE COLOR VARIABLES DECLARATION:
include ../colors.mk

LIB_NAME = GET_NEXT_LINE LIBRARY

NAME = get_next_line.a

SRCS =	files/get_next_line.c\
		files/get_next_line_utils.c

OBJS = ${SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

all: ${NAME}

%.o: %.c
	@echo "${ORANGE}${LIB_NAME} compiling file: $(BROWN)[$<]...${DEF_COLOR}"
	@${CC} ${CFLAGS} -c $< -o $@

# CREAMOS BIBLIOTECA ESTATICA Y NO UN EJECUTABLE (NO HAY MAIN)
${NAME}: ${OBJS}
	@ar rc ${NAME} ${OBJS}
	@ranlib ${NAME}
	@echo "$(GREEN)✓ Created ${NAME}$(DEF_COLOR)\n"

clean: 
	@${RM} ${OBJS}
	@echo "\n$(GREEN)✓ All objects from ${LIB_NAME} cleaned successfully$(DEF_COLOR)\n"

fclean: clean
	@${RM} ${NAME}
	@echo "\n$(GREEN)✓ All executable from ${LIB_NAME} cleaned successfully $(DEF_COLOR)\n"


re: fclean all

.PHONY: all clean fclean re
