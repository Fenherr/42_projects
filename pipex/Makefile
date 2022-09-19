# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/02 11:04:32 by ngrenoux          #+#    #+#              #
#    Updated: 2022/09/19 09:28:38 by ngrenoux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#=================================COMPILATION==================================#
CC			= gcc
FLAGS		= -Wall -Wextra -Werror -Iincludes -g3

#==================================EXECUTABLE==================================#
NAME		= pipex
NAME_BONUS	= pipex_bonus

#===================================INCLUDES===================================#
LIBFT		= libft

#=================================SOURCE FILES=================================#
SRCS		= srcs/main.c \
			  srcs/utils/error.c \
			  srcs/utils/init.c	\
			  srcs/utils/free.c \
			  srcs/utils/files.c \
			  srcs/utils/close_fd.c \
			  srcs/env/env.c \
			  srcs/process/process.c \

#=====================================BONUS====================================#
BONUS		= bonus/srcs/main_bonus.c \
			  bonus/srcs/utils/error_bonus.c \
			  bonus/srcs/utils/init_bonus.c	\
			  bonus/srcs/utils/free_bonus.c \
			  bonus/srcs/utils/files_bonus.c \
			  bonus/srcs/utils/close_fd_bonus.c \
			  bonus/srcs/env/env_bonus.c \
			  bonus/srcs/process/process_bonus.c \

#====================================OBJECTS===================================#
OBJS		= $(SRCS:.c=.o)
OBJS_BONUS	= $(BONUS:.c=.o)

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
	
$(NAME_BONUS):	$(OBJS_BONUS)
	@make -sC $(LIBFT)
	@echo "$(BLUE)Compilation...$(NOC)"
	@cp $(LIBFT)/libft.a ./libft.a
	@echo "$(BLUE)Création de l'executable...$(NOC)"
	@$(CC) -o $(NAME_BONUS) $(OBJS_BONUS) libft.a
	@echo "$(GREEN)Tout est prêt !$(NOC)"

bonus:	$(NAME_BONUS)

clean:
	@make -sC $(LIBFT) clean
	@rm -f $(OBJS) $(OBJS_BONUS)

fclean:	clean
	@make -sC $(LIBFT) fclean
	@rm -f $(NAME) $(NAME_BONUS) libft.a

re:	fclean all
	@clear

.PHONY: all clean fclean re
