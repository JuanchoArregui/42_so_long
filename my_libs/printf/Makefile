# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juancho <juancho@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/18 13:58:00 by jarregui          #+#    #+#              #
#    Updated: 2023/12/14 12:44:23 by juancho          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARIABLES DECLARATION:
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
# CFLAGS		=	-Wall -Wextra -Werror -fsanitize=address
ARFLAGS		=	rcs
NAME		=	printf.a
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