# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 16:13:08 by jarregui          #+#    #+#              #
#    Updated: 2024/03/31 20:06:28 by jarregui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLOR VARIABLES DECLARATION:
DEL_LINE		=	\033[2K
ITALIC			=	\033[3m
BOLD			=	\033[1m
DEF_COLOR		=	\033[0;39m
GRAY			=	\033[0;90m
RED				=	\033[0;91m
GREEN			=	\033[0;92m
YELLOW			=	\033[0;93m
BLUE			=	\033[0;94m
MAGENTA			=	\033[0;95m
CYAN			=	\033[0;96m
WHITE			=	\033[0;97m
BLACK			=	\033[0;99m
ORANGE			=	\033[38;5;209m
BROWN			=	\033[38;2;184;143;29m
DARK_GRAY		=	\033[38;5;234m
MID_GRAY		=	\033[38;5;245m
DARK_GREEN		=	\033[38;2;75;179;82m
DARK_YELLOW		=	\033[38;5;143m

# REQUIRED HEADERS for LInux or Mac
# ifeq ($(shell uname), Linux)
# 	INCLUDES = -I/usr/include -Imlx
# else
# 	INCLUDES = -I/opt/X11/include -Imlx
# endif
 
# MLX_DIR = ./mlx
# MLX_LIB = $(MLX_DIR)/libmlx_$(UNAME).a

# REQUIRED LIBRARIES for LInux or Mac
# ifeq ($(shell uname), Linux)
# 	MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
# else
# 	MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
# endif

SRCS		=	main.c \
			./my_files/stuff.c \
# ft_printf.c \
# fts_get.c \
# fts_handling_main_txt.c \
# fts_len.c \
# fts_put_strs.c \
# fts_save_nums.c \
# fts_save_strs.c \
# fts_str.c \


SRCS_BONUS	=	./my_bonus/stuff_bonus.c

# INCLUD =		so_long.h \
# 				./mlx/mlx.h

# INCLUD_BNS = so_long_bonus.h \
# 			./mlx/mlx.h

# VARIABLES DECLARATION:
NAME			=	so_long
BONUS_NAME		=	so_long_bonus
CC				=	gcc
RM				=	rm -f
AR				=	ar rc
RN				=	ranlib
# CFLAGS		=	-Wall -Wextra -Werror -fsanitize=address
CFLAGS			=	-Wall -Wextra -Werror -MMD
MLX_FLAGS		=	-L. -lmlx -framework OpenGL -framework AppKit

.c.o:
				@echo "$(BROWN)Compiling   ${MAGENTA}→   $(CYAN)$< $(DEF_COLOR)"
				@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

OBJS			=	${SRCS:.c=.o}
BONUS_OBJECTS	=	${SRCS_BONUS:.c=.o}
DEPS			=	$(addsuffix .d, $(basename $(SRCS)))
DEPS2			=	$(addsuffix .d, $(basename $(SRCS_BONUS)))

# RULES DECLARATION:
all:		$(NAME)

-include $(DEPS)
${NAME}:	${OBJS}
				@echo "\n${ORANGE}Minilibx compilation $(DEF_COLOR)\n"
				@make -C ./mlx all
				@cp ./mlx/libmlx.a .
				@$(CC) $(SRCS) $(MLX_FLAGS) -o $(NAME)
				@echo "$(GREEN)✓ Created ${NAME}$(DEF_COLOR)\n"


-include $(DEPS2)
bonus: ${BONUS_OBJECTS}
				@echo "\n${ORANGE}Minilibx compilation $(DEF_COLOR)\n"
				@touch $@
				@make -C ./mlx all
				@cp ./mlx/libmlx.a .
				@$(CC) $(SRCS_BONUS) $(LIB) -o $(BONUS_NAME)
				@echo "$(GREEN)✓ Created ${BONUS_NAME}$(DEF_COLOR)\n"

clean:
				@make -C ./mlx clean
				@${RM} ${OBJS} ${BONUS_OBJECTS}
				@${RM} ${DEPS} ${DEPS2}
				@echo "\n$(GREEN)✓ All objects cleaned successfully$(DEF_COLOR)\n"

fclean:
				@make -C ./mlx clean
				@${RM} ${OBJS} ${BONUS_OBJECTS}
				@${RM} ${DEPS} ${DEPS2}
				@${RM} bonus
				@${RM} ${NAME} ${BONUS_NAME} libmlx.a
				@echo "\n$(GREEN)✓ All objects and executable cleaned successfully$(DEF_COLOR)\n"


re: fclean all

.PHONY: all clean fclean re