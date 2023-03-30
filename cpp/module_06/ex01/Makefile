# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 13:46:58 by ngrenoux          #+#    #+#              #
#    Updated: 2023/03/30 11:55:30 by ngrenoux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#=================================COMPILATION==================================#
CC			= c++
FLAGS		= -Wall -Wextra -Werror -std=c++98

#==================================EXECUTABLE==================================#
NAME		= serializer

#=================================SOURCE FILES=================================#
SRCS		= main.cpp \
			  Serializer.cpp

#====================================OBJECTS===================================#
OBJS		= $(SRCS:.cpp=.o)

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

.cpp.o:
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME):	$(OBJS)
	@echo "$(BLUE)Création de l'executable$(NOC)"
	@$(CC) -o $(NAME) $(OBJS)
	@echo "$(GREEN)Exécutable créé.$(NOC)"

clean:
	@rm -f $(OBJS)
	@echo "$(RED)Binaires supprimé.$(NOC)"

fclean:	clean
	@rm -f $(NAME)
	@echo "$(RED)Exécutable supprimé.$(NOC)"

re:	fclean all

.PHONY: all clean fclean re
