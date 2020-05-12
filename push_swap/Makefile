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

NAME_1 = push_swap

NAME_2 = checker

CC = gcc

FLAGS = -Wall -Werror -Wextra

SRC_1 = main.c\
		algos_1.c\
		algos_2.c\
		ass_functions.c\
		push_swap.c\
		sort2.c\
		swap_a.c\
		swap_b.c\

SRC_2 = $(NAME_2).c\
		algos_1.c\
		algos_2.c\
		checker_opsA.c\
		checker_opsB.c\
		ass_functions.c\
		push_swap.c\
		swap_a.c\
		swap_b.c\

OBJ_1 = $(SRC_1:%.c=%.o)

OBJ_2 = $(SRC_2:%.c=%.o)

DIR = ../libft

all: $(NAME_1) $(NAME_2)

$(NAME_1):
	make all -C $(DIR)
	$(CC) $(FLAGS) -o $(NAME_1) $(SRC_1) ../libft/libft.a

$(NAME_2):
	make all -C $(DIR)
	$(CC) $(FLAGS) -o $(NAME_2) $(SRC_2) ../libft/libft.a

clean:
	make clean -C $(DIR) 
	rm -rf $(OBJ_1) $(OBJ_2)
	
fclean: clean
	make fclean -C $(DIR)
	rm -rf $(NAME_1) $(NAME_2)

re: fclean all
