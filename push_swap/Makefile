# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/22 08:44:27 by ngrenoux          #+#    #+#              #
#    Updated: 2022/09/01 10:05:05 by ngrenoux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#=================================COMPILATION==================================#
CC			= gcc
FLAGS		= -Wall -Wextra -Werror -Iincludes -g3

#==================================EXECUTABLE==================================#
NAME		= push_swap

#===================================INCLUDES===================================#
LIBFT		= libft

#=================================SOURCE FILES=================================#
SRCS		= srcs/main.c \
			  srcs/sort_algorithm/search_min.c \
			  srcs/sort_algorithm/sort.c \
			  srcs/sort_algorithm/sort3.c \
			  srcs/sort_algorithm/sort5.c \
			  srcs/sort_algorithm/sort_more.c \
			  srcs/sort_algorithm/tmp_tab.c \
			  srcs/sort_functions/error.c \
			  srcs/sort_functions/filling_stack.c \
			  srcs/sort_functions/free.c \
			  srcs/sort_functions/init.c \
			  srcs/sort_functions/is_sorted.c \
			  srcs/sort_functions/push.c \
			  srcs/sort_functions/reverse.c \
			  srcs/sort_functions/rotate.c \
			  srcs/sort_functions/swap.c
		  
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
	@echo "$(BLUE)Copie de la librairie...$(NOC)"
	@cp $(LIBFT)/libft.a ./libft.a
	@echo "$(GREEN)Copie effectuée.$(NOC)"
	@echo "$(BLUE)Création de l'executable$(NOC)"
	@$(CC) -o $(NAME) $(OBJS) libft.a
	@echo "$(GREEN)Exécutable créé.$(NOC)"

clean:
	@make -sC $(LIBFT) clean
	@rm -f $(OBJS)

fclean:	clean
	@make -sC $(LIBFT) fclean
	@rm -f $(NAME) libft.a

re:	fclean all

.PHONY: all clean fclean re
