# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 16:13:08 by jarregui          #+#    #+#              #
#    Updated: 2024/06/27 19:03:21 by jarregui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# INCLUDE COLOR VARIABLES DECLARATION:
include libs/colors.mk

# REQUIRED HEADERS for LInux or Mac
ifeq ($(shell uname), Linux)
	INCLUDES = -I/usr/include -Imlx
else
	INCLUDES = -I/opt/X11/include -Imlx
endif

SRCS		=	files/main.c \
			files/game_init_strucs.c \
			files/game_stuff.c \
			files/map_arg_check.c \
			files/maps_check.c \
			files/maps_print.c \
			files/maps_set.c \
			files/maps_stuff.c \
			files/mlx_draw_game.c \
			files/mlx_load_images.c \
			
SRCS_BONUS	=	files_bonus/main_bonus.c \
			files_bonus/game_init_strucs_bonus.c \
			files_bonus/game_stuff_bonus.c \
			files_bonus/map_arg_check_bonus.c \
			files_bonus/maps_check_bonus.c \
			files_bonus/maps_print_bonus.c \
			files_bonus/maps_set_bonus.c \
			files_bonus/maps_stuff_bonus.c \
			files_bonus/mlx_draw_game_bonus.c \
			files_bonus/mlx_load_images_bonus.c \
			files_bonus/mlx_animate_game_bonus.c \
			files_bonus/game_random_bonus.c \

# VARIABLES DECLARATION:
PROY_NAME		=	SO_LONG
NAME			=	so_long
BONUS_NAME		=	so_long_bonus
CC				=	gcc
RM				=	rm -f
AR				=	ar rc
RN				=	ranlib
# CFLAGS			=	-g -Wall -Wextra -Werror -fsanitize=address
CFLAGS			=	-Wall -Wextra -Werror

# MinilibX directory, macro and flags for LInux
MLX_DIR = libs/minilib
CFLAGS +=  -Wno-unused-result
MLX_FLAGS		=	-L$(MLX_DIR) -lmlx
MLX_FLAGS += -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

MLX_LIB = $(MLX_DIR)/libmlx.a
LIBFT_DIR = libs/libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
PRINTF_DIR = libs/printf
PRINTF_LIB = $(PRINTF_DIR)/printf.a
GET_NEXT_LINE_DIR = libs/get_next_line
GET_NEXT_LINE_LIB = $(GET_NEXT_LINE_DIR)/get_next_line.a
INCLUDE_FLAGS	= -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(GET_NEXT_LINE_DIR) -I$(MLX_DIR) 

OBJS			=	${SRCS:.c=.o}
BONUS_OBJECTS	=	${SRCS_BONUS:.c=.o}
LIBS			=	${MLX_LIB} ${LIBFT_LIB} ${PRINTF_LIB} ${GET_NEXT_LINE_LIB}

# RULES DECLARATION:
all: subsystems $(NAME)

%.o : %.c
	@echo "${ORANGE}${PROY_NAME} compiling file: $(BROWN)[$<]...${DEF_COLOR}"
	@$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c -o $@ $< 

subsystems:
# Do Make only if there are changes in the libraries:
	@if [ -f $(MLX_LIB) ]; then \
	if find $(MLX_DIR) -name "*.c" -newer $(MLX_LIB) | grep -q .; then \
	${MAKE} -C $(MLX_DIR) all; \
	fi; \
	else \
	${MAKE} -C $(MLX_DIR) all; \
	fi

	@if [ -f $(LIBFT_LIB) ]; then \
	if find $(LIBFT_DIR) -name "*.c" -newer $(LIBFT_LIB) | grep -q .; then \
	${MAKE} -C $(LIBFT_DIR) all; \
	fi; \
	else \
	${MAKE} -C $(LIBFT_DIR) all; \
	fi

	@if [ -f $(PRINTF_LIB) ]; then \
	if find $(PRINTF_DIR) -name "*.c" -newer $(PRINTF_LIB) | grep -q .; then \
	${MAKE} -C $(PRINTF_DIR) all; \
	fi; \
	else \
	${MAKE} -C $(PRINTF_DIR) all; \
	fi
	
	@if [ -f $(GET_NEXT_LINE_LIB) ]; then \
	if find $(GET_NEXT_LINE_DIR) -name "*.c" -newer $(GET_NEXT_LINE_LIB) | grep -q .; then \
	${MAKE} -C $(GET_NEXT_LINE_DIR) all; \
	fi; \
	else \
	${MAKE} -C $(GET_NEXT_LINE_DIR) all; \
	fi


${NAME}:	${OBJS}
	@$(CC) ${CFLAGS} $(INCLUDE_FLAGS) $(MLX_FLAGS) ${OBJS} ${LIBS} $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)✓ Created ${NAME}$(DEF_COLOR)\n"

install_mlx:
	@echo "Copying libmlx.a to /usr/lib/X11"
	@sudo cp $(MLX_DIR)libmlx.a /usr/lib/X11
	@echo "Copying libmlx_Linux.a to /usr/lib/X11"
	@sudo cp $(MLX_DIR)libmlx_Linux.a /usr/lib/X11
	@echo "Copying mlx.h to /usr/include/X11"
	@sudo cp $(MLX_DIR)mlx.h /usr/include/X11/

bonus:	subsystems ${BONUS_OBJECTS}
	@$(CC) ${CFLAGS} $(INCLUDE_FLAGS) $(MLX_FLAGS) ${BONUS_OBJECTS} ${LIBS} $(MLX_FLAGS) -o $(BONUS_NAME)
	@echo "$(GREEN)✓ Created ${BONUS_NAME}$(DEF_COLOR)\n"

clean:
	@${RM} ${OBJS} ${BONUS_OBJECTS}
	@echo "\n$(GREEN)✓ All objects from ${PROY_NAME} cleaned successfully$(DEF_COLOR)"
	@echo "$(GREEN)Note: run $(YELLOW)make cleanlibs$(GREEN) if also want to clean all libraries $(DEF_COLOR)\n"

cleanlibs: 
	@${MAKE} -C $(MLX_DIR) clean
	@${MAKE} -C $(LIBFT_DIR) clean
	@${MAKE} -C $(PRINTF_DIR) clean
	@${MAKE} -C $(GET_NEXT_LINE_DIR) clean


fclean: clean
	@${RM} ${NAME} ${BONUS_NAME}
	@echo "\n$(GREEN)✓ All executable from ${PROY_NAME} cleaned successfully $(DEF_COLOR)"
	@echo "$(GREEN)Note: run $(YELLOW)make fcleanlibs$(GREEN) if also want to fclean all libraries $(DEF_COLOR)\n"

fcleanlibs: 
	@${MAKE} -C $(MLX_DIR) clean
	@${MAKE} -C $(LIBFT_DIR) fclean
	@${MAKE} -C $(PRINTF_DIR) fclean
	@${MAKE} -C $(GET_NEXT_LINE_DIR) fclean

re: fclean all

.PHONY: all bonus install_mlx clean fcleanlibs fclean re