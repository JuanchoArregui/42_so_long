# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/18 13:58:00 by jarregui          #+#    #+#              #
#    Updated: 2024/05/21 09:57:54 by jarregui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# INCLUDE COLOR VARIABLES DECLARATION:
include ../colors.mk

NAME		=	printf.a

# VARIABLES DECLARATION:
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
# CFLAGS		=	-Wall -Wextra -Werror -fsanitize=address
ARFLAGS		=	rcs
RM			=	/bin/rm -f
EXEC_NAME	=	a.out

SRCS		=	$(wildcard functions/*.c)

OBJS		=	${SRCS:.c=.o}

# RULES DECLARATION:
all:			${NAME}

${NAME}:		${OBJS}
					ar -rc ${NAME} ${OBJS}
					ranlib ${NAME}

clean:
				${RM} ${OBJS} ${OBJS_BONUS} ${EXEC_NAME}

fclean:			clean
					${RM} ${NAME}
 
re:				fclean all

.PHONY:			all clean fclean re bonus