# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alegent <alegent@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/13 12:17:39 by alegent           #+#    #+#              #
#    Updated: 2016/09/19 16:35:35 by alegent          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= wolf3d

SRC_PATH= sources/
SRC_NAME= main.c \
		  destroy/destroy_sdl.c \
		  draw/draw_floor.c \
		  draw/draw_wall.c \
		  event/check_move.c \
		  event/key_hook.c \
		  event/wait_event.c \
		  init/init_cam.c \
		  init/init_dda.c \
		  init/init_game.c \
		  init/init_ray.c \
		  init/init_sdl.c \
		  init/init_window.c \
		  level/convert_file.c \
		  level/get_map.c \
		  level/level.c \
		  level/read_file.c \
		  logic/dda.c \
		  logic/game_loop.c \
		  logic/raycasting.c \
		  logic/move/move_down.c \
		  logic/move/move_up.c \
		  logic/rotate/rotate_left.c \
		  logic/rotate/rotate_right.c \
		  tools/get_pixel.c

SRC= $(addprefix $(SRC_PATH), $(SRC_NAME))

OBJ_PATH= obj/
OBJ_NAME= $(SRC_NAME:.c=.o)
OBJ= $(addprefix $(OBJ_PATH), $(OBJ_NAME))

CC= clang -Wall -Wextra -Werror

INC_LIB= libft/
INC_PATH= includes/
INC= -I $(INC_LIB) -I $(INC_PATH)

LIB= libft/libft.a
FRAMEWORK= -framework SDL2

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(INC_LIB)
	@$(CC) $(LIB) $(INC) $(FRAMEWORK) -o $(NAME) $(OBJ)
	@echo "Your program is ready to go !"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)/{destroy,draw,event,init,level,logic/{move,rotate},tools}
	$(CC) $(INC) -o $@ -c $<
 
clean:
	@make -C $(INC_LIB) clean
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_PATH)
	@echo "Object files has been deleted"

fclean: clean
	@make -C $(INC_LIB) fclean
	@rm -rf $(SUBNAME)
	@rm -rf $(NAME)
	@echo "Librairy has been deleted"

re: fclean all

.PHONY: clean fclean re norme

