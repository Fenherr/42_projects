# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngrenoux <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 13:48:12 by ngrenoux          #+#    #+#              #
#    Updated: 2022/04/01 12:57:22 by ngrenoux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
		ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
		ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
		ft_atoi.c ft_calloc.c ft_strdup.c

ADD = ft_strcpy

OBJS = $(SRCS:.c=.o)

OBJS_ADD = $(ADD:.c=.o)

NAME = libft.a

CC = ar rcs

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
	gcc $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(OBJS)

all:	$(NAME)

clean:
	$(RM) $(OBJS) $(OBJS_ADD)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

add:	$(OBJS) $(OBJS_ADD)
	$(CC) $(NAME) $(OBJS) $(OBJS_ADD)

.PHONY:	all clean fclean re add
