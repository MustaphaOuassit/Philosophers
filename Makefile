# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mouassit <mouassit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 09:44:25 by mouassit          #+#    #+#              #
#    Updated: 2022/02/19 19:35:57 by mouassit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers

LIB = philosophers.h \

SRC = main.c\
	  info_philo.c\
	  create_threads.c\
	  libft.c\

all : $(NAME)

$(NAME): $(SRC)
	@gcc -Wall -Wextra -Werror -fsanitize=address -g $(SRC) -o $(NAME)

clean:
	@rm -rf $(NAME)

fclean:
	@rm -rf $(NAME)

re: fclean all