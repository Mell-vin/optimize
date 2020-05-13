# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgumede  <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/25 15:43:17 by lgumede           #+#    #+#              #
#    Updated: 2019/09/04 08:59:42 by lgumede          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_1 = checker

NAME_2 = push_swap

LIBRARY = ./libft/

FLAGS = -Wall -Werror -Wextra

SRCS_PATH = ./srcs/

OBJS_PATH = ./objs/

OBJS_DIR = objs

CHECKER_SRCS = $(NAME_1).c\
			   checkerComm.c\
			   checkerRR.c\
			   checkerR.c\
			   stackMacker.c\
			   frees.c\

PUSH_SWAP_SRCS = $(NAME_2).c\
				 pushComm.c\
				 pushRR.c\
				 pushR.c\
				 stackMacker.c\
				 Rotate.c\
				 frees.c\
				 bigStack.c\
				 minMoves.c\
				 smallStack.c\
				 sorter.c\

CHECKER_C = $(addprefix $(OBJS_PATH), $(CHECKER_SRCS))

PUSH_SWAP_C = $(addprefix $(OBJS_PATH), $(PUSH_SWAP_SRCS))

CHECKER_O = $(patsubst %.c, %.o, $(CHECKER_C))

PUSH_SWAP_O = $(patsubst %.c, %.o, $(PUSH_SWAP_C))

all: $(NAME_1) $(NAME_2)

$(OBJS_DIR):
	@mkdir $(OBJS_DIR)

libft:
	@$(MAKE) -C $(LIBRARY)/

$(NAME_1): $(OBJS_DIR) $(CHECKER_O) libft
	@gcc $(FLAGS) $(CHECKER_O) -L $(LIBRARY) -lft -o $(NAME_1)
	@echo "$(NAME_1) created"
	
$(NAME_2): $(OBJS_DIR) $(PUSH_SWAP_O) libft
	@gcc $(FLAGS) $(PUSH_SWAP_O) -L $(LIBRARY) -lft -o $(NAME_2) -g
	@echo "$(NAME_2) created"

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@gcc $(FLAGS) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBRARY)/ clean
	@rm -rf $(OBJS_DIR)
	@echo "objs deleted"

fclean:
	@$(MAKE) -C $(LIBRARY)/ fclean
	@rm -rf $(OBJS_DIR)
	@echo "objs deleted"
	@rm -f $(NAME_1) $(NAME_2)
	@echo "$(NAME_1) & $(NAME_2) deleted"

re: fclean all

.PHONY: all clean fclean libft re
