# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngrenoux <ngrenoux@student.42angoulem      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/22 08:44:27 by ngrenoux          #+#    #+#              #
#    Updated: 2022/04/22 13:21:42 by ngrenoux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_DIR = src/

SRCS = ft_printf.c \
	   ft_len_hexa.c \
	   ft_printchar.c \
	   ft_printf_utils.c \
	   ft_printhexa.c \
	   ft_printptr.c \
	   ft_printunsigned.c

CC = gcc

AR = ar -rcs

RM = rm -f

FLAGS = -c -Wall -Wextra -Werror

OBJS = $(addprefix $(SRC_DIR), $(SRCS:.c=.o))

all:	$(NAME)

$(NAME):	$(OBJS)
	make -C ./libft
	cp libft/libft.a $(NAME)
	$(AR) -o  $(NAME) $(OBJS)

clean:
	make clean -C ./libft
	$(RM) $(OBJS)

fclean:	clean
	make fclean -C ./libft
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
