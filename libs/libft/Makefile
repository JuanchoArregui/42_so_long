# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/25 15:39:13 by jarregui          #+#    #+#              #
#    Updated: 2024/05/21 09:57:42 by jarregui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# nice tutorials about Makefile:  
#		https://stackoverflow.com/c/42network/questions/1604/1605
#		https://makefiletutorial.com/
#		https://opensource.com/article/18/8/what-how-makefile


#syntax of a typical rule:
#		target: prerequisites
#		<TAB> recipe

# INCLUDE COLOR VARIABLES DECLARATION:
include ../colors.mk

# VARIABLES DECLARATION:
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
NAME	=	libft.a
RM		=	/bin/rm -f
SRCS	=	$(wildcard functions/*.c)

OBJS	=	${SRCS:.c=.o}

# RULES DECLARATION:
all:	${NAME}

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@

# CREAMOS BIBLIOTECA ESTATICA Y NO UN EJECUTABLE (NO HAY MAIN)
${NAME}:	${OBJS}
	ar -rc ${NAME} ${OBJS}
	ranlib ${NAME}

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re:	fclean all

.PHONY:	all clean fclean re