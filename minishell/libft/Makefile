# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aderouba <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/26 12:24:51 by aderouba          #+#    #+#              #
#    Updated: 2022/12/10 12:55:59 by aderouba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS = --no-print-directory

#=================================COMPILATION==================================#
CC = clang
CFLAGS = -g -Wall -Wextra -Werror

#==================================EXECUTABLE==================================#
NAME = libft.a

#===================================INCLUDES===================================#
INCLUDE = -I .

#=================================SOURCE FILES=================================#
SRCS =	ft_atof.c \
		ft_atoi_base.c \
		ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_ftoa.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprime.c \
		ft_isprint.c \
		ft_itoa_base.c \
		ft_itoa.c \
		ft_lstadd_back.c \
		ft_lstadd_front.c \
		ft_lstclear.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstlast.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_lstr.c \
		ft_lstsize.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_pow.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_base_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_putunbr_base_fd.c \
		ft_putunbr_fd.c \
		ft_split.c \
		ft_sqrt.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin_free_1st_p.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_strsuperjoin_free_1st_p.c \
		ft_strsuperjoin.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_supersplit.c \
		ft_tolower.c \
		ft_toupper.c \
		gnl.c \
		printf_fd.c \
		printf.c

#====================================OBJECTS===================================#
OBJS = ${SRCS:.c=.o}

#====================================COLORS====================================#
NOC			= \033[0m
BOLD		= \033[1m
UNDERLINE	= \033[4m
BLACK		= \033[1;30m
RED			= \e[1m\e[38;5;196m
GREEN		= \e[1m\e[38;5;76m
YELLOW		= \e[1m\e[38;5;220m
BLUE		= \e[1m\e[38;5;33m
VIOLET		= \033[1;35m
CYAN		= \033[1;36m
WHITE		= \033[1;37m

NORMAL		= \e[25
BLINK		= \e[5m

#==============================PROGRESS BAR UTILS==============================#
PERCENT = 0
NB_COMPIL = 0
TOTAL_COMPIL = $(words $(OBJS))
PROGRESS_BAR_DETAIL = 4

#=====================================RULES====================================#
all : $(NAME)

%.o : %.c
	$(if $(filter $(NB_COMPIL),0), @echo "$(YELLOW)$(NB_COMPIL) 0%$(NOC)")
	$(if $(filter $(NB_COMPIL),0), @make create_progressbar)
	$(eval NB_COMPIL=$(shell echo $$(($(NB_COMPIL)+1))))
	$(eval PERCENT=$(shell echo $$(($(NB_COMPIL) * 100 / $(TOTAL_COMPIL)))))
	@./.progressbar $(PERCENT)
	@$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE)

$(NAME) : $(OBJS)
	@./.progressbar 100
	@rm .progressbar
	@ar cr $@ $^

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean $(NAME)

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
