# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 13:58:00 by jarregui          #+#    #+#              #
#    Updated: 2023/12/05 13:59:56 by jarregui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARIABLES DECLARATION:
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
# CFLAGS		=	-Wall -Wextra -Werror -fsanitize=address
ARFLAGS		=	rcs
NAME		=	libftprintf.a
RM			=	/bin/rm -f
EXEC_NAME	=	a.out

# REQUIRED HEADERS for LInux or Mac
ifeq ($(shell uname), Linux)
	INCLUDES = -I/usr/include -Imlx
else
	INCLUDES = -I/opt/X11/include -Imlx
endif
 
MLX_DIR = ./mlx
MLX_LIB = $(MLX_DIR)/libmlx_$(UNAME).a

# REQUIRED LIBRARIES for LInux or Mac
ifeq ($(shell uname), Linux)
	MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
else
	MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
endif

SRCS		=	ft_printf.c \
				fts_get.c \
				fts_handling_main_txt.c \
				fts_len.c \
				fts_put_strs.c \
				fts_save_nums.c \
				fts_save_strs.c \
				fts_str.c \


# SRCS_BONUS	=	fts_bonus.c

SRCS_TEST	=	./tests/fts_test.c \
				./tests/fts_tests_a.c \
				./tests/fts_tests_b.c \

OBJS		=	${SRCS:.c=.o}
# OBJS_BONUS	=	${SRCS_BONUS:.c=.o}
OBJS_TEST	=	${SRCS_TEST:.c=.o}

# RULES DECLARATION:
all:			$(MLX_LIB) $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)
 
$(MLX_LIB):
	@make -C $(MLX_DIR)


# ${NAME}:		${OBJS}
# 					ar -rc ${NAME} ${OBJS}
# 					ranlib ${NAME}

clean:
				${RM} ${OBJS} ${OBJS_BONUS} ${OBJS_TEST} ${EXEC_NAME}

fclean:			clean
					${RM} ${NAME}

# test:			${OBJS} ${OBJS_TEST}
# 				${CC} ${CFLAGS} -o ${EXEC_NAME} ${OBJS} ${OBJS_TEST}
 
re:				fclean all

.PHONY:			all clean fclean re bonus test