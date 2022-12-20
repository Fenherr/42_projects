# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 14:20:53 by ngrenoux          #+#    #+#              #
#    Updated: 2022/12/20 10:22:55 by ngrenoux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS = --no-print-directory

#=================================COMPILATION==================================#
CC			= clang
FLAGS		= -Wall -Wextra -Werror -Iincludes -g3

#==================================EXECUTABLE==================================#
NAME		= cub3D

#===================================INCLUDES===================================#
LIBFT		= libft

#=================================SOURCE FILES=================================#
SRCS		= srcs/main.c \
			  srcs/parsing/parsing.c \
			  srcs/parsing/parsing_utils.c \
			  srcs/parsing/command.c \
			  srcs/parsing/command_utils.c \
			  srcs/parsing/variable.c \
			  srcs/parsing/variable_utils.c \
			  srcs/parsing/variable_utils2.c \
			  srcs/parsing/env.c \
			  srcs/parsing/redirection.c \
			  srcs/parsing/redirection_utils.c \
			  srcs/parsing/redirection_utils2.c \
			  srcs/parsing/here_doc.c \
			  srcs/parsing/here_doc_utils.c \
			  srcs/parsing/quote.c \
			  srcs/signal/signal.c \
			  srcs/execution/execution.c \
			  srcs/execution/execution_utils.c \
			  srcs/execution/execution_utils2.c \
			  srcs/execution/builtins.c \
			  srcs/execution/exit.c \
			  srcs/execution/builtins_utils.c \
			  srcs/execution/export.c \
			  srcs/execution/export_utils.c \
			  srcs/execution/echo.c \
			  srcs/utils/init.c \
			  srcs/utils/error.c \
			  srcs/utils/error_utils.c \


#====================================OBJECTS===================================#
OBJS		= $(SRCS:.c=.o)

#====================================COLORS====================================#
NOC			= \e[0m
BOLD		= \e[1m
UNDERLINE	= \e[4m
BLACK		= \e[1;30m
RED			= \e[1m\e[38;5;196m
GREEN		= \e[1m\e[38;5;76m
YELLOW		= \e[1m\e[38;5;220m
BLUE		= \e[1m\e[38;5;33m
VIOLET		= \e[1;35m
CYAN		= \e[1;36m
WHITE		= \e[1;37m

#==============================PROGRESS BAR UTILS==============================#
PERCENT = 0
NB_COMPIL = 0
TOTAL_COMPIL = $(words $(OBJS))
PROGRESS_BAR_DETAIL = 4

#=====================================RULES====================================#
all: $(NAME)

.c.o:
	$(if $(filter $(NB_COMPIL),0), @echo "$(BLUE)Compilation de minishell...$(NOC)")
	$(if $(filter $(NB_COMPIL),0), @echo "$(YELLOW)$(NB_COMPIL) 0%$(NOC)")
	$(if $(filter $(NB_COMPIL),0), @make create_progressbar)
	$(eval NB_COMPIL=$(shell echo $$(($(NB_COMPIL)+1))))
	$(eval PERCENT=$(shell echo $$(($(NB_COMPIL) * 100 / $(TOTAL_COMPIL)))))
	@$(CC) $(FLAGS) -c $< -o $@
	@./.progressbar $(PERCENT)

$(NAME): $(OBJS)
	@./.progressbar 100
	@rm .progressbar
	@echo "$(BLUE)Compilation de la libft...$(NOC)"
	@make -sC $(LIBFT)
	@cp $(LIBFT)/libft.a ./libft.a
	@echo "$(BLUE)Création de l'executable...$(NOC)"
	@$(CC) -o $(NAME) $(OBJS) libft.a
	@echo "$(GREEN)Tout est prêt !$(NOC)"

clean:
	@echo "$(RED)Suppression des objets$(NOC)"
	@make -sC $(LIBFT) clean
	@rm -f $(OBJS)

fclean:	clean
	@echo "$(RED)Suppression des binaires$(NOC)"
	@make -sC $(LIBFT) fclean
	@rm -f $(NAME) libft.a

re:
	@clear
	@make fclean
	@make all

create_progressbar:
	@echo '#include <stdio.h>' > .progressbar.c
	@echo '#include <stdlib.h>\n' >> .progressbar.c
	@echo 'void	print_color(int color)' >> .progressbar.c
	@echo '{' >> .progressbar.c
	@echo '	if (color == -1)' >> .progressbar.c
	@echo '		printf("\\e[0m ");' >> .progressbar.c
	@echo '	else if (color == 0)' >> .progressbar.c
	@echo '		printf("\\e[48;5;154m ");' >> .progressbar.c
	@echo '	else if (color == 1 || color == 9)' >> .progressbar.c
	@echo '		printf("\\e[48;5;155m ");' >> .progressbar.c
	@echo '	else if (color == 2 || color == 8)' >> .progressbar.c
	@echo '		printf("\\e[48;5;156m ");' >> .progressbar.c
	@echo '	else if (color == 3 || color == 7)' >> .progressbar.c
	@echo '		printf("\\e[48;5;157m ");' >> .progressbar.c
	@echo '	else if (color == 4 || color == 6)' >> .progressbar.c
	@echo '		printf("\\e[48;5;158m ");' >> .progressbar.c
	@echo '	else if (color == 5)' >> .progressbar.c
	@echo '		printf("\\e[48;5;159m ");' >> .progressbar.c
	@echo '}\n' >> .progressbar.c
	@echo 'int	main(int ac, char **av)' >> .progressbar.c
	@echo '{' >> .progressbar.c
	@echo '	int	nb = atoi(av[1]);\n' >> .progressbar.c
	@echo '	printf("\\e[1A\\e[K");' >> .progressbar.c
	@echo '	for (int i = 0; i <= 100; i += $(PROGRESS_BAR_DETAIL))' >> .progressbar.c
	@echo '	{' >> .progressbar.c
	@echo '		if (i > nb)' >> .progressbar.c
	@echo '			printf("\\e[48;5;196m ");' >> .progressbar.c
	@echo '		else' >> .progressbar.c
	@echo '			print_color((nb - (i / $(PROGRESS_BAR_DETAIL))) % 10);' >> .progressbar.c
	@echo '	}' >> .progressbar.c
	@echo '	print_color(-1);' >> .progressbar.c
	@echo '	if (nb == 100)' >> .progressbar.c
	@echo '		printf("\e[1m\e[38;5;76m100%%\\e[0m\\n");' >> .progressbar.c
	@echo '	else' >> .progressbar.c
	@echo '		printf("\e[1m\e[38;5;220m%i%%\\e[0m\\n", nb);' >> .progressbar.c
	@echo '}' >> .progressbar.c
	@gcc .progressbar.c -o .progressbar
	@rm .progressbar.c

.PHONY: all clean fclean re create_progressbar
