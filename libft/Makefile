# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngrenoux <ngrenoux@student.42angouleme.fr> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 08:41:56 by ngrenoux          #+#    #+#              #
#    Updated: 2022/04/07 16:50:10 by ngrenoux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
		ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
		ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
		ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
		ft_strtrim.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
		ft_putnbr_fd.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_split.c

SRCS_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			 ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstadd_back.c \
			 ft_lstmap.c

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

NAME = libft.a

CC = ar rcs

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

LIBSHARE = libft.so

.c.o:
	gcc $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(OBJS)

so:
	gcc -c -fPIC $(CFLAGS) $(SRCS) $(SRCS_BONUS)
	gcc -nostartfiles -shared -o $(LIBSHARE) $(OBJS) $(OBJS_BONUS)

bonus:	$(OBJS_BONUS)
	$(CC) $(NAME) $(OBJS_BONUS)

all:	$(NAME)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re bonus
