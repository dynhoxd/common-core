# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jabernar <jabernar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/03 14:52:40 by jabernar          #+#    #+#              #
#    Updated: 2026/11/03 15:01:53 by jabernar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
FLAGS = -c -Wall -Werror -Wextra
SRCS = *.c
OBJS = $(SRCS:%.c=%.o)

all: $(OBJS)
	ar crs $(NAME) $^

%.o: %.c
	$(CC) $(FLAGS) $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re