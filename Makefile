# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mouassit <mouassit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 09:44:25 by mouassit          #+#    #+#              #
#    Updated: 2022/02/24 06:40:31 by mouassit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers

LIB = philosophers.h \

SRC = main.c\
	  info_philo.c\
	  info_fork.c\
	  create_threads.c\
	  utils.c\
	  libft.c\

all : $(NAME)

$(NAME): $(SRC)
	@gcc -Wall -Wextra -Werror -fsanitize=address -g $(SRC) -o $(NAME)

clean:
	@rm -rf $(NAME)

fclean:
	@rm -rf $(NAME)

re: fclean all