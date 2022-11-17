# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngrenoux <ngrenoux@student.42angoulem      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 14:20:53 by ngrenoux          #+#    #+#              #
#    Updated: 2022/11/17 14:21:01 by ngrenoux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#=================================COMPILATION==================================#
CC			= clang
FLAGS		= -Wall -Wextra -Werror -Iincludes -g3

#==================================EXECUTABLE==================================#
NAME		= minishell

#===================================INCLUDES===================================#
LIBFT		= libft

#=================================SOURCE FILES=================================#
SRCS		=

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
	@make -sC $(LIBFT)
	@echo "$(BLUE)Compilation...$(NOC)"
	@cp $(LIBFT)/libft.a ./libft.a
	@echo "$(BLUE)Création de l'executable...$(NOC)"
	@$(CC) -o $(NAME) $(OBJS) libft.a
	@echo "$(GREEN)Tout est prêt !$(NOC)"

clean:
	@make -sC $(LIBFT) clean
	@rm -f $(OBJS)

fclean:	clean
	@make -sC $(LIBFT) fclean
	@rm -f $(NAME) libft.a

re:	fclean all
	@clear

.PHONY: all clean fclean re
