# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 16:13:08 by jarregui          #+#    #+#              #
#    Updated: 2024/05/21 09:56:14 by jarregui         ###   ########.fr        #
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

SRCS		=	main.c \
			files/images.c \
			files/map_arg_check.c \
			files/maps_check.c \
			files/maps_print.c \
			files/maps_set.c \
			files/maps_stuff.c \
			files/stuff.c \
			
SRCS_BONUS	=	bonus/stuff_bonus.c

# VARIABLES DECLARATION:
NAME			=	so_long
BONUS_NAME		=	so_long_bonus
CC				=	gcc
RM				=	rm -f
AR				=	ar rc
RN				=	ranlib
# CFLAGS			=	-g -Wall -Wextra -Werror -fsanitize=address
CFLAGS			=	-Wall -Wextra -Werror

# MinilibX directory, macro and flags for LInux or Mac
ifeq ($(shell uname), Linux)
	MLX_DIR = libs/minilib/minilibx_linux
	CFLAGS +=  -Wno-unused-result
else
	MLX_DIR = libs/minilib/minilibx_opengl
endif

MLX_FLAGS		=	-L$(MLX_DIR) -lmlx

ifeq ($(shell uname), Linux)
	MLX_FLAGS += -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
else
	MLX_FLAGS += -framework OpenGL -framework AppKit
endif

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
all: subsystems	$(NAME)

%.o : %.c
	@echo "$(BROWN)Compiling [$<]...${DEF_COLOR}"
	@$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c -o $@ $< 

subsystems:
	@echo "\n${ORANGE}********************** $(DEF_COLOR)"
	@echo "${ORANGE}Minilibx compilation: $(DEF_COLOR)"
	@${MAKE} -C $(MLX_DIR) all
	@echo "$(GREEN)✓ Created ${MLX_LIB} $(DEF_COLOR)"
	
	@echo "\n${ORANGE}********************** $(DEF_COLOR)"
	@echo "${ORANGE}Libft compilation: $(DEF_COLOR)"
	@${MAKE} -C $(LIBFT_DIR) all
	@echo "$(GREEN)✓ Created ${LIBFT_LIB} $(DEF_COLOR)"

	@echo "\n${ORANGE}********************** $(DEF_COLOR)"
	@echo "${ORANGE}printf compilation: $(DEF_COLOR)"
	@${MAKE} -C $(PRINTF_DIR) all
	@echo "$(GREEN)✓ Created ${PRINTF_LIB} $(DEF_COLOR)"

	@echo "\n${ORANGE}********************** $(DEF_COLOR)"
	@echo "${ORANGE}get_next_line compilation: $(DEF_COLOR)"
	@${MAKE} -C $(GET_NEXT_LINE_DIR) all
	@echo "$(GREEN)✓ Created ${GET_NEXT_LINE_LIB} $(DEF_COLOR)"

	@echo "\n${ORANGE}********************** $(DEF_COLOR)"
	@echo "${ORANGE}So_long compilation: $(DEF_COLOR)"

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

bonus: ${BONUS_OBJECTS}
	@echo "\n${ORANGE}Minilibx compilation $(DEF_COLOR)\n"
	@touch $@
	@make -C ${MLX_DIR} all
	@cp ${MLX_DIR}/libmlx.a .
	@$(CC) $(SRCS_BONUS) $(MLX_FLAGS) -o $(BONUS_NAME)
	@echo "$(GREEN)✓ Created ${BONUS_NAME}$(DEF_COLOR)\n"

clean:
	@${RM} ${OBJS} ${BONUS_OBJECTS}
	@${MAKE} -C $(MLX_DIR) clean
	@${MAKE} -C $(LIBFT_DIR) clean
	@${MAKE} -C $(PRINTF_DIR) clean
	@${MAKE} -C $(GET_NEXT_LINE_DIR) clean
	@echo "\n$(GREEN)✓ All objects cleaned successfully$(DEF_COLOR)\n"

fcleanlibs: 
	@${MAKE} -C $(MLX_DIR) fclean
	@${MAKE} -C $(LIBFT_DIR) fclean
	@${MAKE} -C $(PRINTF_DIR) fclean
	@${MAKE} -C $(GET_NEXT_LINE_DIR) fclean

fclean: clean
	@${RM} ${NAME} ${BONUS_NAME}
	@echo "\n$(GREEN)✓ All executable cleaned successfully$(DEF_COLOR)\n"

re: fclean all

.PHONY: all bonus install_mlx clean fcleanlibs fclean re