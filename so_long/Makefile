# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/22 08:44:27 by ngrenoux          #+#    #+#              #
#    Updated: 2022/10/04 15:32:24 by ngrenoux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#=================================COMPILATION==================================#
CC		= gcc
FLAGS		= -Wall -Wextra -Werror -Iincludes -Imlx_linux -lm -g3

#==================================EXECUTABLE==================================#
NAME		= so_long

#===================================INCLUDES===================================#
LIBFT		= libft
MINILIBX	= lib/mlx_linux

#=================================SOURCE FILES=================================#
SRCS		= srcs/main.c \
			  srcs/init.c \
			  srcs/check_map.c \
		  
#====================================OBJECTS===================================#
OBJS		= $(SRCS:.c=.o)

#====================================COLORS====================================#
NOC		= \033[0m
BOLD		= \033[1m
UNDERLINE	= \033[4m
BLACK		= \033[1;30m
RED		= \033[1;31m
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
	@$(CC) $(OBJS) -Lmlx -lmlx -Llib/mlx_linux -Imlx -lXext -lX11 -lm -lz -o $(NAME)  libft.a
	@echo "$(GREEN)Exécutable créé.$(NOC)"

clean:
	@make -sC $(LIBFT) clean
	@make -sC $(MINILIBX) clean
	@rm -f $(OBJS)

fclean:	clean
	@make -sC $(LIBFT) fclean
	@rm -f $(NAME) libft.a

re:	fclean all

.PHONY: all clean fclean re
