# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/05 09:30:50 by nel-baz           #+#    #+#              #
#    Updated: 2022/11/05 09:33:40 by nel-baz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = 

OBJS = $(SRCS:.c=.o)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $<

all : $(NAME)

$(NAME):	$(OBJS)
		ar rc $(NAME) $(OBJS)

clean:	
		rm -rf $(OBJS)

fclean:	clean
		rm -rf $(NAME)
		
re : fclean all

.PHONY : all fclean clean re bonus