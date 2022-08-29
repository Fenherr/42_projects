# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 08:41:56 by ngrenoux          #+#    #+#              #
#    Updated: 2022/08/22 09:00:27 by ngrenoux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIR_IS = 		ft_is/
DIR_LST = 		ft_lst/
DIR_MEM = 		ft_mem/
DIR_OTHER = 	ft_other/
DIR_PUT = 		ft_put/
DIR_STR = 		ft_str/
DIR_TO = 		ft_to/
DIR_GNL = 		get_next_line/
DIR_PRINTF = 	printf/

SRCS_IS = 		ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isblank.c \
				ft_iscntrl.c \
				ft_isdigit.c \
				ft_isgraph.c \
				ft_islower.c \
				ft_isprint.c \
				ft_isspace.c \
				ft_isupper.c \
				ft_isxdigit.c
SRCS_LST =		ft_lstadd_back.c \
				ft_lstadd_front.c \
				ft_lstclear.c \
				ft_lstdelone.c \
				ft_lstiter.c \
				ft_lstlast.c \
				ft_lstmap.c \
				ft_lstnew.c \
				ft_lstsize.c
SRCS_MEM =		ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_memset.c
SRCS_OTHER =	ft_atoi.c \
				ft_bzero.c \
				ft_calloc.c \
				ft_itoa.c \
				ft_split.c	\
				ft_atoi_base.c
SRCS_PUT = 		ft_putchar.c \
				ft_putchar_fd.c \
				ft_putendl_fd.c \
				ft_putnbr.c \
				ft_putnbr_fd.c \
				ft_putstr.c \
				ft_putstr_fd.c \
				ft_putunbr.c	\
				ft_putnbr_base.c
SRCS_STR =		ft_strchr.c \
				ft_strcpy.c \
				ft_strdup.c \
				ft_striteri.c \
				ft_strjoin.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_strmapi.c \
				ft_strncmp.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_strtrim.c \
				ft_substr.c  \
				ft_strcmp.c
SRCS_TO =		ft_tolower.c \
				ft_toupper.c
SRCS_GNL =		get_next_line.c
SRCS_PRINTF =	ft_len_hexa.c \
				ft_printchar.c \
				ft_printf.c \
				ft_printf_utils.c \
				ft_printhexa.c \
				ft_printptr.c \
				ft_printunsigned.c

OBJS_IS = $(addprefix $(DIR_IS), $(SRCS_IS:.c=.o))
OBJS_LST = $(addprefix $(DIR_LST), $(SRCS_LST:.c=.o))
OBJS_MEM = $(addprefix $(DIR_MEM), $(SRCS_MEM:.c=.o))
OBJS_OTHER = $(addprefix $(DIR_OTHER), $(SRCS_OTHER:.c=.o))
OBJS_PUT = $(addprefix $(DIR_PUT), $(SRCS_PUT:.c=.o))
OBJS_STR = $(addprefix $(DIR_STR), $(SRCS_STR:.c=.o))
OBJS_TO = $(addprefix $(DIR_TO), $(SRCS_TO:.c=.o))
OBJS_GNL = $(addprefix $(DIR_GNL), $(SRCS_GNL:.c=.o))
OBJS_PRINTF = $(addprefix $(DIR_PRINTF), $(SRCS_PRINTF:.c=.o))
OBJS = $(OBJS_IS) $(OBJS_LST) $(OBJS_MEM) $(OBJS_OTHER) \
	   $(OBJS_PUT) $(OBJS_STR) $(OBJS_TO) $(OBJS_GNL) $(OBJS_PRINTF)

NAME = libft.a

CC = ar rcs

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
	@gcc $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
	@$(CC) -o $(NAME) $(OBJS)
	@echo "\033[32m\n----Travail terminé !----\033[0m"

all:	$(NAME)

clean:
	@$(RM) $(OBJS)

fclean:	clean
	@$(RM) $(NAME)
	@echo "\033[32mTout est... clean...\033[0m"

re:	fclean all

.PHONY:	all clean fclean re
