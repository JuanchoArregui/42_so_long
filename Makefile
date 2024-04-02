# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 16:13:08 by jarregui          #+#    #+#              #
#    Updated: 2024/04/02 11:18:35 by jarregui         ###   ########.fr        #
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

# VARIABLES DECLARATION:
NAME			=	so_long
BONUS_NAME		=	so_long_bonus
CC				=	gcc
RM				=	rm -f
AR				=	ar rc
RN				=	ranlib
# CFLAGS		=	-Wall -Wextra -Werror -fsanitize=address
CFLAGS			=	-Wall -Wextra -Werror

# MinilibX directory, macro and flags for LInux or Mac
ifeq ($(shell uname), Linux)
	MLX_DIR = ./mlx/linux/
	MACROS = -DLINUX
	CFLAGS +=  -Wno-unused-result
else
	MLX_DIR = ./mlx/mac/
	MACROS = -DMAC
endif
MLX_FLAGS		=	-L$(MLX_DIR) -lmlx
ifeq ($(shell uname), Linux)
	MLX_FLAGS += -lXext -lX11 -lm -lbsd
else
	MLX_FLAGS += -framework OpenGL -framework AppKit
endif

MLX_LIB = $(MLX_DIR)libmlx.a
LIBFT_DIR = ./my_libs/libft/
LIBFT_LIB = $(LIBFT_DIR)libft.a
INCLUDE_FLAGS	=	-I$(LIBFT_DIR) -I$(MLX_DIR)

OBJS			=	${SRCS:.c=.o}
BONUS_OBJECTS	=	${SRCS_BONUS:.c=.o}

# RULES DECLARATION:
all: subsystems	$(NAME)

%.o : %.c
	@echo "$(BROWN)Compiling [$<]...${DEF_COLOR}"
	@$(CC) $(CFLAGS) -c -o $@ $<  $(INCLUDE_FLAGS)

subsystems:
	@echo "\n${ORANGE}********************** $(DEF_COLOR)"
	@echo "${ORANGE}Minilibx compilation: $(DEF_COLOR)"
	make -C $(MLX_DIR) all
	@echo "$(GREEN)✓ Created ${MLX_LIB} $(DEF_COLOR)"
	@echo "\n${ORANGE}********************** $(DEF_COLOR)"
	@echo "${ORANGE}Libft compilation: $(DEF_COLOR)"
	make -C $(LIBFT_DIR) all
	@echo "$(GREEN)✓ Created ${LIBFT_LIB} $(DEF_COLOR)"


${NAME}:	${OBJS}
	@echo "\n${ORANGE}********************** $(DEF_COLOR)"
	@echo "${ORANGE}So_long compilation $(DEF_COLOR)"
	@$(CC) ${CFLAGS} $(INCLUDE_FLAGS) $(MLX_FLAGS) $(MACROS) ${OBJS} ${MLX_LIB} ${LIBFT_LIB} -o $(NAME)
	@echo "$(GREEN)✓ Created ${NAME}$(DEF_COLOR)\n"

bonus: ${BONUS_OBJECTS}
	@echo "\n${ORANGE}Minilibx compilation $(DEF_COLOR)\n"
	@touch $@
	@make -C ${MLX_DIR} all
	@cp ${MLX_DIR}/libmlx.a .
	@$(CC) $(SRCS_BONUS) $(MLX_FLAGS) -o $(BONUS_NAME)
	@echo "$(GREEN)✓ Created ${BONUS_NAME}$(DEF_COLOR)\n"

clean:
	@${RM} ${OBJS} ${BONUS_OBJECTS}
	@echo "\n$(GREEN)✓ All objects cleaned successfully$(DEF_COLOR)\n"

fclean: clean
	@${RM} ${NAME} ${BONUS_NAME}
	@echo "\n$(GREEN)✓ All executable cleaned successfully$(DEF_COLOR)\n"

re: fclean all

.PHONY: all bonus clean fclean re