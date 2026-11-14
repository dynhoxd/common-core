# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jabernar <jabernar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/13 18:05:15 by jabernar          #+#    #+#              #
#    Updated: 2026/11/13 18:09:02 by jabernar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

FLAGS = -c -Wall -Werror -Wextra

LIBFTFLAGS = -Llibft -lft -Ilibft 

SRCS = 
	
OBJS = $(SRCS:%.c=%.o)


all: $(NAME)

$(NAME): $(OBJS)
	ar crs $(NAME) $^

%.o: %.c
	$(CC) $(FLAGS) $(LIBFTFLAGS) $< -o $@

# bonus: $(OBJS) $(BONUS_OBJS)
# 	ar crs $(NAME) $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re