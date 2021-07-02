# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbjaghou <nbjaghou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/01 15:03:24 by nbjaghou          #+#    #+#              #
#    Updated: 2021/07/02 14:33:04 by nbjaghou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS = 	philo_one.c				\
		util_funcs.c			\
		ft_actions.c			\
		ft_checker.c			\
		ft_initialise.c			\
		ft_philosophers.c		\
		utils/ft_atoi.c			\
		utils/ft_putchar_fd.c	\
		utils/ft_putstr_fd.c	\
		utils/ft_strdup.c		\
		utils/ft_strjoin.c		\
		utils/ft_strlen.c		\
		utils/ft_isdigit.c		\

FLAGS = -Werror -Wextra -Wall

$(NAME) :
	gcc $(SRCS) -o $(NAME) -lpthread $(FLAGS)
	
all: $(NAME)

clean:

fclean:
	rm -rf $(NAME)

re: fclean all

