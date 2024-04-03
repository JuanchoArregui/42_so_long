# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juancho <juancho@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/25 15:39:13 by jarregui          #+#    #+#              #
#    Updated: 2023/12/14 12:21:43 by juancho          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# nice tutorials about Makefile:  
#		https://stackoverflow.com/c/42network/questions/1604/1605
#		https://makefiletutorial.com/
#		https://opensource.com/article/18/8/what-how-makefile


#syntax of a typical rule:
#		target: prerequisites
#		<TAB> recipe


# VARIABLES DECLARATION:
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
NAME		=	libft.a
RM			=	/bin/rm -f
SRCS		=	$(wildcard functions/*.c)

OBJS		=	${SRCS:.c=.o}

# RULES DECLARATION:
all:			${NAME}

${NAME}:		${OBJS}
					ar -rc ${NAME} ${OBJS}
					ranlib ${NAME}

clean:
				${RM} ${OBJS}

fclean:			clean
					${RM} ${NAME}

re:				fclean all

.PHONY:			all clean fclean re