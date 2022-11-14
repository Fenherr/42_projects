# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/22 08:44:27 by ngrenoux          #+#    #+#              #
#    Updated: 2022/10/27 12:31:46 by ngrenoux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#=================================COMPILATION==================================#
CC			= gcc
FLAGS		= -Wall -Wextra -Werror -Iincludes -g3

#==================================EXECUTABLE==================================#
NAME		= philo

#=================================SOURCE FILES=================================#
SRCS		= srcs/main.c\
			  srcs/init.c \
			  srcs/error.c \
			  srcs/utils.c  \
			  srcs/parsing.c \
			  srcs/patterns.c \
			  srcs/utils_lib.c \
		  
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
	@echo "$(BLUE)Création de l'executable$(NOC)"
	@$(CC) -o $(NAME) $(OBJS) -lpthread
	@echo "$(GREEN)Exécutable créé.$(NOC)"

clean:
	@rm -f $(OBJS)

fclean:	clean
	@rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
