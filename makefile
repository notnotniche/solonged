NAME =		so_long

PARSING_DIR = parsing/

GNL_DIR = gnl/

GAME_DIR = game/

UTILS_DIR = utils/

RECURSIVE_DIR = recursive/

MAIN = 		maingame.c

SRCS =		${GNL_DIR}get_next_line.c		\
			${GNL_DIR}get_next_line_utils.c \
			${PARSING_DIR}valid_map.c\
			${PARSING_DIR}world_of_wall.c\
			${PARSING_DIR}coin_start_end.c\
			${PARSING_DIR}init.c\
			${UTILS_DIR}utils.c\
			${GAME_DIR}game_utils.c \
			${GAME_DIR}game_init.c \
			${GAME_DIR}game_player_move.c\
			${GAME_DIR}game_positions.c\
			${GAME_DIR}ft_inputs.c\
			${RECURSIVE_DIR}path.c\
			${RECURSIVE_DIR}recursion.c

			

			

MAIN_M =	${MAIN:.c=.o}
OBJS =		${SRCS:.c=.o}

DEFAULT			=	\033[1;0m
RED				=	\033[1;31m
GREEN			=	\033[1;32m

CC =		clang

RM =		rm -f

CFLAGS =	-Wall -Werror -Wextra -fstandalone-debug -g3 -I.

MLX =		./mlx

MLX_LIB = 	./mlx/libmlx_Linux.a

all:		${NAME}

.c.o:
		${CC} ${CFLAGS} -I${MLX} -c $< -o ${<:.c=.o}

$(MLX_LIB):
		make -C ${MLX} -j

$(NAME):	${MAIN_M} ${OBJS} $(MLX_LIB)
		${CC} ${CFLAGS} ${MAIN_M} ${OBJS} -o ${NAME} ${MLX_LIB}\
		-L -lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
		@echo "$(GREEN)##### so_long est compilé ! #####$(DEFAULT)"

clean:
		${RM} ${OBJS}
		${RM} ${MAIN_M}
		${RM} ${OBJS_B}
		make clean -C ${MLX}

fclean:		clean
		${RM} ${NAME}
		${RM} ${NAME_B}
		${RM} ${NAME} ${MLX_LIB}
		@echo "\n${RED}#### Tout est supprimé ! ####${DEFAULT}"

re:		fclean
		$(MAKE) all -j

.PHONY:		all clean fclean re