# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgumede <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/13 13:40:49 by lgumede           #+#    #+#              #
#    Updated: 2019/08/13 14:11:06 by lgumede          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

FLAGS = -Wall -Werror -Wextra

SRC = *.c

OBJ = $(SRC:%.c=%.o)

DIR = ../libft

all: $(NAME)

$(NAME):
	make all -C $(DIR)
	$(CC) $(FLAGS) -o $(NAME) $(SRC) ../libft/libft.a

clean:
	make clean -C $(DIR) 
	rm -rf $(OBJ)
	
fclean: clean
	make fclean -C $(DIR)
	rm -rf $(NAME)

re: fclean all
