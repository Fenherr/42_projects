# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/22 08:44:27 by ngrenoux          #+#    #+#              #
#    Updated: 2023/01/17 09:34:33 by ngrenoux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#=================================COMPILATION==================================#
CC			= clang
FLAGS		= -Wall -Wextra -Werror -Iincludes -Imlx_linux -g3

#==================================EXECUTABLE==================================#
NAME		= cub3D

#===================================INCLUDES===================================#
LIBFT		= libs/libft
MINILIBX	= libs/mlx_linux

#=================================SOURCE FILES=================================#
SRCS		= srcs/main.c \
			  srcs/utils/init.c \
			  srcs/utils/textures.c \
			  srcs/utils/error.c \
			  srcs/utils/free.c \
			  srcs/utils/utils.c \
			  srcs/utils/colors.c \
			  srcs/parsing/parsing.c \
			  srcs/parsing/parsing_utils.c \
			  srcs/parsing/check_map.c \
			  srcs/parsing/check_map_utils.c \
			  srcs/parsing/duplicate_map.c \
			  srcs/parsing/corner.c \
			  srcs/parsing/check_spec_wall.c \
			  srcs/window/window.c \
			  srcs/window/free_window.c \
			  srcs/window/init_player.c \
			  srcs/window/input.c \
			  srcs/window/put_image.c \
			  srcs/move/move.c \
			  srcs/move/look.c \
			  srcs/move/math.c \
			  srcs/move/math_2.c \
			  srcs/move/wall.c \
			  srcs/display/display.c \
			  srcs/display/raycast.c \
			  srcs/display/start_image.c \
			  srcs/display/texture.c \
			  srcs/display/init_add_dir.c \
			  srcs/display/dir.c \
			  srcs/display/special_wall.c \
			  srcs/display/double_wall.c \
			  srcs/display/3_wall.c \
			  srcs/display/4_wall.c \
			  srcs/minimap/minimap.c \

#====================================OBJECTS===================================#
OBJS		= $(SRCS:.c=.o)

#====================================COLORS====================================#
NOC			= \033[0m
BOLD		= \033[1m
UNDERLINE	= \033[4m
BLACK		= \033[1;30m
RED			= \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
BLUE		= \033[1;34m
VIOLET		= \033[1;35m
CYAN		= \033[1;36m
WHITE		= \033[1;37m

#=====================================RULES====================================#
all:	$(NAME)

.c.o:
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME):	$(OBJS)
	@echo "$(BLUE)Compilation de la librairie...$(NOC)"
	@make -sC $(LIBFT)
	@echo "$(BLUE)Compilation de la minilibx...$(NOC)"
	@make -sC $(MINILIBX)
	@echo "$(BLUE)Copie de la librairie...$(NOC)"
	@cp $(LIBFT)/libft.a ./libft.a
	@echo "$(GREEN)Copie effectuée.$(NOC)"
	@echo "$(BLUE)Création de l'executable$(NOC)"
	@$(CC) $(OBJS) -Lmlx -lmlx -Llibs/mlx_linux -Imlx -lXext -lX11 -lm -lz -o $(NAME)  libft.a
	@echo "$(GREEN)Exécutable créé.$(NOC)"

clean:
	@echo "$(RED)Suppression des objets$(NOC)"
	@make -sC $(LIBFT) clean
	@make -sC $(MINILIBX) clean
	@rm -f $(OBJS)

fclean:	clean
	@echo "$(RED)Suppression des binaires$(NOC)"
	@make -sC $(LIBFT) fclean
	@rm -f $(NAME) libft.a

re:	fclean all

.PHONY: all clean fclean re
