# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngrenoux <ngrenoux@student.42angoulem      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/22 08:44:27 by ngrenoux          #+#    #+#              #
#    Updated: 2022/05/27 14:09:58 by ngrenoux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#=================================COMPILATION==================================#
CC		= gcc
FLAGS		= -Wall -Wextra -Werror

#==================================EXECUTABLE==================================#
NAME		= push_swap

#===================================INCLUDES===================================#
LIBFT		= libft

#=================================SOURCE FILES=================================#
SRCS		= main.c 		\
		  init.c		\
		  add.c 		\
		  swap.c		\
		  rotate.c		\
		  reverse_rotate	\
		  print_stack.c 	\

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

$(NAME):
	@echo "$(BLUE)Compilation de la librairie...$(NOC)"
	@make -sC $(LIBFT)
	@echo "$(BLUE)Copie de la librairie...$(NOC)"
	@cp $(LIBFT)/libft.a ./libft.a
	@echo "$(GREEN)Copie effectuée.$(NOC)"
	@echo "$(BLUE)Création des objets...$(NOC)"
	@$(CC) $(FLAGS) -c $(SRCS)
	@echo "$(GREEN)Objets créés.$(NOC)"
	@echo "$(BLUE)Création de l'executable$(NOC)"
	@$(CC) $(OBJS) libft.a -o $(NAME)
	@echo "$(GREEN)Exécutable créé.$(NOC)"

clean:
	@make -sC $(LIBFT) clean
	@rm -f $(OBJS)

fclean:	clean
	@make -sC $(LIBFT) fclean
	@rm -f $(NAME) libft.a

re:	fclean all

.PHONY: all clean fclean re
