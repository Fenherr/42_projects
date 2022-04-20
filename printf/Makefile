# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngrenoux <ngrenoux@student.42angoulem      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/19 09:36:43 by ngrenoux          #+#    #+#              #
#    Updated: 2022/04/19 14:17:59 by ngrenoux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIR = srcs/

SRCS_FILE = ft_printf.c

SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRCS_FILE)))

OBJS_DIR = obj/

OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRCS_FILE)))

NAME = libftprintf.a

INCLUDE = includes

LIBFT = libft

CC = gcc

AR = ar rcs

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -I

OBJF = .cache_exists

$(NAME):	$(OBJS)
	make -C $(LIBFT)
	cp libft/libft.a
	mv libft.a $(NAME)
	$(AR) $(NAME) $(OBJS)

all:	$(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c | $(OBJF)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o

$(OBJF):
	mkdir -p $(OBJS_DIR)

clean:
	$(RM) -rd $(OBJS_DIR)
	make clean -C $(LIBFT)

fclean:	clean
	$(RM) -f $(NAME)
	$(RM) -f $(LIBFT)/libft.a

re:	fclean all

.PHONY:	all clean fclean re
