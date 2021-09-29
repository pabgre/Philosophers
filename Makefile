# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psan-gre <psan-gre@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/07 13:35:42 by psan-gre          #+#    #+#              #
#    Updated: 2021/09/29 14:36:46 by psan-gre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo

SRCS	= main.c ft_utils.c philo_constructor.c philo_private_methods.c\
			philo_private_methods_2.c philo_public_methods.c restaurant.c

OBJS	= $(SRCS:.c=.o)

CC		= gcc

INCLUDES = ./

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror -pthread -lpthread -g

all: $(NAME)

$(NAME):	$(SRCS)
	-$(CC) $(CFLAGS) -I$(INCLUDES) $(SRCS) -o $(NAME)

run: $(NAME) clean
	./$(NAME)

clean:
	-$(RM) $(OBJS)
fclean:		clean
	-$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
