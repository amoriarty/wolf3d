CMAKE_MINIMUM_REQUIRED(VERSION 3.3)
PROJECT(wolf3d)

#COMPILERS CONFIGURATION
SET(CMAKE_C_COMPILER "/usr/bin/clang")
SET(CMAKE_C_FLAGS "-Wall -Wextra -Werror -F /Library/Frameworks")

#EXECUTABLE FILES
SET(EXEC_FILE sources/main.c
		sources/level/level.c
		sources/draw/draw_vertical.c
		sources/draw/draw_background.c
		sources/init/init_cam.c
		sources/draw/draw_wall.c
		sources/logic/dda.c
		sources/init/init_ray.c
		sources/init/init_dda.c
		sources/logic/raycasting.c
		sources/event/key_hook.c
		sources/logic/move/move_up.c
		sources/logic/move/move_down.c
		sources/logic/rotate/rotate_left.c
		sources/logic/rotate/rotate_right.c
		sources/logic/game_loop.c
		sources/level/get_map.c
		sources/level/read_file.c
		sources/level/convert_file.c
		sources/tools/get_pixel.c
		sources/init/init_sdl.c
		sources/destroy/destroy_sdl.c sources/init/init_window.c sources/event/wait_event.c sources/init/init_game.c sources/event/window_event.c sources/draw/draw_floor.c)

#INCLUDES DIRECTORIES
INCLUDE_DIRECTORIES(includes)
INCLUDE_DIRECTORIES(libft)

#LIBFT MAKEFILE CALL
ADD_CUSTOM_COMMAND(
		OUTPUT ${PROJECT_SOURCE_DIR}/libft/libft.a
		COMMAND make
		WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/libft
)
ADD_CUSTOM_TARGET(
		libft
		DEPENDS ${PROJECT_SOURCE_DIR}/libft/libft.a
)

#EXECUTABLES
ADD_EXECUTABLE(wolf3d ${EXEC_FILE})

#DEPENDENCIES
ADD_DEPENDENCIES(wolf3d libft)

#LIBRARIES LINKING
TARGET_LINK_LIBRARIES(wolf3d ${PROJECT_SOURCE_DIR}/libft/libft.a)
TARGET_LINK_LIBRARIES(wolf3d "-framework SDL2")
TARGET_LINK_LIBRARIES(wolf3d "-framework SDL2_image")
